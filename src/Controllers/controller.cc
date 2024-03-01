#include "controller.h"

// Controller::Controller(QObject *parent)
//     : QObject{parent}
// {}

s21::Controller::Controller(s21::View& view, s21::ModelScene& model) : view_(view), model_(model) {
    QObject::connect(&view_, &View::ControllerOpenFile, this, &s21::Controller::LoadScene);
    QObject::connect(&view_, &View::ControllerRotateModel, this, &s21::Controller::RotateScene);
};

void s21::Controller::LoadScene(QString path) {
    model_.LoadScene(path.toStdString());
    view_.SetVertices(model_.GetVertices());
    view_.SetLines(model_.GetLines());
};

void s21::Controller::RotateScene(int value) {
    model_.RotateScene(0.0, 0.0, value);
    view_.SetVertices(model_.GetVertices());
    view_.SetLines(model_.GetLines());
};

void s21::Controller::ScaleScene(double scale) {
    model_.ScaleScene(scale);
    view_.SetVertices(model_.GetVertices());
    view_.SetLines(model_.GetLines());
};
