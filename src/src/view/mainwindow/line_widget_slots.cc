#include <QColorDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

void MainWindow::RadioButtonLinesSolidToggled() {
  if (selected_type_ != SelectedType::kSelectedObject) return;
  if (ui->rb_solid_line->isChecked()) {
    current_line_type_ = Controller::LineTypes::kLineTypeSolid;
    selected_object_->SetLineType(Controller::LineTypes::kLineTypeSolid);
    controller_->SetLineTypeObject(selected_object_->GetObjectId(),
                                   Controller::LineTypes::kLineTypeSolid);
    controller_->Render();
  }
}

void MainWindow::RadioButtonLinesDottedToggled() {
  if (selected_type_ != SelectedType::kSelectedObject) return;
  if (ui->rb_dotted_line->isChecked()) {
    current_line_type_ = Controller::LineTypes::kLineTypeDotted;
    selected_object_->SetLineType(Controller::LineTypes::kLineTypeDotted);
    controller_->SetLineTypeObject(selected_object_->GetObjectId(),
                                   Controller::LineTypes::kLineTypeDotted);
    controller_->Render();
  }
}

void MainWindow::ButtonChangeColorLinesClicked() {
  if (selected_type_ != SelectedType::kSelectedObject) return;

  QColorDialog::ColorDialogOptions option = QColorDialog::ShowAlphaChannel;
  QColor input_color =
      QColorDialog::getColor(Qt::white, nullptr, "Изменить цвет линий", option);
  if (!input_color.isValid()) return;

  current_line_color_ = input_color;

  int r, g, b, a;
  input_color.getRgb(&r, &g, &b, &a);

  ui->pb_change_lines_color->setStyleSheet(GetColorStyleString(input_color));

  controller_->SetLineColorObject(selected_object_->GetObjectId(),
                                  Color(r, g, b, a));
  controller_->Render();
}

void MainWindow::LineEditSizeLineChanged() {
  if (selected_type_ != SelectedType::kSelectedObject) return;
  float size = StringToFloat(ui->le_line_thickness->text());
  if (std::isnan(size)) return;
  current_line_size_ = size;
  controller_->SetLineSizeObject(selected_object_->GetObjectId(), size);
  controller_->Render();
}

}  // namespace s21
