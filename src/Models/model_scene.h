#ifndef SRC_MODELS_FACADE_H_
#define SRC_MODELS_FACADE_H_

#include "file_reader.h"
#include "scene.h"
#include "affine_transformations.h"

namespace s21
{
    class FacadeOperationResult {
        public:
            FacadeOperationResult() {
                errorMessage_ = "";
                is_success_ = true;
            };
            ~FacadeOperationResult() noexcept = default;

            void SetErrorMessage(std::string err) noexcept { errorMessage_ = err; };
            void SetStatus(bool status) noexcept { is_success_ = status; };
            std::string GetErrorMessage() const noexcept { return errorMessage_; };
            bool IsSuccess() const noexcept { return is_success_; };

        private:
            std::string errorMessage_;
            bool is_success_;  
    };

    /*
    \brief Основной класс модели, реализующий паттерн Фасад.
    */
    class ModelScene {
    public:
        ModelScene() : file_reader_(nullptr), scene_(nullptr) {};
        ~ModelScene() noexcept {
            if (file_reader_ != nullptr) {
                delete file_reader_;
            }
            if (scene_ != nullptr) {
                delete scene_;
            }
        };

        // FacadeOperationResult DrawScene() {

        // };

        FacadeOperationResult LoadScene(std::string path) {
            FacadeOperationResult status = FacadeOperationResult();
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

        FacadeOperationResult MoveScene(double x, double y, double z) {
            FacadeOperationResult status = FacadeOperationResult();
            try {
                MoveTransformation* transfer = new MoveTransformation();
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

        FacadeOperationResult RotateScene(double x, double y, double z) {
            FacadeOperationResult status = FacadeOperationResult();
            try {
                RotateTransformation* transfer = new RotateTransformation();
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

        FacadeOperationResult ScaleScene(double scale) {
            FacadeOperationResult status = FacadeOperationResult();
            try {
                ScaleTransformation* transfer = new ScaleTransformation();
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

        Scene& GetScene() const noexcept {
            return *scene_;
        };
    private:
        Reader* file_reader_;
        Scene* scene_;
    };
} // namespace s21


#endif  // SRC_MODELS_FACADE_H_