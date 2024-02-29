#include "qtscenedrawer.h"
#include <QApplication>

// #include "../Models/model_scene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // s21::ModelScene model;
    QtSceneDrawer w;
    w.show();
    return a.exec();
}
