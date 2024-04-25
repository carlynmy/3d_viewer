#include "widgetlist.h"

#include <QHBoxLayout>
#include <QSpacerItem>

namespace s21 {

WidgetList::WidgetList(QWidget* parent) {
  scroll_area_ = new QScrollArea(this);
  scroll_area_->setGeometry(this->geometry());
  h_layout_ = new QVBoxLayout(scroll_area_);
  this->setLayout(h_layout_);
}

WidgetList::~WidgetList() {
  delete h_layout_;
  delete scroll_area_;
  for (auto iter = widget_list_.begin(); iter != widget_list_.end(); ++iter) {
    delete *iter;
  }
}

void WidgetList::AddWidget(QWidget* widget) {
  widget_list_.push_back(widget);
  h_layout_->addWidget(widget);
  widget->setParent(this);
  widget->show();
}

void WidgetList::RemoveWidget(QWidget* widget) {
  std::list<QWidget*>::iterator iter = widget_list_.begin();
  for (; iter != widget_list_.end(); ++iter) {
    if (*iter == widget) break;
  }
  delete *iter;
  widget_list_.erase(iter);
}

};  // namespace s21
