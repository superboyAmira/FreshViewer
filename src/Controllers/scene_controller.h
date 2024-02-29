#ifndef SCENE_CONTROLLER_H
#define SCENE_CONTROLLER_H

#include "../Models/model_scene.h"

namespace s21 {

class SceneController {
public:
    SceneController();
    ~SceneController();

    void SetPath(std::string file_name) noexcept {
        path_ = file_name;
    };

    void DrawScene() {

    };
private:
    std::string path_;
    s21::ModelScene* model;
};

};

#endif // SCENE_CONTROLLER_H
