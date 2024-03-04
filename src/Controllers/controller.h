#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <threads.h>

#include <QMetaObject>
#include <QObject>
#include <thread>

#include "../Models/model_scene.h"
#include "../Views/view.h"

namespace s21 {

/*!
 * \brief Класс контроллера, являющий частью реализации паттерна MVC.
 */
class Controller : public QObject {
  Q_OBJECT
 public:
  /*!
   * \brief Параметризованный конструктор, позволяющий создать объект Controller
   * только из main.cc. \param view Ссылка на класс представления. \param model
   * Ссылка на класс модели.
   */
  Controller(s21::View& view, s21::ModelScene& model);

 private slots:

  /*!
   * \brief Метод первичной обработки 3Д модели из файла классом ModelScene.
   * \param path Путь к файлу.
   */
  void LoadScene(QString path);

  /*!
   * \brief Метод поворота 3Д модели классом ModelScene.
   * \param x
   * \param y
   * \param z
   */
  void RotateScene(double x, double y, double z);

  /*!
   * \brief Метод перемещения 3Д модели классом ModelScene.
   * \param x
   * \param y
   * \param z
   */
  void MoveScene(double x, double y, double z);

  /*!
   * \brief Метод масштабирования 3Д модели классом ModelScene.
   * \param x
   * \param y
   * \param z
   */
  void ScaleScene(double scale);

 private:
  std::string path_;
  s21::ModelScene& model_;
  s21::View& view_;
};

}  // namespace s21

#endif  // CONTROLLER_H
