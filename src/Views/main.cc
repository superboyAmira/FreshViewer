#include "view.h"
#include "../Controllers/controller.h"
#include "../Models/model_scene.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    s21::View view;
    s21::ModelScene model;
    s21::Controller controller(view, model);
    view.show();
    return a.exec();
}
