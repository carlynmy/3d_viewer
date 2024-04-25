#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QRadioButton>
#include <QTimer>

#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

void MainWindow::UiConnect() {
  connect(ui->pb_add_object, &QPushButton::clicked, this,
          &MainWindow::ButtonAddObjectsClicked);
  connect(ui->pb_clone_object, &QPushButton::clicked, this,
          &MainWindow::ButtonCloneObjectClicked);
  ShowHideWidgetConnects();
  PositionWidgetConnects();
  RotationWidgetConnects();
  ScaleWidgetConnects();
  LinesWidgetConnects();
  VertexWidgetConnects();
  TextureWidgetConnects();
  SpecFuncConnects();
}

void MainWindow::RenderedObjectConnects(RenderedObject* obj) {
  connect(obj, &RenderedObject::ObjectSelected, this,
          &MainWindow::SelectObjectCalled);
  connect(obj, &RenderedObject::ObjectDeleted, this,
          &MainWindow::ButtonsRemoveObjectClicked);
  connect(obj, &RenderedObject::ObjectShowHide, this,
          &MainWindow::ShowHideObjectCalled);
  connect(obj, &RenderedObject::MouseMovedOnWidget, this,
          &MainWindow::ShowNumberOfVerticesEdgesCalled);
  connect(obj, &RenderedObject::MouseWentBehindTheWidget, this,
          &MainWindow::DeleteObjectInfoCalled);
}

void MainWindow::ShowHideWidgetConnects() {
  connect(ui->pb_widget_position_show_hide, &QPushButton::clicked, this,
          &MainWindow::ButtonPositionHideClicked);
  connect(ui->pb_widget_rotation_show_hide, &QPushButton::clicked, this,
          &MainWindow::ButtonRotateHideClicked);
  connect(ui->pb_widget_scale_show_hide, &QPushButton::clicked, this,
          &MainWindow::ButtonSchaleHideClicked);
  connect(ui->pb_widget_lines_show_hide, &QPushButton::clicked, this,
          &MainWindow::ButtonLinesHideClicked);
  connect(ui->pb_widget_vertex_show_hide, &QPushButton::clicked, this,
          &MainWindow::ButtonVertexHideClicked);
  connect(ui->pb_widget_texture_show_hide, &QPushButton::clicked, this,
          &MainWindow::ButtonTextureHideClicked);
  connect(ui->pb_widget_spec_show_hide, &QPushButton::clicked, this,
          &MainWindow::ButtonSpecHideClicked);
}

void MainWindow::PositionWidgetConnects() {
  connect(ui->slider_move_x, &QSlider::sliderMoved, this,
          &MainWindow::SlidersPositionXChanged);
  connect(ui->slider_move_y, &QSlider::sliderMoved, this,
          &MainWindow::SlidersPositionYChanged);
  connect(ui->slider_move_z, &QSlider::sliderMoved, this,
          &MainWindow::SlidersPositionZChanged);
  connect(ui->le_move_x, &QLineEdit::textEdited, this,
          &MainWindow::LineEditPositionXChanged);
  connect(ui->le_move_y, &QLineEdit::textEdited, this,
          &MainWindow::LineEditPositionYChanged);
  connect(ui->le_move_z, &QLineEdit::textEdited, this,
          &MainWindow::LineEditPositionZChanged);
}

void MainWindow::RotationWidgetConnects() {
  connect(ui->slider_rotation_x, &QSlider::sliderMoved, this,
          &MainWindow::SlidersRotationXChanged);
  connect(ui->slider_rotation_y, &QSlider::sliderMoved, this,
          &MainWindow::SlidersRotationYChanged);
  connect(ui->slider_rotation_z, &QSlider::sliderMoved, this,
          &MainWindow::SlidersRotationZChanged);
  connect(ui->le_rotation_x, &QLineEdit::textEdited, this,
          &MainWindow::LineEditRotationXChanged);
  connect(ui->le_rotation_y, &QLineEdit::textEdited, this,
          &MainWindow::LineEditRotationYChanged);
  connect(ui->le_rotation_z, &QLineEdit::textEdited, this,
          &MainWindow::LineEditRotationZChanged);
}

void MainWindow::ScaleWidgetConnects() {
  connect(ui->slider_scale, &QSlider::sliderMoved, this,
          &MainWindow::SlidersScaleChanged);
  connect(ui->le_scale, &QLineEdit::textEdited, this,
          &MainWindow::LineEditScaleChanged);
}

void MainWindow::LinesWidgetConnects() {
  connect(ui->rb_solid_line, &QRadioButton::toggled, this,
          &MainWindow::RadioButtonLinesSolidToggled);
  connect(ui->rb_dotted_line, &QRadioButton::toggled, this,
          &MainWindow::RadioButtonLinesDottedToggled);
  connect(ui->pb_change_lines_color, &QPushButton::clicked, this,
          &MainWindow::ButtonChangeColorLinesClicked);
  connect(ui->le_line_thickness, &QLineEdit::editingFinished, this,
          &MainWindow::LineEditSizeLineChanged);
}

void MainWindow::VertexWidgetConnects() {
  connect(ui->com_box_type_vertex, &QComboBox::currentTextChanged, this,
          &MainWindow::ComboBoxVertexTypeChanged);
  connect(ui->pb_change_vertex_color, &QPushButton::clicked, this,
          &MainWindow::ButtonChangeColorVertexClicked);
  connect(ui->le_vertex_size, &QLineEdit::editingFinished, this,
          &MainWindow::LineEditSizeVertexChanged);
}

void MainWindow::TextureWidgetConnects() {
  connect(ui->pb_add_texture, &QPushButton::clicked, this,
          &MainWindow::ButtonAddTextureClicked);
  connect(ui->com_box_polygon_mod_type, &QComboBox::currentTextChanged, this,
          &MainWindow::ComboBoxCurrentPolygonModChanged);
}

void MainWindow::SpecFuncConnects() {
  connect(ui->pb_change_projection, &QPushButton::clicked, this,
          &MainWindow::ButtonSwitchProjectionClicked);
  connect(ui->pb_change_color_back, &QPushButton::clicked, this,
          &MainWindow::ButtonChangeColorBackgroundClicked);
  connect(ui->pb_save_jpeg, &QPushButton::clicked, this,
          &MainWindow::ButtonSaveJPEGClicked);
  connect(ui->pb_save_bmp, &QPushButton::clicked, this,
          &MainWindow::ButtonSaveBMPClicked);
  connect(ui->pb_save_gif, &QPushButton::clicked, this,
          &MainWindow::ButtonSaveGIFClicked);
  connect(&gif_timer_, &QTimer::timeout, this, &MainWindow::AddFrameToGif);
  connect(&timer_, &QTimer::timeout, this, &MainWindow::ClearInfoLabel);
  connect(ui->cb_axes, &QCheckBox::stateChanged, this,
          &MainWindow::CheckBoxShowAxesStateChanged);
  connect(ui->cb_floor, &QCheckBox::stateChanged, this,
          &MainWindow::CheckBoxShowFloorStateChanged);
}

}  // namespace s21
