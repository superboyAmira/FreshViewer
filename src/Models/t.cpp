
#include "model_scene.h"

int main() {
    s21::ModelScene fac;
    auto i = fac.LoadScene("../ObjExamples/cube.obj");
    i = fac.MoveScene(1.0, 0.0, 0.0);
    i = fac.RotateScene(1.0, 0.0, 0.0);
    i = fac.ScaleScene(3.0);
    return 0;
}