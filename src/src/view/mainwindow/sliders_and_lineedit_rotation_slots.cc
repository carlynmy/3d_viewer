#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

void MainWindow::SlidersRotationXChanged() {
  float value = ScroolToFloatRotate(ui->slider_rotation_x->value());

  ui->le_rotation_x->setText(QString::number(value, 'g', 2));

  float res = value - current_rotate_x_;
  current_rotate_x_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->RotateObject(oid, Controller::AxisId::kAxisX, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxisX, res);
      break;
    }

    default:
      controller_->RotateScene(Controller::AxisId::kAxisX, res);
      break;
  }

  controller_->Render();
}

void MainWindow::SlidersRotationYChanged() {
  float value = ScroolToFloatRotate(ui->slider_rotation_y->value());

  ui->le_rotation_y->setText(QString::number(value, 'g', 2));

  float res = value - current_rotate_y_;
  current_rotate_y_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->RotateObject(oid, Controller::AxisId::kAxisY, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxis, res);
      break;
    }

    default:
      controller_->RotateScene(Controller::AxisId::kAxisY, res);
      break;
  }

  controller_->Render();
}

void MainWindow::SlidersRotationZChanged() {
  float value = ScroolToFloatRotate(ui->slider_rotation_z->value());

  ui->le_rotation_z->setText(QString::number(value, 'g', 2));

  float res = value - current_rotate_z_;
  current_rotate_z_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->RotateObject(oid, Controller::AxisId::kAxisZ, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxisX, res);
      break;
    }

    default:
      controller_->RotateScene(Controller::AxisId::kAxisZ, res);
      break;
  }

  controller_->Render();
}

void MainWindow::LineEditRotationXChanged() {
  float value = StringToFloat(ui->le_rotation_x->text());
  if (std::isnan(value)) return;

  int scrool = FloatToScrollRotate(value);
  ui->slider_rotation_x->setValue(scrool);

  float res = value - current_rotate_x_;
  current_rotate_x_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->RotateObject(oid, Controller::AxisId::kAxisX, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxisX, res);
      break;
    }

    default:
      controller_->RotateScene(Controller::AxisId::kAxisX, res);
      break;
  }

  controller_->Render();
}

void MainWindow::LineEditRotationYChanged() {
  float value = StringToFloat(ui->le_rotation_y->text());
  if (std::isnan(value)) return;

  int scrool = FloatToScrollRotate(value);
  ui->slider_rotation_y->setValue(scrool);

  float res = value - current_rotate_y_;
  current_rotate_y_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->RotateObject(oid, Controller::AxisId::kAxisY, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxisX, res);
      break;
    }

    default:
      controller_->RotateScene(Controller::AxisId::kAxisY, res);
      break;
  }

  controller_->Render();
}

void MainWindow::LineEditRotationZChanged() {
  float value = StringToFloat(ui->le_rotation_z->text());
  if (std::isnan(value)) return;

  int scrool = FloatToScrollRotate(value);
  ui->slider_rotation_z->setValue(scrool);

  float res = value - current_rotate_z_;
  current_rotate_z_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->RotateObject(oid, Controller::AxisId::kAxisZ, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxisX, res);
      break;
    }

    default:
      controller_->RotateScene(Controller::AxisId::kAxisZ, res);
      break;
  }

  controller_->Render();
}

int MainWindow::FloatToScrollRotate(float value) {
  int slider_sum = kSliderRotateMax - kSliderRotateMin;
  float real_sum = kRealRotateMax - kRealRotateMin;
  float coef = static_cast<float>(slider_sum) / real_sum;

  int res = static_cast<int>(value - kRealRotateMin) * coef + kSliderRotateMin;

  return res;
}

float MainWindow::ScroolToFloatRotate(int value) {
  int slider_sum = kSliderRotateMax - kSliderRotateMin;
  float real_sum = kRealRotateMax - kRealRotateMin;
  float coef = static_cast<float>(slider_sum) / real_sum;

  float res =
      static_cast<float>(value - kSliderRotateMin) / coef + kRealRotateMin;

  return res;
}

}  // namespace s21
