#include "renderedobject.h"

#include <QPainter>
#include <QStyle>
#include <QStyleOption>
#include <iostream>

#include "ui_renderedobject.h"

namespace s21 {

RenderedObject::RenderedObject(QWidget* parent, std::string& filename,
                               ObjectId id)
    : QWidget(parent), ui_(new Ui::RenderedObject), id_(id) {
  ui_->setupUi(this);
  ui_->le_filename->setText(QString::fromStdString(filename));
  connect(ui_->pb_remove, &QPushButton::clicked, this,
          &RenderedObject::ButtonRemoveObjectClicked);
  connect(ui_->pb_show_hide, &QPushButton::clicked, this,
          &RenderedObject::ButtonHideObjectClicked);
  installEventFilter(this);
  setMouseTracking(true);
  is_hidden_ = false;
  is_moved_ = true;
}

RenderedObject::~RenderedObject() { delete ui_; }

bool RenderedObject::eventFilter(QObject* obj, QEvent* ev) {
  if (ev->type() == QEvent::MouseButtonPress) {
    emit ObjectSelected(this);
    return true;
  }
  if (this->underMouse() && is_moved_) {
    emit MouseMovedOnWidget(this);
    is_moved_ = false;
    return true;
  } else if (!this->underMouse() && is_moved_ == false) {
    emit MouseWentBehindTheWidget();
    is_moved_ = true;
    return true;
  }
  return false;
}

void RenderedObject::ChangeStyleSheetSelected() {
  this->setStyleSheet("background: rgba(69, 9, 187, 0.6);");
}

void RenderedObject::ChangeStyleSheetDefault() {
  this->setStyleSheet("background: rgba(0, 0, 0, 0);");
}

void RenderedObject::paintEvent(QPaintEvent* ev) {
  QStyleOption opt;
  opt.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void RenderedObject::ButtonRemoveObjectClicked() {
  deleteLater();
  emit ObjectDeleted(this);
}

void RenderedObject::ButtonHideObjectClicked() {
  if (is_hidden_) {
    is_hidden_ = false;
    ui_->pb_show_hide->setText("h");
  } else {
    is_hidden_ = true;
    ui_->pb_show_hide->setText("s");
  }
  emit ObjectShowHide(this, is_hidden_);
}

void RenderedObject::SetObjectName(const QString& object_name) {
  ui_->le_filename->setText(object_name);
}

QString RenderedObject::GetObjectName() const {
  return ui_->le_filename->text();
}

}  // namespace s21
