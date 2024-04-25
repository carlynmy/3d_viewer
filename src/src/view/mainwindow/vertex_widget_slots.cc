#include <QColorDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

void MainWindow::ComboBoxVertexTypeChanged() {
  if (selected_type_ != SelectedType::kSelectedObject) return;
  if (ui->com_box_type_vertex->currentText() == kVertexTypeNoneStr) {
    current_vertex_type_ = Controller::VertexTypes::kVertexTypeNone;
    controller_->SetVertexTypeObject(selected_object_->GetObjectId(),
                                     Controller::VertexTypes::kVertexTypeNone);
  } else if (ui->com_box_type_vertex->currentText() == kVertexTypeCircleStr) {
    current_vertex_type_ = Controller::VertexTypes::kVertexTypeCircle;
    controller_->SetVertexTypeObject(
        selected_object_->GetObjectId(),
        Controller::VertexTypes::kVertexTypeCircle);
  } else if (ui->com_box_type_vertex->currentText() == kVertexTypeSquareStr) {
    current_vertex_type_ = Controller::VertexTypes::kVertexTypeSquare;
    controller_->SetVertexTypeObject(
        selected_object_->GetObjectId(),
        Controller::VertexTypes::kVertexTypeSquare);
  }
  controller_->Render();
}

void MainWindow::ButtonChangeColorVertexClicked() {
  if (selected_type_ != SelectedType::kSelectedObject) return;
  QColorDialog::ColorDialogOptions option = QColorDialog::ShowAlphaChannel;
  QColor input_color = QColorDialog::getColor(Qt::white, nullptr,
                                              "Изменить цвет вершин", option);
  if (!input_color.isValid()) return;

  current_vertex_color_ = input_color;

  int r, g, b, a;
  input_color.getRgb(&r, &g, &b, &a);

  ui->pb_change_vertex_color->setStyleSheet(GetColorStyleString(input_color));

  controller_->SetVertexColorObject(selected_object_->GetObjectId(),
                                    Color(r, g, b, a));
  controller_->Render();
}

void MainWindow::LineEditSizeVertexChanged() {
  if (selected_type_ != SelectedType::kSelectedObject) return;
  float size = StringToFloat(ui->le_vertex_size->text());
  if (std::isnan(size)) return;
  current_vertex_size_ = size;
  controller_->SetVertexSizeObject(selected_object_->GetObjectId(), size);
  controller_->Render();
}

}  // namespace s21
