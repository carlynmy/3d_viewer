// Declaration class SceneFromView

#ifndef _3D_VIEWER_MODEL_RENDERER_RENDERER_IMP_OPENGL_OPENGL_SCENE_FROM_VIEW_OPENGL_SCNENE_FROM_VIEW_H_
#define _3D_VIEWER_MODEL_RENDERER_RENDERER_IMP_OPENGL_OPENGL_SCENE_FROM_VIEW_OPENGL_SCNENE_FROM_VIEW_H_

#include "../color.h"
#include "model/color.h"
#include "model/mat4/mat4.h"
#include "model/view_scene/view_scene.h"
#include "scene.h"

namespace s21::OpenGLRenderer {

class SceneFromView : public Scene {
 public:
  using ProjectionTypes = Scene::ProjectionTypes;

  SceneFromView(const ViewScene* view_scene);
  virtual ~SceneFromView();

  Color GetBackgroundColor() const override;
  ProjectionTypes GetProjectionType() const override;
  GLboolean IsFloorShow() const override;
  GLboolean IsLightTrasser() const override;

  Mat4 GetProjectionMatrix(int width, int height) const override;
  Mat4 GetViewMatrix() const override;

 private:
  static s21::OpenGLRenderer::Color ColorToOpenGLColor(const s21::Color& color);

  const ViewScene* view_scene_;
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_RENDERER_RENDERER_IMP_OPENGL_OPENGL_SCENE_FROM_VIEW_OPENGL_SCNENE_FROM_VIEW_H_
