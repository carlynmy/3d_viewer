#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

void MainWindow::SlidersPositionXChanged() {
  float value = ScroolToFloatMove(ui->slider_move_x->value());

  ui->le_move_x->setText(QString::number(value, 'g', 2));

  float res = value - current_move_x_;
  current_move_x_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->MoveObject(oid, Controller::AxisId::kAxisX, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxisX, res);
      break;
    }

    default:
      controller_->MoveScene(Controller::AxisId::kAxisX, res);
      break;
  }

  controller_->Render();
}

void MainWindow::SlidersPositionYChanged() {
  float value = ScroolToFloatMove(ui->slider_move_y->value());

  ui->le_move_y->setText(QString::number(value, 'g', 2));

  float res = value - current_move_y_;
  current_move_y_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->MoveObject(oid, Controller::AxisId::kAxisY, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxisY, res);
      break;
    }

    default:
      controller_->MoveScene(Controller::AxisId::kAxisY, res);
      break;
  }

  controller_->Render();
}

void MainWindow::SlidersPositionZChanged() {
  float value = ScroolToFloatMove(ui->slider_move_z->value());

  ui->le_move_z->setText(QString::number(value, 'g', 2));

  float res = value - current_move_z_;
  current_move_z_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->MoveObject(oid, Controller::AxisId::kAxisZ, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxisZ, res);
      break;
    }

    default:
      controller_->MoveScene(Controller::AxisId::kAxisZ, res);
      break;
  }

  controller_->Render();
}

void MainWindow::LineEditPositionXChanged() {
  float value = StringToFloat(ui->le_move_x->text());
  if (std::isnan(value)) return;

  int scrool = FloatToScrollMove(value);
  ui->slider_move_x->setValue(scrool);

  float res = value - current_move_x_;
  current_move_x_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->MoveObject(oid, Controller::AxisId::kAxisX, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxisX, res);
      break;
    }

    default:
      controller_->MoveScene(Controller::AxisId::kAxisX, res);
      break;
  }

  controller_->Render();
}

void MainWindow::LineEditPositionYChanged() {
  float value = StringToFloat(ui->le_move_y->text());
  if (std::isnan(value)) return;

  int scrool = FloatToScrollMove(value);
  ui->slider_move_y->setValue(scrool);

  float res = value - current_move_y_;
  current_move_y_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->MoveObject(oid, Controller::AxisId::kAxisY, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxisY, res);
      break;
    }

    default:
      controller_->MoveScene(Controller::AxisId::kAxisY, res);
      break;
  }

  controller_->Render();
}

void MainWindow::LineEditPositionZChanged() {
  float value = StringToFloat(ui->le_move_z->text());
  if (std::isnan(value)) return;

  int scrool = FloatToScrollMove(value);
  ui->slider_move_z->setValue(scrool);

  float res = value - current_move_z_;
  current_move_z_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->MoveObject(oid, Controller::AxisId::kAxisZ, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxisZ, res);
      break;
    }

    default:
      controller_->MoveScene(Controller::AxisId::kAxisZ, res);
      break;
  }

  controller_->Render();
}

int MainWindow::FloatToScrollMove(float value) {
  int slider_sum = kSliderMoveMax - kSliderMoveMin;
  float real_sum = kRealMoveMax - kRealMoveMin;
  float coef = static_cast<float>(slider_sum) / real_sum;

  int res = static_cast<int>(value - kRealMoveMin) * coef + kSliderMoveMin;

  return res;
}

float MainWindow::ScroolToFloatMove(int value) {
  int slider_sum = kSliderMoveMax - kSliderMoveMin;
  float real_sum = kRealMoveMax - kRealMoveMin;
  float coef = static_cast<float>(slider_sum) / real_sum;

  float res = static_cast<float>(value - kSliderMoveMin) / coef + kRealMoveMin;

  return res;
}

}  // namespace s21
