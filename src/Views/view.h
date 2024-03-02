#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QFileDialog>

#include "viewopenglscene.h"

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_rotate_clicked();

    void on_pushButton_move_clicked();

    void on_pushButton_scale_clicked();

private:
    Ui::View *ui;



};

}

#endif // VIEW_H
