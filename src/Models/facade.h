#ifndef SRC_MODELS_FACADE_H_
#define SRC_MODELS_FACADE_H_

#include "file_reader.h"
#include "scene.h"

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

    class Facade {
    public:
        Facade() : file_reader_(nullptr), scene_(nullptr) {};
        ~Facade() noexcept = default;


        // FacadeOperationResult DrawScene() {};

        FacadeOperationResult LoadScene(std::string path) {
            FacadeOperationResult status = FacadeOperationResult();
            try {
                file_reader_ = new Reader();
                scene_ = file_reader_->ReadScene(path);
            } catch (std::invalid_argument* err) {
                status.SetErrorMessage(err->what());
                status.SetStatus(false);
            } catch (...) {
                status.SetErrorMessage("Another trouble/LoadScene/Facade");
                status.SetStatus(false);
            }
            return status;
        };

        // FacadeOperationResult MoveScene(double x, double y, double z) {};

        // FacadeOperationResult RotateScene(double x, double y, double z) {};

        // FacadeOperationResult ScaleScene(double x, double y, double z) {};
    private:
        Reader* file_reader_;
        Scene* scene_;
        // SceneDrawerBase scene_drawer_;
    };
} // namespace s21


#endif  // SRC_MODELS_FACADE_H_