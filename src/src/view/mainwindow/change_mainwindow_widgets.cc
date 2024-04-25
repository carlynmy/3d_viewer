#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

void MainWindow::SelectObjectCalled(RenderedObject* obj) {
  // if unselect
  if (obj == selected_object_) {
    SelectScene();
    return;
  }

  UpdatePrevSelected();

  obj->ChangeStyleSheetSelected();
  selected_type_ = kSelectedObject;
  selected_object_ = obj;

  current_rotate_x_ = obj->GetRotateX();
  current_rotate_y_ = obj->GetRotateY();
  current_rotate_z_ = obj->GetRotateZ();

  current_move_x_ = obj->GetMoveX();
  current_move_y_ = obj->GetMoveY();
  current_move_z_ = obj->GetMoveZ();

  current_scale_ = obj->GetScale();

  current_line_type_ = obj->GetLineType();
  current_line_size_ = obj->GetLineSize();
  current_line_color_ = obj->GetLineColor();

  current_vertex_type_ = obj->GetVertexType();
  current_vertex_size_ = obj->GetVertexSize();
  current_vertex_color_ = obj->GetVertexColor();

  RenderedObject::PolygonMode mode = obj->GetPolygonMode();
  FromROPolygonToMWPolygon(mode);

  SetCurrentScrollValues();
}

void MainWindow::FromROPolygonToMWPolygon(RenderedObject::PolygonMode mode) {
  switch (mode) {
    case RenderedObject::PolygonMode::kPolygonModeFill:
      current_polygon_mode_ = Controller::PolygonMode::kPolygonModeFill;
      break;
    case RenderedObject::PolygonMode::kPolygonModeLine:
      current_polygon_mode_ = Controller::PolygonMode::kPolygonModeLine;
      break;
    case RenderedObject::PolygonMode::kPolygonModeTexture:
      current_polygon_mode_ = Controller::PolygonMode::kPolygonModeTexture;
      break;
  }
}

void MainWindow::SelectLightSourceCalled(RenderedLight* obj, LightSourceId id) {
  // if unselect
  if (obj == selected_light_) {
    SelectScene();
    return;
  }

  UpdatePrevSelected();

  obj->ChangeStyleSheetSelected();
  selected_type_ = kSelectedLightSource;
  selected_light_ = obj;

  current_rotate_x_ = obj->GetRotateX();
  current_rotate_y_ = obj->GetRotateY();
  current_rotate_z_ = obj->GetRotateZ();
  current_move_x_ = obj->GetMoveX();
  current_move_y_ = obj->GetMoveY();
  current_move_z_ = obj->GetMoveZ();
  current_scale_ = obj->GetScale();

  SetCurrentScrollValues();
}

void MainWindow::SelectScene() {
  UpdatePrevSelected();

  selected_type_ = kSelectedScene;
  selected_light_ = nullptr;
  selected_object_ = nullptr;

  current_rotate_x_ = rotate_x_;
  current_rotate_y_ = rotate_y_;
  current_rotate_z_ = rotate_z_;
  current_move_x_ = move_x_;
  current_move_y_ = move_y_;
  current_move_z_ = move_z_;
  current_scale_ = scale_;

  SetCurrentScrollValues();
}

void MainWindow::UpdatePrevSelected() {
  switch (selected_type_) {
    case kSelectedObject:
      selected_object_->SetRotateX(current_rotate_x_);
      selected_object_->SetRotateY(current_rotate_y_);
      selected_object_->SetRotateZ(current_rotate_z_);

      selected_object_->SetMoveX(current_move_x_);
      selected_object_->SetMoveY(current_move_y_);
      selected_object_->SetMoveZ(current_move_z_);

      selected_object_->SetScale(current_scale_);

      selected_object_->SetPolygonMode(
          FromMWPolygonToROPolygon(current_polygon_mode_));

      selected_object_->SetLineColor(current_line_color_);
      selected_object_->SetLineSize(current_line_size_);
      selected_object_->SetLineType(current_line_type_);

      selected_object_->SetVertexColor(current_vertex_color_);
      selected_object_->SetVertexSize(current_vertex_size_);
      selected_object_->SetVertexType(current_vertex_type_);

      selected_object_->ChangeStyleSheetDefault();
      break;

    case kSelectedLightSource:
      selected_light_->SetRotateX(current_rotate_x_);
      selected_light_->SetRotateY(current_rotate_y_);
      selected_light_->SetRotateZ(current_rotate_z_);
      selected_light_->SetMoveX(current_move_x_);
      selected_light_->SetMoveY(current_move_y_);
      selected_light_->SetMoveZ(current_move_z_);
      selected_light_->SetScale(current_scale_);
      selected_light_->ChangeStyleSheetDefault();
      break;

    default:
      rotate_x_ = current_rotate_x_;
      rotate_y_ = current_rotate_y_;
      rotate_z_ = current_rotate_z_;
      move_x_ = current_move_x_;
      move_y_ = current_move_y_;
      move_z_ = current_move_z_;
      scale_ = current_scale_;
      break;
  }
}

RenderedObject::PolygonMode MainWindow::FromMWPolygonToROPolygon(
    Controller::PolygonMode mode) {
  switch (mode) {
    case Controller::PolygonMode::kPolygonModeFill:
      return RenderedObject::PolygonMode::kPolygonModeFill;
      break;
    case Controller::PolygonMode::kPolygonModeTexture:
      return RenderedObject::PolygonMode::kPolygonModeTexture;
      break;
    default:
      break;
  }
  return RenderedObject::PolygonMode::kPolygonModeLine;
}

void MainWindow::SetCurrentScrollValues() {
  ui->le_rotation_x->setText(QString::number(current_rotate_x_, 'g', 2));
  ui->le_rotation_y->setText(QString::number(current_rotate_y_, 'g', 2));
  ui->le_rotation_z->setText(QString::number(current_rotate_z_, 'g', 2));

  ui->le_move_x->setText(QString::number(current_move_x_, 'g', 2));
  ui->le_move_y->setText(QString::number(current_move_y_, 'g', 2));
  ui->le_move_z->setText(QString::number(current_move_z_, 'g', 2));

  ui->le_scale->setText(QString::number(current_scale_, 'g', 2));

  ui->slider_rotation_x->setValue(FloatToScrollRotate(current_rotate_x_));
  ui->slider_rotation_y->setValue(FloatToScrollRotate(current_rotate_y_));
  ui->slider_rotation_z->setValue(FloatToScrollRotate(current_rotate_z_));

  ui->slider_move_x->setValue(FloatToScrollMove(current_move_x_));
  ui->slider_move_y->setValue(FloatToScrollMove(current_move_y_));
  ui->slider_move_z->setValue(FloatToScrollMove(current_move_z_));

  ui->slider_scale->setValue(FloatToScrollScale(current_scale_));

  SetCurrentButtonsColor();

  switch (current_polygon_mode_) {
    case Controller::PolygonMode::kPolygonModeFill:
      ui->com_box_polygon_mod_type->setCurrentText(kPolygonModeFillStr);
      break;
    case Controller::PolygonMode::kPolygonModeLine:
      ui->com_box_polygon_mod_type->setCurrentText(kPolygonModeLineStr);
      break;
    case Controller::PolygonMode::kPolygonModeTexture:
      ui->com_box_polygon_mod_type->setCurrentText(kPolygonModeTextureStr);
      break;
  }

  ui->le_line_thickness->setText(QString::number(current_line_size_, 'g', 2));

  ui->le_vertex_size->setText(QString::number(current_vertex_size_, 'g', 2));

  if (current_line_type_ == Controller::LineTypes::kLineTypeDotted) {
    ui->rb_dotted_line->setChecked(true);
    ui->rb_solid_line->setChecked(false);
  } else {
    ui->rb_dotted_line->setChecked(false);
    ui->rb_solid_line->setChecked(true);
  }

  if (current_vertex_type_ == Controller::VertexTypes::kVertexTypeNone) {
    ui->com_box_type_vertex->setCurrentText(kVertexTypeNoneStr);
  } else if (current_vertex_type_ ==
             Controller::VertexTypes::kVertexTypeCircle) {
    ui->com_box_type_vertex->setCurrentText(kVertexTypeCircleStr);
  } else if (current_vertex_type_ ==
             Controller::VertexTypes::kVertexTypeSquare) {
    ui->com_box_type_vertex->setCurrentText(kVertexTypeSquareStr);
  }
}

void MainWindow::SetCurrentButtonsColor() {
  QString color = GetColorStyleString(current_line_color_);
  ui->pb_change_lines_color->setStyleSheet(color);

  color = GetColorStyleString(current_vertex_color_);
  ui->pb_change_vertex_color->setStyleSheet(color);
}

}  // namespace s21
