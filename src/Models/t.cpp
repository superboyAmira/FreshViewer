
#include "model_scene.h"
#include <iostream>

int main() {
    s21::ModelScene fac;
    auto i = fac.LoadScene("../ObjExamples/cube.obj");
    i = fac.MoveScene(1.0, 0.0, 0.0);
    i = fac.RotateScene(1.0, 0.0, 0.0);
    i = fac.ScaleScene(3.0);

    std::vector<int>* d = fac.GetLines();

    for (auto i = 0; i < d->size(); ++i) {
        std::cout << i << " " << d->at(i) << "\n";
    }

    return 0;
}

