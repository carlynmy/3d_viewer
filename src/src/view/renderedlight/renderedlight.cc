#include "renderedlight.h"

#include "ui_renderedlight.h"

namespace s21 {

RenderedLight::RenderedLight(QWidget *parent)
    : QWidget(parent), ui(new Ui::RenderedLight) {
  ui->setupUi(this);
}

RenderedLight::~RenderedLight() { delete ui; }

}  // namespace s21
