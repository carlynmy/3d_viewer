#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

void MainWindow::SlidersScaleChanged() {
  float value = ScroolToFloatScale(ui->slider_scale->value());
  if (value <= 1e-6) return;
  ui->le_scale->setText(QString::number(value, 'g', 2));

  float res = value / current_scale_;
  current_scale_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->ScaleObject(oid, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxisX, res);
      break;
    }

    default:
      controller_->ScaleScene(res);
      break;
  }

  controller_->Render();
}

void MainWindow::LineEditScaleChanged() {
  float value = StringToFloat(ui->le_scale->text());
  if (std::isnan(value)) return;
  if (value <= 1e-6) return;

  int scroll = FloatToScrollScale(value);
  ui->slider_scale->setValue(scroll);

  float res = value / current_scale_;
  current_scale_ = value;

  switch (selected_type_) {
    case kSelectedObject: {
      ObjectId oid = selected_object_->GetObjectId();
      controller_->ScaleObject(oid, res);
      break;
    }

    case kSelectedLightSource: {
      // LightSourceId id = selected_light_->GetLightSourceId();
      // controller_->MoveLightSource(id, Controller::AxisId::kAxisX, res);
      break;
    }

    default:
      controller_->ScaleScene(res);
      break;
  }

  controller_->Render();
}

int MainWindow::FloatToScrollScale(float value) {
  int slider_sum = kSliderScaleMax - kSliderScaleMin;
  float real_sum = kRealScaleMax - kRealScaleMin;
  float coef = static_cast<float>(slider_sum) / real_sum;

  int res = static_cast<int>(value - kRealScaleMin) * coef + kSliderScaleMin;

  return res;
}

float MainWindow::ScroolToFloatScale(int value) {
  int slider_sum = kSliderScaleMax - kSliderScaleMin;
  float real_sum = kRealScaleMax - kRealScaleMin;
  float coef = static_cast<float>(slider_sum) / real_sum;

  float res =
      static_cast<float>(value - kSliderScaleMin) / coef + kRealScaleMin;

  return res;
}

}  // namespace s21
