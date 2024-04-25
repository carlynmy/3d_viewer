#ifndef _3D_VIEWER_VIEW_RENDEREDOBJECT_H_
#define _3D_VIEWER_VIEW_RENDEREDOBJECT_H_

#include <QColor>
#include <QPaintEvent>
#include <QWidget>
#include <string>

#include "../../controller/controller.h"

namespace Ui {
class RenderedObject;
}

namespace s21 {

class RenderedObject : public QWidget {
  Q_OBJECT

 public:
  enum VertexType { kVertexTypeNone = 0, kVertexTypeCircle, kVertexTypeSquare };
  enum PolygonMode { kPolygonModeTexture, kPolygonModeLine, kPolygonModeFill };
  enum LineType {
    kLineTypeSolid = 0,
    kLineTypeDotted,
  };

  using ObjectId = s21::Controller::ObjectId;

  explicit RenderedObject(QWidget* parent, std::string& filename, ObjectId id);
  ~RenderedObject();
  void ChangeStyleSheetDefault();
  void ChangeStyleSheetSelected();

  void SetObjectId(ObjectId id) { id_ = id; }
  void SetRotateX(float rotate_x) { rotate_x_ = rotate_x; }
  void SetRotateY(float rotate_y) { rotate_y_ = rotate_y; }
  void SetRotateZ(float rotate_z) { rotate_z_ = rotate_z; }
  void SetMoveX(float move_x) { move_x_ = move_x; }
  void SetMoveY(float move_y) { move_y_ = move_y; }
  void SetMoveZ(float move_z) { move_z_ = move_z; }
  void SetScale(float scale) { scale_ = scale; }
  void SetLineType(uint8_t line_type) { line_type_ = line_type; }
  void SetLineSize(float line_size) { line_size_ = line_size; }
  void SetLineColor(const QColor& color) { line_color_ = color; }
  void SetVertexType(uint8_t vertex_type) { vertex_type_ = vertex_type; }
  void SetVertexSize(float vertex_size) { vertex_size_ = vertex_size; }
  void SetVertexColor(const QColor& color) { vertex_color_ = color; }
  void SetPolygonMode(PolygonMode type) { polygon_mode_ = type; };
  void SetObjectName(const QString& object_name);

  ObjectId GetObjectId() const { return id_; }
  float GetRotateX() const { return rotate_x_; }
  float GetRotateY() const { return rotate_y_; }
  float GetRotateZ() const { return rotate_z_; }
  float GetMoveX() const { return move_x_; }
  float GetMoveY() const { return move_y_; }
  float GetMoveZ() const { return move_z_; }
  float GetScale() const { return scale_; }
  uint8_t GetLineType() const { return line_type_; }
  float GetLineSize() const { return line_size_; }
  QColor GetLineColor() const { return line_color_; }
  uint8_t GetVertexType() const { return vertex_type_; }
  float GetVertexSize() const { return vertex_size_; }
  QColor GetVertexColor() const { return vertex_color_; }
  PolygonMode GetPolygonMode() const { return polygon_mode_; }
  QString GetObjectName() const;

 signals:
  void ObjectSelected(RenderedObject* obj);
  void ObjectShowHide(RenderedObject* obj, bool state);
  void ObjectDeleted(RenderedObject* obj);
  void MouseMovedOnWidget(RenderedObject* obj);
  void MouseWentBehindTheWidget();

 private slots:
  void ButtonRemoveObjectClicked();
  void ButtonHideObjectClicked();

 private:
  bool eventFilter(QObject* obj, QEvent* ev) override;
  void paintEvent(QPaintEvent* ev) override;
  Ui::RenderedObject* ui_;

  ObjectId id_;
  float rotate_x_ = 0;
  float rotate_y_ = 0;
  float rotate_z_ = 0;
  float move_x_ = 0;
  float move_y_ = 0;
  float move_z_ = 0;
  float scale_ = 1;
  uint8_t vertex_type_ = kVertexTypeNone;
  float vertex_size_ = 1;
  uint8_t line_type_ = kLineTypeSolid;
  float line_size_ = 1;
  PolygonMode polygon_mode_ = PolygonMode::kPolygonModeLine;
  QColor vertex_color_;
  QColor line_color_;

  bool is_hidden_;
  bool is_moved_;
};

}  // namespace s21

#endif  // _3D_VIEWER_VIEW_RENDEREDOBJECT_H_
