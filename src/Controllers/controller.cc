#include "controller.h"

// Controller::Controller(QObject *parent)
//     : QObject{parent}
// {}

s21::Controller::Controller(s21::View& view, s21::ModelScene& model)
    : view_(view), model_(model) {
  QObject::connect(&view_, &View::ControllerOpenFile, this,
                   &s21::Controller::LoadScene);
  QObject::connect(&view_, &View::ControllerRotateModel, this,
                   &s21::Controller::RotateScene);
  QObject::connect(&view_, &View::ControllerMoveModel, this,
                   &s21::Controller::MoveScene);
  QObject::connect(&view_, &View::ControllerScaleModel, this,
                   &s21::Controller::ScaleScene);
};

void tFunc(s21::View& v, s21::ModelScene& m) {
  v.SetVertices(m.GetVertices());
};

void tFunc2(s21::View& v, s21::ModelScene& m) { v.SetLines(m.GetLines()); };

void s21::Controller::LoadScene(QString path) {
  model_.LoadScene(path.toStdString());
  std::thread first_tr(tFunc, std::ref(view_), std::ref(model_));
  std::thread second_tr(tFunc2, std::ref(view_), std::ref(model_));
  first_tr.join();
  second_tr.join();
};

void s21::Controller::RotateScene(double x, double y, double z) {
  model_.RotateScene(x, y, z);
  view_.SetVertices(model_.GetVertices());
  view_.SetLines(model_.GetLines());
};

void s21::Controller::MoveScene(double x, double y, double z) {
  model_.MoveScene(x, y, z);
  view_.SetVertices(model_.GetVertices());
  view_.SetLines(model_.GetLines());
};

void s21::Controller::ScaleScene(double scale) {
  model_.ScaleScene(scale);
  view_.SetVertices(model_.GetVertices());
  view_.SetLines(model_.GetLines());
};
