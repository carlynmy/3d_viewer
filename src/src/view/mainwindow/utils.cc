#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

float MainWindow::StringToFloat(const QString& qstr) {
  std::string str = qstr.toStdString();

  try {
    return std::stof(str);
  } catch (...) {
    ;
  }

  return NAN;
}

QString MainWindow::GetColorStyleString(QColor color) const {
  int r, g, b;
  color.getRgb(&r, &g, &b);
  QString str_color = "border: 5px solid rgb(" + QString::number(r) + ", " +
                      QString::number(g) + ", " + QString::number(b) + ");" +
                      "border-radius : 3px;" + "background-color: rgb(" +
                      QString::number(r) + ", " + QString::number(g) + ", " +
                      QString::number(b) + ");";
  return str_color;
}

}  // namespace s21
