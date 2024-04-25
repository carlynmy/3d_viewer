#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

void MainWindow::ButtonRotateHideClicked() {
  QRect geometry = ui->widget_rotation->geometry();
  QSize size = QSize(geometry.width(), geometry.height());
  if (size == kMaxSizeRotationWidget) {
    ui->pb_widget_rotation_show_hide->setText(kShowWindowText);
    ui->widget_rotation->setMinimumSize(kMinSizeRotationWidget);
    ui->widget_rotation->setMaximumSize(kMinSizeRotationWidget);
  } else {
    ui->pb_widget_rotation_show_hide->setText(kHideWindowText);
    ui->widget_rotation->setMinimumSize(kMaxSizeRotationWidget);
    ui->widget_rotation->setMaximumSize(kMaxSizeRotationWidget);
  }
}

void MainWindow::ButtonPositionHideClicked() {
  QRect geometry = ui->widget_position->geometry();
  QSize size = QSize(geometry.width(), geometry.height());
  if (size == kMaxSizePositionWidget) {
    ui->pb_widget_position_show_hide->setText(kShowWindowText);
    ui->widget_position->setMinimumSize(kMinSizePositionWidget);
    ui->widget_position->setMaximumSize(kMinSizePositionWidget);
  } else {
    ui->pb_widget_position_show_hide->setText(kHideWindowText);
    ui->widget_position->setMinimumSize(kMaxSizePositionWidget);
    ui->widget_position->setMaximumSize(kMaxSizePositionWidget);
  }
}

void MainWindow::ButtonSchaleHideClicked() {
  QRect geometry = ui->widget_scale->geometry();
  QSize size = QSize(geometry.width(), geometry.height());
  if (size == kMaxSizeScaleWidget) {
    ui->pb_widget_scale_show_hide->setText(kShowWindowText);
    ui->widget_scale->setMinimumSize(kMinSizeScaleWidget);
    ui->widget_scale->setMaximumSize(kMinSizeScaleWidget);
  } else {
    ui->pb_widget_scale_show_hide->setText(kHideWindowText);
    ui->widget_scale->setMinimumSize(kMaxSizeScaleWidget);
    ui->widget_scale->setMaximumSize(kMaxSizeScaleWidget);
  }
}

void MainWindow::ButtonLinesHideClicked() {
  QRect geometry = ui->widget_lines->geometry();
  QSize size = QSize(geometry.width(), geometry.height());
  if (size == kMaxSizeLinesWidget) {
    ui->pb_widget_lines_show_hide->setText(kShowWindowText);
    ui->widget_lines->setMinimumSize(kMinSizeLinesWidget);
    ui->widget_lines->setMaximumSize(kMinSizeLinesWidget);
  } else {
    ui->pb_widget_lines_show_hide->setText(kHideWindowText);
    ui->widget_lines->setMinimumSize(kMaxSizeLinesWidget);
    ui->widget_lines->setMaximumSize(kMaxSizeLinesWidget);
  }
}

void MainWindow::ButtonVertexHideClicked() {
  QRect geometry = ui->widget_vertex->geometry();
  QSize size = QSize(geometry.width(), geometry.height());
  if (size == kMaxSizeVertexWidget) {
    ui->pb_widget_vertex_show_hide->setText(kShowWindowText);
    ui->widget_vertex->setMinimumSize(kMinSizeVertexWidget);
    ui->widget_vertex->setMaximumSize(kMinSizeVertexWidget);
  } else {
    ui->pb_widget_vertex_show_hide->setText(kHideWindowText);
    ui->widget_vertex->setMinimumSize(kMaxSizeVertexWidget);
    ui->widget_vertex->setMaximumSize(kMaxSizeVertexWidget);
  }
}

void MainWindow::ButtonTextureHideClicked() {
  QRect geometry = ui->widget_texture->geometry();
  QSize size = QSize(geometry.width(), geometry.height());
  if (size == kMaxSizeTextureWidget) {
    ui->pb_widget_texture_show_hide->setText(kShowWindowText);
    ui->widget_texture->setMinimumSize(kMinSizeTextureWidget);
    ui->widget_texture->setMaximumSize(kMinSizeTextureWidget);
  } else {
    ui->pb_widget_texture_show_hide->setText(kHideWindowText);
    ui->widget_texture->setMinimumSize(kMaxSizeTextureWidget);
    ui->widget_texture->setMaximumSize(kMaxSizeTextureWidget);
  }
}

void MainWindow::ButtonSpecHideClicked() {
  QRect geometry = ui->widget_spec->geometry();
  QSize size = QSize(geometry.width(), geometry.height());
  if (size == kMaxSizeSpecWidget) {
    ui->pb_widget_spec_show_hide->setText(kShowWindowText);
    ui->widget_spec->setMinimumSize(kMinSizeSpecWidget);
    ui->widget_spec->setMaximumSize(kMinSizeSpecWidget);
  } else {
    ui->pb_widget_spec_show_hide->setText(kHideWindowText);
    ui->widget_spec->setMinimumSize(kMaxSizeSpecWidget);
    ui->widget_spec->setMaximumSize(kMaxSizeSpecWidget);
  }
}

}  // namespace s21
