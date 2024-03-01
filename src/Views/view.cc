#include "view.h"
#include "./ui_view.h"

s21::View::View(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
}

s21::View::~View()
{
    delete ui;
}

void s21::View::on_pushButton_clicked()
{
    QString file_name =
        QFileDialog::getOpenFileName(this, tr("Open obj file"), "",
                                     tr("obj files (*.obj) ;; All files (*.*)"));
    ui->label_file_name->setText(file_name);
    emit ControllerOpenFile(file_name);
}

void s21::View::SetVertices(std::vector<double>* vertices) {
    ui->widget->SetVertices(*vertices);
    ui->label_count_vertex->setText(QString::number(vertices->size() / 3));
}

void s21::View::SetLines(std::vector<int>* lines) {
    ui->widget->SetLines(*lines);
    ui->label_count_poly->setText(QString::number(lines->size()));
}



void s21::View::on_horizontalSlider_rotate_valueChanged(int value)
{
    emit ControllerRotateModel(value);
}

