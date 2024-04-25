#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

void MainWindow::InitScrollArea() {
  ui->sa_objects_area->setMinimumSize(kMinSqrollArea);

  ui->widget_position->setMinimumSize(kMinSizePositionWidget);
  ui->widget_position->setMaximumSize(kMaxSizePositionWidget);

  ui->widget_rotation->setMinimumSize(kMinSizeRotationWidget);
  ui->widget_rotation->setMaximumSize(kMaxSizeRotationWidget);

  ui->widget_scale->setMinimumSize(kMinSizeScaleWidget);
  ui->widget_scale->setMaximumSize(kMaxSizeScaleWidget);

  ui->widget_lines->setMinimumSize(kMinSizeLinesWidget);
  ui->widget_lines->setMaximumSize(kMaxSizeLinesWidget);

  ui->widget_vertex->setMinimumSize(kMinSizeVertexWidget);
  ui->widget_vertex->setMaximumSize(kMaxSizeVertexWidget);

  ui->widget_texture->setMinimumSize(kMinSizeTextureWidget);
  ui->widget_texture->setMaximumSize(kMaxSizeTextureWidget);

  ui->widget_spec->setMinimumSize(kMinSizeSpecWidget);
  ui->widget_spec->setMaximumSize(kMaxSizeSpecWidget);
}

void MainWindow::InitSlider(QSlider* slider, int min, int max, int start_value,
                            int step) {
  slider->setMinimum(min);
  slider->setMaximum(max);
  slider->setValue(start_value);
  slider->setSingleStep(step);
}

void MainWindow::InitSliders() {
  InitSlider(ui->slider_move_x, kSliderMoveMin, kSliderMoveMax, 0, 1);
  InitSlider(ui->slider_move_y, kSliderMoveMin, kSliderMoveMax, 0, 1);
  InitSlider(ui->slider_move_z, kSliderMoveMin, kSliderMoveMax, 0, 1);
  InitSlider(ui->slider_rotation_x, kSliderRotateMin, kSliderRotateMax, 0, 1);
  InitSlider(ui->slider_rotation_y, kSliderRotateMin, kSliderRotateMax, 0, 1);
  InitSlider(ui->slider_rotation_z, kSliderRotateMin, kSliderRotateMax, 0, 1);

  InitSlider(ui->slider_scale, kSliderScaleMin, kSliderScaleMax, 10, 1);
}

void MainWindow::InitLineEdit() {
  ui->le_move_x->setText("0.0");
  ui->le_move_y->setText("0.0");
  ui->le_move_z->setText("0.0");

  ui->le_rotation_x->setText("0.0");
  ui->le_rotation_y->setText("0.0");
  ui->le_rotation_z->setText("0.0");

  ui->le_scale->setText("1.0");

  ui->le_line_thickness->setText("1.0");

  ui->le_vertex_size->setText("1.0");
}

}  // namespace s21
