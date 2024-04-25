// Declaration class ViewScene

#ifndef _3D_VIEWER_MODEL_VIEW_SCENE_VIEW_SCENE_H_
#define _3D_VIEWER_MODEL_VIEW_SCENE_VIEW_SCENE_H_

#include <list>

#include "../color.h"
#include "model/light_source/light_source.h"
#include "model/mat4/mat4.h"
#include "model/view_object/view_object.h"

namespace s21 {

class ViewScene {
 public:
  using Objects = std::list<ViewObject>;
  using LightSources = std::list<LightSource>;
  using AxisId = ViewObject::AxisId;

  enum ProjectionTypes { kPrTypeCentral, kPrTypeParallel };

  ViewScene();
  virtual ~ViewScene();

  void Rotate(AxisId axis, float value);
  void Move(AxisId axis, float value);
  void Scale(float value);

  void SetBackgroundColor(const Color& color);

  const Color& GetBackgroundColor() const;

  void SetProjectionType(ProjectionTypes type);

  ProjectionTypes GetProjectionType() const;

  void SetShowFloor(bool answer);
  bool IsFloorShow() const;

  void SetShowAxes(bool answer);

  void SetLightTrasser(bool answer);
  bool IsLightTrasser() const;

  Mat4 GetViewMatrix() const;
  Mat4 GetProjectionMatrix() const;

  void SetWidth(int width);
  void SetHeight(int width);

  /// @brief Add object to scene
  /// @return pointer to new object
  ViewObject* AddObject(const ViewObject& object);

  /// @brief Add object to scene
  /// @return pointer to new object
  ViewObject* AddObject(ViewObject&& object);

  /// @brief Add light source to scene
  /// @return pointer to new light source
  LightSource* AddLightSource(const LightSource& light_source);

  /// @brief Add light source to scene
  /// @return pointer to new light source
  LightSource* AddLightSource(LightSource&& light_source);

  /// @brief Remove object from scene
  /// @param object pointer to object in this scene
  /// @warning Undefined behavior if pointer invalid
  void RemoveObject(const ViewObject* object);

  /// @brief Remove light source from scene
  /// @param light_source pointer to light source in this scene
  /// @warning Undefined behavior if pointer invalid
  void RemoveLightSource(const LightSource* light_source);

  Objects::iterator BeginObjects();
  Objects::iterator EndObjects();
  LightSources::iterator BeginLightSources();
  LightSources::iterator EndLightSources();

  Objects::const_iterator BeginObjects() const;
  Objects::const_iterator EndObjects() const;
  LightSources::const_iterator BeginLightSources() const;
  LightSources::const_iterator EndLightSources() const;

 private:
  void CreateAxisObjects();
  void CreateFloorObject();

  Objects objects_;
  LightSources light_sources_;

  Color background_color_;
  ProjectionTypes projection_type_;

  bool show_floor_;
  bool light_trasser_;

  float move_x_;
  float move_y_;
  float move_z_;
  float rotate_x_;
  float rotate_y_;
  float rotate_z_;
  float scale_;

  int width_;
  int height_;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_VIEW_SCENE_VIEW_SCENE_H_
