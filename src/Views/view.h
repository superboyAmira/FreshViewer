#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QFileDialog>
#include <QColorDialog>
#include <QSettings>

/*
Использование способа организации кода MVC подразумевает структурную реализацию
поведенческого паттерна Наблюдатель (Observer),
в конкретике - Представление является Obreverable, а контроллер Observer, реагрующий на
изменение модели путем связки сигналов представления с методами контроллера.
*/

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace s21 {

class View : public QWidget
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();

    void SetVertices(std::vector<double>* vertices);

    void SetLines(std::vector<int>* lines);

signals:
    void ControllerOpenFile(QString path);

    void ControllerRotateModel(double x, double y, double z);

    void ControllerMoveModel(double x, double y, double z);

    void ControllerScaleModel(double scale);

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
    Ui::View *ui;

};

}

#endif // VIEW_H
