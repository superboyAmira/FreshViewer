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
    ui->label_file_name->setText("Path: " + file_name);
    emit ControllerOpenFile(file_name);
}

void s21::View::SetVertices(std::vector<double>* vertices) {
    ui->widget->SetVertices(*vertices);
    ui->label_count_vertex->setText("Vertices: " + QString::number(vertices->size() / 3));
}

void s21::View::SetLines(std::vector<int>* lines) {
    ui->widget->SetLines(*lines);
    ui->label_count_poly->setText("Lines: " + QString::number(lines->size()));
}

void s21::View::on_pushButton_rotate_clicked()
{
    emit ControllerRotateModel(ui->doubleSpinBox_x_rotate->value(), ui->doubleSpinBox_y_rotate->value(), ui->doubleSpinBox_z_roate->value());
}

void s21::View::on_pushButton_move_clicked()
{
    emit ControllerMoveModel(ui->doubleSpinBox_x_move->value(), ui->doubleSpinBox_y_move->value(), ui->doubleSpinBox_z_move->value());
}

void s21::View::on_pushButton_scale_clicked()
{
    emit ControllerScaleModel(ui->doubleSpinBox_scale->value());
}

