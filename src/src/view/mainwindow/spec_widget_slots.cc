#include <QColorDialog>
#include <QFileDialog>
#include <QPalette>
#include <QSettings>
#include <QTime>
#include <QTimer>

#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

void MainWindow::ButtonSwitchProjectionClicked() {
  if ((ui->pb_change_projection->text()).toStdString() == kParallel) {
    controller_->SetProjectionType(
        Controller::ProjectionTypes::kPrTypeParallel);
    ui->pb_change_projection->setText(QString::fromStdString(kCentral));
  } else {
    controller_->SetProjectionType(Controller::ProjectionTypes::kPrTypeCentral);
    ui->pb_change_projection->setText(QString::fromStdString(kParallel));
  }
  controller_->Render();
}

void MainWindow::ButtonChangeColorBackgroundClicked() {
  QColorDialog::ColorDialogOptions option = QColorDialog::ShowAlphaChannel;
  QColor input_color =
      QColorDialog::getColor(Qt::white, nullptr, "Изменить цвет фона", option);
  if (!input_color.isValid()) return;
  int r, g, b, a;
  input_color.getRgb(&r, &g, &b, &a);
  controller_->SetBackgroundColor(Color(r, g, b, a));

  QString color = "border: 5px solid rgb(" + QString::number(r) + ", " +
                  QString::number(g) + ", " + QString::number(b) + ");" +
                  "border - radius : 7px;" + "background-color: rgb(" +
                  QString::number(r) + ", " + QString::number(g) + ", " +
                  QString::number(b) + ");";
  ui->pb_change_color_back->setStyleSheet(color);

  controller_->Render();
}

QString MainWindow::CreateNameForFile(FileType type) {
  QString path;

  switch (type) {
    case FileType::kJPEG:
      path =
          QFileDialog::getExistingDirectory(this, tr("Сохранить .jpeg"), "~");
      break;

    case FileType::kBMP:
      path = QFileDialog::getExistingDirectory(this, tr("Сохранить .bmp"), "~");
      break;

    case FileType::kGIF:
      path = QFileDialog::getExistingDirectory(this, tr("Сохранить .gif"), "~");
      break;
  }

  QTime current_time = QTime::currentTime();
  QString current_time_str = current_time.toString("hh:mm:ss");

  path.append("/" + current_time_str);

  switch (type) {
    case FileType::kJPEG:
      path.append(".jpeg");
      break;

    case FileType::kBMP:
      path.append(".bmp");
      break;

    case FileType::kGIF:
      path.append(".gif");
      break;
  }

  return path;
}

void MainWindow::ButtonSaveJPEGClicked() {
  QString path = CreateNameForFile(FileType::kJPEG);

  ReturnCode code =
      controller_->SaveImage(path.toStdString(), Controller::ImageType::kJPEG);

  PrintImageError(code);
}

void MainWindow::ButtonSaveBMPClicked() {
  QString path = CreateNameForFile(FileType::kBMP);

  ReturnCode code =
      controller_->SaveImage(path.toStdString(), Controller::ImageType::kBMP);

  PrintImageError(code);
}

void MainWindow::ClearInfoLabel() {
  ui->le_info->setText("");
  timer_.stop();
}

void MainWindow::PrintImageError(ReturnCode code) {
  switch (code) {
    case ReturnCode::kCodeInvData:
      ui->le_info->setText("Неверные данные");
      break;

    case ReturnCode::kCodeOk:
      ui->le_info->setText("Изображение сохранено");
      break;

    default:
      ui->le_info->setText("Неизвестная ошибка");
      break;
  }

  timer_.start(5000);
}

void MainWindow::PrintGifError(ReturnCode code) {
  switch (code) {
    case ReturnCode::kCodeFileDoesntFound:
      ui->le_info->setText("Файл потерян");
      break;

    case ReturnCode::kCodeInvDataOrFileLost:
      ui->le_info->setText("Файл потерян или данные некорректны");
      break;
    default:
      break;
  }
}

void MainWindow::ButtonSaveGIFClicked() {
  if (is_gif_started_) return;

  QString path = CreateNameForFile(FileType::kGIF);

  ReturnCode code = controller_->StartGif(path.toStdString());

  switch (code) {
    case ReturnCode::kCodeOk:
      is_gif_started_ = true;
      gif_timer_.start(100);
      ui->le_info->setText("Gif записывается");
      break;

    default:
      PrintGifError(code);
      timer_.start(5000);
      break;
  }
}

void MainWindow::AddFrameToGif() {
  ReturnCode code;
  if (is_gif_started_) code = controller_->AddFrame();

  ++count_frame_;

  if (count_frame_ < 50 && code == ReturnCode::kCodeOk && is_gif_started_) {
    gif_timer_.start(100);
    return;
  }

  code = controller_->EndGif();

  switch (code) {
    case ReturnCode::kCodeOk:
      ui->le_info->setText("Gif записан");
      break;

    default:
      PrintGifError(code);
      break;
  }

  gif_timer_.stop();
  count_frame_ = 0;
  is_gif_started_ = false;
  timer_.start(5000);
}

void MainWindow::SaveSettings() {
  QSettings settings("soft", "3d viewer");

  settings.setValue("projection", ui->pb_change_projection->text());

  QColor back_color = ui->pb_change_color_back->palette().button().color();
  settings.setValue("back_color", back_color);

  settings.setValue("floor", ui->cb_floor->isChecked());
  settings.setValue("file_info", ui->cb_file_info->isChecked());
  settings.setValue("axes", ui->cb_axes->isChecked());
  settings.setValue("use_prev_obj_settings",
                    ui->cb_use_prev_obj_settings->isChecked());

  settings.setValue("line_type_solid", ui->rb_solid_line->isChecked());
  settings.setValue("line_type_dotted", ui->rb_dotted_line->isChecked());
  QColor line_color = ui->pb_change_lines_color->palette().button().color();
  settings.setValue("line_color", line_color);
  settings.setValue("line_size", ui->le_line_thickness->text());

  settings.setValue("vertex_type", ui->com_box_type_vertex->currentText());
  QColor vertex_color = ui->pb_change_vertex_color->palette().button().color();
  settings.setValue("vertex_color", vertex_color);
  settings.setValue("vertex_size", ui->le_vertex_size->text());
}

void MainWindow::LoadSettings() {
  QSettings settings("soft", "3d viewer");

  LoadProjection(settings);
  LoadBackgroundColor(settings);

  bool floor = settings.value("floor").toBool();
  ui->cb_floor->setChecked(floor);
  controller_->SetShowFloor(floor);

  bool file_info = settings.value("file_info").toBool();
  ui->cb_file_info->setChecked(file_info);

  bool axes = settings.value("axes").toBool();
  ui->cb_axes->setChecked(axes);
  controller_->SetShowAxes(axes);

  bool use_prev_obj_settings = settings.value("use_prev_obj_settings").toBool();
  ui->cb_use_prev_obj_settings->setChecked(use_prev_obj_settings);
}

void MainWindow::LoadBackgroundColor(const QSettings& settings) {
  QColor back_color = settings.value("back_color").value<QColor>();
  int r, g, b, a;
  back_color.getRgb(&r, &g, &b, &a);
  controller_->SetBackgroundColor(Color(r, g, b, a));

  QString color = "border: 5px solid rgb(" + QString::number(r) + ", " +
                  QString::number(g) + ", " + QString::number(b) + ");" +
                  "border - radius : 7px;" + "background-color: rgb(" +
                  QString::number(r) + ", " + QString::number(g) + ", " +
                  QString::number(b) + ");";
  ui->pb_change_color_back->setStyleSheet(color);
}

void MainWindow::LoadProjection(const QSettings& settings) {
  QString projection = settings.value("projection").toString();
  if (!projection.isEmpty()) {
    if (projection.toStdString() == kParallel) {
      controller_->SetProjectionType(
          Controller::ProjectionTypes::kPrTypeCentral);
      ui->pb_change_projection->setText(QString::fromStdString(kParallel));
    } else {
      controller_->SetProjectionType(
          Controller::ProjectionTypes::kPrTypeParallel);
      ui->pb_change_projection->setText(QString::fromStdString(kCentral));
    }
  }
}

void MainWindow::CheckBoxShowFloorStateChanged() {
  controller_->SetShowFloor(ui->cb_floor->isChecked());
  controller_->Render();
}

void MainWindow::CheckBoxShowAxesStateChanged() {
  controller_->SetShowAxes(ui->cb_axes->isChecked());
  controller_->Render();
}

void MainWindow::UsePrevObjectSettings(RenderedObject* object_id) {
  QSettings settings("soft", "3d viewer");

  LoadVertexSettings(settings, object_id);
  LoadLineSettings(settings, object_id);
}

void MainWindow::LoadVertexSettings(const QSettings& settings,
                                    RenderedObject* object_id) {
  QString vertex_type = settings.value("vertex_type").toString();
  if (vertex_type == kVertexTypeNoneStr) {
    object_id->SetVertexType(RenderedObject::VertexType::kVertexTypeNone);
    controller_->SetVertexTypeObject(object_id->GetObjectId(),
                                     Controller::VertexTypes::kVertexTypeNone);
  } else if (vertex_type == kVertexTypeCircleStr) {
    object_id->SetVertexType(RenderedObject::VertexType::kVertexTypeCircle);
    controller_->SetVertexTypeObject(
        object_id->GetObjectId(), Controller::VertexTypes::kVertexTypeCircle);
  } else if (vertex_type == kVertexTypeSquareStr) {
    object_id->SetVertexType(RenderedObject::VertexType::kVertexTypeSquare);
    controller_->SetVertexTypeObject(
        object_id->GetObjectId(), Controller::VertexTypes::kVertexTypeSquare);
  }

  QColor vertex_color = settings.value("vertex_color").value<QColor>();
  object_id->SetVertexColor(vertex_color);
  int r, g, b, a;
  vertex_color.getRgb(&r, &g, &b, &a);
  controller_->SetVertexColorObject(object_id->GetObjectId(),
                                    Color(r, g, b, a));

  QString vertex_size = settings.value("vertex_size").toString();
  object_id->SetVertexSize(vertex_size.toFloat());
  controller_->SetVertexSizeObject(object_id->GetObjectId(),
                                   vertex_size.toFloat());
}

void MainWindow::LoadLineSettings(const QSettings& settings,
                                  RenderedObject* object_id) {
  bool line_type_solid = settings.value("line_type_solid").toBool();
  if (line_type_solid) {
    object_id->SetLineType(RenderedObject::LineType::kLineTypeSolid);
    controller_->SetLineTypeObject(object_id->GetObjectId(),
                                   Controller::LineTypes::kLineTypeSolid);
  } else {
    object_id->SetLineType(RenderedObject::LineType::kLineTypeDotted);
    controller_->SetLineTypeObject(object_id->GetObjectId(),
                                   Controller::LineTypes::kLineTypeDotted);
  }

  QColor line_color = settings.value("line_color").value<QColor>();
  object_id->SetLineColor(line_color);
  int r, g, b, a;
  line_color.getRgb(&r, &g, &b, &a);
  controller_->SetLineColorObject(object_id->GetObjectId(), Color(r, g, b, a));

  QString line_size = settings.value("line_size").toString();
  object_id->SetLineSize(line_size.toFloat());
  controller_->SetLineSizeObject(object_id->GetObjectId(), line_size.toFloat());
}

}  // namespace s21
