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
    if (file_name.size() > 0) {
        ui->label_file_name->setText("Path: " + file_name);
        emit ControllerOpenFile(file_name);
    }
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

void s21::View::on_pushButton_color_ver_clicked()
{
    QColor color_ver = QColorDialog::getColor(Qt::blue, this, tr("Select color"));
    ui->widget->GetState()->setValue("vertices_colorR", color_ver.redF());
    ui->widget->GetState()->setValue("vertices_colorG", color_ver.greenF());
    ui->widget->GetState()->setValue("vertices_colorB", color_ver.blueF());
    ui->widget->update();
}

void s21::View::on_pushButton_color_line_clicked()
{
    QColor color_ver = QColorDialog::getColor(Qt::red, this, tr("Select color"));
    ui->widget->GetState()->setValue("lines_colorR", color_ver.redF());
    ui->widget->GetState()->setValue("lines_colorG", color_ver.greenF());
    ui->widget->GetState()->setValue("lines_colorB", color_ver.blueF());
    ui->widget->update();
}

void s21::View::on_pushButton_color_proj_clicked()
{
    QColor color_ver = QColorDialog::getColor(Qt::black, this, tr("Select color"));
    ui->widget->GetState()->setValue("projection_colorR", color_ver.redF());
    ui->widget->GetState()->setValue("projection_colorG", color_ver.greenF());
    ui->widget->GetState()->setValue("projection_colorB", color_ver.blueF());
    ui->widget->update();
}

void s21::View::on_pushButton_redraw_clicked()
{
    ui->widget->GetState()->setValue("vertices_size", ui->spinBox_size_ver->value());
    ui->widget->GetState()->setValue("lines_size", ui->spinBox_size_line->value());

    ui->widget->GetState()->setValue("vertices_type", ui->comboBox_type_ver->currentIndex());
    ui->widget->GetState()->setValue("lines_type", ui->comboBox_type_line->currentIndex());

    ui->widget->GetState()->setValue("projection_type", ui->comboBox_type_projection->currentIndex());
    ui->widget->update();
}
