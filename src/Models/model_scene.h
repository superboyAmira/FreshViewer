#ifndef SRC_MODELS_FACADE_H_
#define SRC_MODELS_FACADE_H_

#include "file_reader.h"
#include "scene.h"
#include "affine_transformations.h"

/*
В данном классе используется структурный паттерн Фасад.
ModelScene выступает в роли фасада для большого набора классов реализующих парсинг
и хранения данных их .obj файлов. Клиентом выступает Controller.
*/

namespace s21
{
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

    class ModelScene {
    public:
        ModelScene() : file_reader_(nullptr), scene_(nullptr) {};
        ~ModelScene() noexcept {
            if (file_reader_ != nullptr) {
                delete file_reader_;
            }
        };

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

        ModelOperationResult MoveScene(double x, double y, double z) {
            ModelOperationResult status = ModelOperationResult();
            try {
                BaseTransormation* transfer = new MoveTransformation();
                if (abs(x) > 1e-7) {
                    transfer->TransformSceneX(x, *scene_);
                }
                if (abs(y) > 1e-7) {
                    transfer->TransformSceneY(y, *scene_);
                }
                if (abs(z) > 1e-7) {
                    transfer->TransformSceneZ(z, *scene_);
                }
                delete transfer;
            } catch (std::bad_alloc* err) {
                status.SetErrorMessage(err->what());
                status.SetStatus(false);
            }
            
            return status;
        };

        ModelOperationResult RotateScene(double x, double y, double z) {
            ModelOperationResult status = ModelOperationResult();
            try {
                BaseTransormation* transfer = new RotateTransformation();
                if (abs(x) > 1e-7) {
                    transfer->TransformSceneX(x, *scene_);
                }
                if (abs(y) > 1e-7) {
                    transfer->TransformSceneY(y, *scene_);
                }
                if (abs(z) > 1e-7) {
                    transfer->TransformSceneZ(z, *scene_);
                }
                delete transfer;
            } catch (std::bad_alloc* err) {
                status.SetErrorMessage(err->what());
                status.SetStatus(false);
            }
            
            return status;
        };

        ModelOperationResult ScaleScene(double scale) {
            ModelOperationResult status = ModelOperationResult();
            try {
                BaseTransormation* transfer = new ScaleTransformation();
                if (abs(scale) > 1e-7) {
                    transfer->TransformSceneX(scale, *scene_);
                }
                delete transfer;
            } catch (std::bad_alloc* err) {
                status.SetErrorMessage(err->what());
                status.SetStatus(false);
            }
            return status;
        };

        /* Не по диаграмме. Эти геттеры нужны для сохранения паттерна Фасад */

        Scene* GetScene() const noexcept {
            return scene_;
        };

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

        std::vector<int>* GetLines() {
            lines_.clear();
            for (auto it_figure = scene_->GetFigures().begin(); it_figure != scene_->GetFigures().end(); ++it_figure) {
                for (auto it_edges = it_figure.base()->GetEdges().begin(); it_edges != it_figure.base()->GetEdges().end(); ++it_edges) {
                    lines_.push_back(it_edges.base()->GetBegin()->GetPosition().index);
                    lines_.push_back(it_edges.base()->GetEnd()->GetPosition().index);
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
