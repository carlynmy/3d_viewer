#include <QColorDialog>
#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

void MainWindow::ButtonAddTextureClicked() {
  if (selected_type_ != SelectedType::kSelectedObject) return;
  if (ui->com_box_polygon_mod_type->currentText() != "Текстурная модель")
    return;

  controller_->SetPolygonModeObject(
      selected_object_->GetObjectId(),
      Controller::PolygonMode::kPolygonModeTexture);

  QString qpath = QFileDialog::getOpenFileName(
      this, tr("Выбрать файл текстуры"), "~", tr("*.bmp (*.bmp)"));

  controller_->SetTextureObject(selected_object_->GetObjectId(),
                                qpath.toStdString());
  controller_->Render();
}

void MainWindow::ComboBoxCurrentPolygonModChanged(const QString& text) {
  if (selected_type_ != SelectedType::kSelectedObject) return;
  if (text == kPolygonModeLineStr) {
    controller_->SetPolygonModeObject(
        selected_object_->GetObjectId(),
        Controller::PolygonMode::kPolygonModeLine);
    current_polygon_mode_ = Controller::PolygonMode::kPolygonModeLine;
  } else if (text == kPolygonModeTextureStr) {
    controller_->SetPolygonModeObject(
        selected_object_->GetObjectId(),
        Controller::PolygonMode::kPolygonModeTexture);
    current_polygon_mode_ = Controller::PolygonMode::kPolygonModeTexture;
  } else if (text == kPolygonModeFillStr) {
    controller_->SetPolygonModeObject(
        selected_object_->GetObjectId(),
        Controller::PolygonMode::kPolygonModeFill);
    current_polygon_mode_ = Controller::PolygonMode::kPolygonModeFill;
  }
  controller_->Render();
}

}  // namespace s21
