#ifndef SRC_MODELS_FACADE_H_
#define SRC_MODELS_FACADE_H_

#include "file_reader.h"
#include "scene.h"
#include "affine_transformations.h"

namespace s21
{
    /*!
        \brief Returned класс для обработки результатов обработки .obj файла
    */
    class ModelOperationResult {
        public:
            ModelOperationResult() {
                errorMessage_ = "";
                is_success_ = true;
            };
            ~ModelOperationResult() noexcept = default;

            void SetErrorMessage(std::string err) noexcept { errorMessage_ = err; };
            void SetStatus(bool status) noexcept { is_success_ = status; };
            std::string GetErrorMessage() const noexcept { return errorMessage_; };
            bool IsSuccess() const noexcept { return is_success_; };

        private:
            std::string errorMessage_;
            bool is_success_;  
    };

    /*!
        \brief Основной класс модели для загрузки и обработки модели.
        \detais В данной системе классов используется структурный паттерн Фасад.
        ModelScene выступает в роли фасада для большого набора классов реализующих парсинг
        и хранения данных их .obj файлов. Клиентом выступает Controller.
    */
    class ModelScene {
    public:
        ModelScene() : file_reader_(nullptr), scene_(nullptr) {};
        ~ModelScene() noexcept {
            if (file_reader_ != nullptr) {
                delete file_reader_;
            }
        };

        /*!
            \brief Метод для загрузки и первичной обработки 3Д модели.
            \param path путь файла
            \exception При некорректном path вызывает исключение std::invalid_argument, при ошибки выделения памяти вызывает исключение std::bad_alloc.
        */
        ModelOperationResult LoadScene(std::string path) {
            ModelOperationResult status = ModelOperationResult();
            try {
                file_reader_ = new Reader();
                scene_ = file_reader_->ReadScene(path);
            } catch (std::invalid_argument* err) {
                status.SetErrorMessage(err->what());
                status.SetStatus(false);
            } catch (...) {
                status.SetErrorMessage("Another trouble/LoadScene/ModelScene");
                status.SetStatus(false);
            }
            return status;
        };
        
        /*!
            \brief Метод для перемщении модели относительно осей.
            \param x
            \param y
            \param z
            \details Изменяет напрямую координаты вершин, никак не взаимодействут с движком представления.
        */
        ModelOperationResult MoveScene(double x, double y, double z) {
            ModelOperationResult status = ModelOperationResult();
            try {
                BaseTransormation* transfer = new MoveTransformation();
                if (fabs(x) > 1e-7) {
                    transfer->TransformSceneX(x, *scene_);
                }
                if (fabs(y) > 1e-7) {
                    transfer->TransformSceneY(y, *scene_);
                }
                if (fabs(z) > 1e-7) {
                    transfer->TransformSceneZ(z, *scene_);
                }
                delete transfer;
            } catch (std::bad_alloc* err) {
                status.SetErrorMessage(err->what());
                status.SetStatus(false);
            }
            
            return status;
        };

        /*!
            \brief Метод для поворота модели относительно осей.
            \param x
            \param y
            \param z
            \details Изменяет напрямую координаты вершин, никак не взаимодействут с движком представления.
        */
        ModelOperationResult RotateScene(double x, double y, double z) {
            ModelOperationResult status = ModelOperationResult();
            try {
                BaseTransormation* transfer = new RotateTransformation();
                if (fabs(x) > 1e-7) {
                    transfer->TransformSceneX(x, *scene_);
                }
                if (fabs(y) > 1e-7) {
                    transfer->TransformSceneY(y, *scene_);
                }
                if (fabs(z) > 1e-7) {
                    transfer->TransformSceneZ(z, *scene_);
                }
                delete transfer;
            } catch (std::bad_alloc* err) {
                status.SetErrorMessage(err->what());
                status.SetStatus(false);
            }
            
            return status;
        };

        /*!
            \brief Метод для масштабирования модели относительно осей.
            \param x
            \param y
            \param z
            \details Изменяет напрямую координаты вершин, никак не взаимодействут с движком представления.
        */
        ModelOperationResult ScaleScene(double scale) {
            ModelOperationResult status = ModelOperationResult();
            try {
                BaseTransormation* transfer = new ScaleTransformation();
                if (fabs(scale) > 1e-7) {
                    transfer->TransformSceneX(scale, *scene_);
                }
                delete transfer;
            } catch (std::bad_alloc* err) {
                status.SetErrorMessage(err->what());
                status.SetStatus(false);
            }
            return status;
        };

        Scene* GetScene() const noexcept {
            return scene_;
        };

        /*!
            \brief Геттер для формирования std::vector вершин, пригодных для обработки OpenGL.
        */
        std::vector<double>* GetVertices() {
            vertices_.clear();
            for (auto it_figure = scene_->GetFigures().begin(); it_figure != scene_->GetFigures().end(); ++it_figure) {
                for (auto it_vertex = it_figure.base()->GetVertices().begin(); it_vertex != it_figure.base()->GetVertices().end(); ++it_vertex) {
                    vertices_.push_back(it_vertex.base()->GetPosition().X);
                    vertices_.push_back(it_vertex.base()->GetPosition().Y);
                    vertices_.push_back(it_vertex.base()->GetPosition().Z);
                }
            }
            return &vertices_;
        };

        /*!
            \brief Геттер для формирования std::vector индексов вершин (линий), пригодных для обработки OpenGL.
        */
        std::vector<int>* GetLines() {
            lines_.clear();
            for (auto it_figure = scene_->GetFigures().begin(); it_figure != scene_->GetFigures().end(); ++it_figure) {
                for (auto it_edges = it_figure.base()->GetEdges().begin(); it_edges != it_figure.base()->GetEdges().end(); ++it_edges) {
                    lines_.push_back(it_edges.base()->GetBegin());
                    lines_.push_back(it_edges.base()->GetEnd());
                }
            }
            return &lines_;
        };
    private:
        Reader* file_reader_;
        Scene* scene_;

        std::vector<double> vertices_;
        std::vector<int> lines_;
    };
} // namespace s21

#endif  // SRC_MODELS_FACADE_H_
