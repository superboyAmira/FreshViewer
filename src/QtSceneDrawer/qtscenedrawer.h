#ifndef QTSCENEDRAWER_H
#define QTSCENEDRAWER_H

#include <QMainWindow>
#include <QFileDialog>

#include "../Views/sceneopenglwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class QtSceneDrawer;
}
QT_END_NAMESPACE

class QtSceneDrawer : public QMainWindow
{
    Q_OBJECT

public:
    QtSceneDrawer(QWidget *parent = nullptr);
    ~QtSceneDrawer();

private slots:
    void on_pushButton_file_path_clicked();

private:
    Ui::QtSceneDrawer *ui;
    SceneOpenGlWidget *scene_;

};
#endif // QTSCENEDRAWER_H
