#ifndef _3D_VIEWER_VIEW_WIDGETLIST_H_
#define _3D_VIEWER_VIEW_WIDGETLIST_H_

#include <QObject>
#include <QScrollArea>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QWidget>

namespace s21 {
class WidgetList : public QWidget {
  Q_OBJECT
 public:
  explicit WidgetList(QWidget* parent = nullptr);
  ~WidgetList();

  void AddWidget(QWidget* widget);
  void RemoveWidget(QWidget* widget);

 private:
  std::list<QWidget*> widget_list_;
  QScrollArea* scroll_area_;
  QVBoxLayout* h_layout_;
};

}  // namespace s21

#endif  // _3D_VIEWER_VIEW_WIDGETLIST_H_
