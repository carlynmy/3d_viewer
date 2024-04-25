#include <QApplication>

#include "controller/controller.h"
#include "controller/controller_default.h"
#include "model/model.h"
#include "view/mainwindow/mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  QApplication::setAttribute(Qt::AA_ForceRasterWidgets, false);

  s21::Model* model = new s21::Model();
  s21::Controller* controller = new s21::ControllerDefault(model);
  s21::MainWindow w(controller);
  w.setWindowTitle("3DViewer_v2.0");

  w.show();
  controller->SetWidth(w.geometry().width() - 300);
  controller->SetHeight(w.geometry().height() - 55);
  controller->Render();
  int code = a.exec();

  delete model;
  delete controller;

  return code;
}
