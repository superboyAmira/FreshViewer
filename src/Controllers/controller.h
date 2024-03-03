#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMetaObject>
#include <QObject>

#include "../Models/model_scene.h"
#include "../Views/view.h"

namespace s21 {

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(s21::View& view, s21::ModelScene& model);

private slots:

    void LoadScene(QString path);

    void RotateScene(double x, double y, double z);

    void MoveScene(double x, double y, double z);

    void ScaleScene(double scale);

private:
    std::string path_;
    s21::ModelScene& model_;
    s21::View& view_;
};

}

#endif // CONTROLLER_H
