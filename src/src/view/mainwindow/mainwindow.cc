#include "mainwindow.h"

#include <QAction>
#include <QCheckBox>
#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QRadioButton>
#include <QSlider>
#include <cmath>
#include <iostream>
#include <locale>

#include "../canvas/qt_opengl_canvas.h"
#include "../renderedlight/renderedlight.h"
#include "../renderedobject/renderedobject.h"
#include "ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(s21::Controller* controller, QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  controller_ = controller;
  selected_type_ = kSelectedScene;
  selected_object_ = nullptr;
  setlocale(LC_ALL, "C");
  ui->setupUi(this);
  InitScrollArea();
  InitSliders();
  InitLineEdit();
  size_gl_widget_ = ui->openGLWidget->size();
  InitCanvas();
  LoadSettings();
  UiConnect();
  installEventFilter(this);
}

MainWindow::~MainWindow() {
  delete ui;
  delete canvas_;
}

void MainWindow::InitCanvas() {
  canvas_ = new QTOpenGLCanvas();
  canvas_->SetOpenGLWidget(ui->openGLWidget);
  controller_->SetCanvas(canvas_);
  controller_->SetWidth(ui->openGLWidget->width());
  controller_->SetHeight(ui->openGLWidget->height());
}

void MainWindow::ButtonAddObjectsClicked() {
  QString qpath = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "~",
                                               tr("*.obj (*.obj)"));
  std::string path = qpath.toStdString();

  ObjectId object_id;
  ReturnCode code = controller_->AddObject(path, object_id);
  if (code != ReturnCode::kCodeOk) {
    PrintErrorForNotAddedObject(code);
    return;
  }

  std::string filename = controller_->GetNameObject(object_id);
  RenderedObject* obj = new RenderedObject(this, filename, object_id);

  RenderedObjectConnects(obj);

  ui->widget_list->AddWidget(obj);

  if (ui->cb_use_prev_obj_settings->isChecked())
    UsePrevObjectSettings(obj);
  else
    UseDefaultObjectSettings(obj);

  controller_->Render();
}

void MainWindow::PrintErrorForNotAddedObject(ReturnCode code) {
  switch (code) {
    case Controller::ReturnCode::kCodeInvFilename:
      ui->le_info->setText("Неверное имя файла");
      break;

    case Controller::ReturnCode::kCodeInvData:
      ui->le_info->setText("Неверные данные в файле");
      break;

    default:
      break;
  }
  timer_.start(5000);
}

void MainWindow::UseDefaultObjectSettings(RenderedObject* object_id) {
  controller_->SetLineTypeObject(object_id->GetObjectId(),
                                 Controller::LineTypes::kLineTypeSolid);
  controller_->SetLineSizeObject(object_id->GetObjectId(), 3);
  controller_->SetLineColorObject(object_id->GetObjectId(),
                                  Color(92, 7, 245, 255));

  object_id->SetLineType(Controller::LineTypes::kLineTypeSolid);
  object_id->SetLineSize(3);
  object_id->SetLineColor(QColor(92, 7, 245));

  controller_->SetVertexTypeObject(object_id->GetObjectId(),
                                   Controller::VertexTypes::kVertexTypeCircle);
  controller_->SetVertexSizeObject(object_id->GetObjectId(), 8);
  controller_->SetVertexColorObject(object_id->GetObjectId(),
                                    Color(255, 148, 25, 255));

  object_id->SetVertexType(Controller::VertexTypes::kVertexTypeCircle);
  object_id->SetVertexSize(8);
  object_id->SetVertexColor(QColor(255, 148, 25));
}

void MainWindow::ButtonCloneObjectClicked() {
  if (selected_type_ != SelectedType::kSelectedObject) return;

  ObjectId object_id;
  controller_->CloneObject(selected_object_->GetObjectId(), object_id);

  QString obj_name = selected_object_->GetObjectName();
  std::string obj_name_new = obj_name.toStdString() + " copy";
  RenderedObject* obj = new RenderedObject(this, obj_name_new, object_id);

  RenderedObjectConnects(obj);

  ui->widget_list->AddWidget(obj);

  UseClonedObjectSettings(obj);
  controller_->Render();
}

void MainWindow::UseClonedObjectSettings(RenderedObject* object) {
  object->SetLineColor(current_line_color_);
  object->SetLineSize(current_line_size_);
  object->SetLineType(current_line_type_);

  int r, g, b, a;
  object->GetLineColor().getRgb(&r, &g, &b, &a);
  controller_->SetLineColorObject(object->GetObjectId(), Color(r, g, b, a));
  controller_->SetLineSizeObject(object->GetObjectId(), object->GetLineSize());
  switch (object->GetLineType()) {
    case Controller::LineTypes::kLineTypeDotted:
      controller_->SetLineTypeObject(object->GetObjectId(),
                                     Controller::LineTypes::kLineTypeDotted);
      break;

    case Controller::LineTypes::kLineTypeSolid:
      controller_->SetLineTypeObject(object->GetObjectId(),
                                     Controller::LineTypes::kLineTypeSolid);
      break;

    default:
      break;
  }

  object->SetVertexColor(current_vertex_color_);
  object->SetVertexSize(current_vertex_size_);
  object->SetVertexType(current_vertex_type_);

  object->GetVertexColor().getRgb(&r, &g, &b, &a);
  controller_->SetVertexColorObject(object->GetObjectId(), Color(r, g, b, a));
  controller_->SetVertexSizeObject(object->GetObjectId(),
                                   object->GetVertexSize());
  switch (object->GetVertexType()) {
    case Controller::VertexTypes::kVertexTypeNone:
      controller_->SetVertexTypeObject(
          object->GetObjectId(), Controller::VertexTypes::kVertexTypeNone);
      break;

    case Controller::VertexTypes::kVertexTypeCircle:
      controller_->SetVertexTypeObject(
          object->GetObjectId(), Controller::VertexTypes::kVertexTypeCircle);
      break;

    case Controller::VertexTypes::kVertexTypeSquare:
      controller_->SetVertexTypeObject(
          object->GetObjectId(), Controller::VertexTypes::kVertexTypeSquare);
      break;

    default:
      break;
  }
}

void MainWindow::ButtonAddLightClicked() {
  RenderedLight* light = new RenderedLight();
  ui->widget_list->AddWidget(light);
}

void MainWindow::ButtonsRemoveObjectClicked(RenderedObject* obj) {
  controller_->RemoveObject(obj->GetObjectId());
  ui->widget_list->RemoveWidget(obj);
  DeleteObjectInfoCalled();
  SelectScene();
  UpdatePrevSelected();
  controller_->Render();
}

void MainWindow::ShowHideObjectCalled(RenderedObject* obj, bool state) {
  controller_->HideObject(obj->GetObjectId(), state);
  controller_->Render();
}

void MainWindow::ShowNumberOfVerticesEdgesCalled(RenderedObject* obj) {
  if (!ui->cb_file_info->isChecked()) return;

  info_label_ = new QLabel();

  size_t num_ov_vertices = controller_->GetVerticesCount(obj->GetObjectId());
  size_t num_of_edges = controller_->GetEdgesCount(obj->GetObjectId());

  std::string num_ov_vertices_str = std::to_string(num_ov_vertices);
  std::string num_of_edges_str = std::to_string(num_of_edges);

  QString res_str =
      "Количество вершин: " + QString::fromStdString(num_ov_vertices_str) +
      "\n" + "Количество ребер: " + QString::fromStdString(num_of_edges_str) +
      "\n";

  info_label_->setText(res_str);

  QString obj_name =
      QString::fromStdString(controller_->GetNameObject(obj->GetObjectId()));
  info_label_->setWindowTitle(obj_name);

  QRect main_window_geometry = this->geometry();
  QRect geometry = ui->openGLWidget->geometry();
  int x = main_window_geometry.x() + geometry.x() + geometry.width() - 250;
  int y = main_window_geometry.y() + geometry.y() + 100;
  info_label_->setGeometry(x, y, 250, 50);

  info_label_->show();
}

void MainWindow::DeleteObjectInfoCalled() {
  if (info_label_) {
    info_label_->deleteLater();
    delete info_label_;
    info_label_ = nullptr;
  }
}

void MainWindow::resizeEvent(QResizeEvent* event) {
  is_gif_started_ = false;
  if (ui->openGLWidget->size() != size_gl_widget_) {
    QMainWindow::resizeEvent(event);
    size_gl_widget_ = ui->openGLWidget->size();
    controller_->SetWidth(ui->openGLWidget->width());
    controller_->SetHeight(ui->openGLWidget->height());
    controller_->Render();
  }
}

void MainWindow::closeEvent(QCloseEvent* event) { SaveSettings(); }

}  // namespace s21
