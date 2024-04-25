#ifndef _3D_VIEWER_VIEW_RENDEREDLIGHT_H_
#define _3D_VIEWER_VIEW_RENDEREDLIGHT_H_

#include <QWidget>

#include "../../controller/controller.h"

namespace Ui {
class RenderedLight;
}

namespace s21 {

class RenderedLight : public QWidget {
  Q_OBJECT

 public:
  using LightSourceId = s21::Controller::LightSourceId;

  explicit RenderedLight(QWidget *parent = nullptr);
  ~RenderedLight();

  void ChangeStyleSheetDefault() {}
  void ChangeStyleSheetSelected() {}

  void SetLightSourceId(LightSourceId id) { light_source_id_ = id; }
  void SetRotateX(float rotate_x) { rotate_x_ = rotate_x; }
  void SetRotateY(float rotate_y) { rotate_y_ = rotate_y; }
  void SetRotateZ(float rotate_z) { rotate_z_ = rotate_z; }
  void SetMoveX(float move_x) { move_x_ = move_x; }
  void SetMoveY(float move_y) { move_y_ = move_y; }
  void SetMoveZ(float move_z) { move_z_ = move_z; }
  void SetScale(float scale) { scale_ = scale; }

  LightSourceId GetLightSourceId() const { return light_source_id_; }
  float GetRotateX() const { return rotate_x_; }
  float GetRotateY() const { return rotate_y_; }
  float GetRotateZ() const { return rotate_z_; }
  float GetMoveX() const { return move_x_; }
  float GetMoveY() const { return move_y_; }
  float GetMoveZ() const { return move_z_; }
  float GetScale() const { return scale_; }

 private:
  Ui::RenderedLight *ui;

  LightSourceId light_source_id_;
  float rotate_x_ = 0;
  float rotate_y_ = 0;
  float rotate_z_ = 0;
  float move_x_ = 0;
  float move_y_ = 0;
  float move_z_ = 0;
  float scale_ = 1;
};

}  // namespace s21

#endif  // _3D_VIEWER_VIEW_RENDEREDLIGHT_H_
