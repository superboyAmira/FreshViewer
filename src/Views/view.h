#ifndef VIEW_H
#define VIEW_H

#include <QColorDialog>
#include <QFileDialog>
#include <QSettings>
#include <QWidget>
// set(CMAKE_PREFIX_PATH "/home/superboy/Qt/6.6.2/gcc_64/lib/cmake/Qt6")
/*
 * Использование способа организации кода MVC подразумевает структурную
 * реализацию поведенческого паттерна Наблюдатель (Observer), в конкретике -
 * Представление является Obreverable, а контроллер Observer, реагрующий на
 * изменение модели путем связки сигналов представления с методами контроллера.
 */

QT_BEGIN_NAMESPACE
namespace Ui {

/*!
 * \brief Класс объекта представления.
 */
class View;
}  // namespace Ui
QT_END_NAMESPACE

namespace s21 {

/*!
 * \brief Класс реализующий логику графического интерфейса приложения.
 */
class View : public QWidget {
  Q_OBJECT

 public:
  View(QWidget* parent = nullptr);
  ~View();

  void SetVertices(std::vector<double>* vertices);

  void SetLines(std::vector<int>* lines);

 signals:
  /*!
   * \brief Сигнал для триггера Наблюдателя(Controller).
   */
  void ControllerOpenFile(QString path);

  /*!
   * \brief Сигнал для триггера Наблюдателя(Controller).
   */
  void ControllerRotateModel(double x, double y, double z);

  /*!
   * \brief Сигнал для триггера Наблюдателя(Controller).
   */
  void ControllerMoveModel(double x, double y, double z);

  /*!
   * \brief Сигнал для триггера Наблюдателя(Controller).
   */
  void ControllerScaleModel(double scale);

  /*!
   * \brief Сигнал для триггера Наблюдателя(Controller).
   */
  void ControllerSaveState(QSettings& state);

 private slots:
  void on_pushButton_clicked();

  void on_pushButton_rotate_clicked();

  void on_pushButton_move_clicked();

  void on_pushButton_scale_clicked();

  void on_pushButton_color_ver_clicked();

  void on_pushButton_color_line_clicked();

  void on_pushButton_color_proj_clicked();

  void on_pushButton_redraw_clicked();

 private:
  Ui::View* ui;
};

}  // namespace s21

#endif  // VIEW_H
