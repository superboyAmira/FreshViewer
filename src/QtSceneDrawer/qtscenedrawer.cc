#include "qtscenedrawer.h"
#include "./ui_qtscenedrawer.h"


QtSceneDrawer::QtSceneDrawer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtSceneDrawer)
{
    ui->setupUi(this);
    scene_ = this->findChild<SceneOpenGlWidget *>("openGLWidget");
    // scene = this->findChild("openGLWidget");
    scene_->update();
}

QtSceneDrawer::~QtSceneDrawer()
{
    delete ui;
}

void QtSceneDrawer::on_pushButton_file_path_clicked()
{
    QString filter = "OBJ File (*.obj)";
    QString file_name =
        QFileDialog::getOpenFileName(this, "Open a file", "./", filter);
    QFile file(file_name);
    std::string path = file_name.toStdString();
    ui->labe_path->setText(file_name);
}

