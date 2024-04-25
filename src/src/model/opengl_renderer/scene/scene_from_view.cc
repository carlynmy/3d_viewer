// Implementation class SceneFromView

#include "scene_from_view.h"

#include <cmath>

#include "../color.h"
#include "../object/object_from_view.h"
#include "model/color.h"
#include "model/view_object/view_object.h"
#include "model/view_scene/view_scene.h"
#include "scene.h"

namespace s21::OpenGLRenderer {

SceneFromView::SceneFromView(const ViewScene* view_scene) {
  view_scene_ = view_scene;

  auto i = view_scene->BeginObjects();
  for (; i != view_scene->EndObjects(); ++i) {
    if (i->IsHide()) continue;
    Object* opengl_object = new ObjectFromView(&*i);
    GetObjects().push_back(opengl_object);
  }
}

SceneFromView::~SceneFromView() {}

s21::OpenGLRenderer::Color SceneFromView::GetBackgroundColor() const {
  return ColorToOpenGLColor(view_scene_->GetBackgroundColor());
}

SceneFromView::ProjectionTypes SceneFromView::GetProjectionType() const {
  ViewScene::ProjectionTypes vs_type = view_scene_->GetProjectionType();

  Scene::ProjectionTypes type = Scene::kPrTypeCentral;
  switch (vs_type) {
    case ViewScene::kPrTypeParallel:
      type = Scene::kPrTypeParallel;
      break;

    default:
      break;
  }

  return type;
}

GLboolean SceneFromView::IsFloorShow() const {
  bool answer = view_scene_->IsFloorShow();
  return static_cast<GLboolean>(answer);
}

GLboolean SceneFromView::IsLightTrasser() const {
  bool answer = view_scene_->IsLightTrasser();
  return static_cast<GLboolean>(answer);
}

s21::OpenGLRenderer::Color SceneFromView::ColorToOpenGLColor(
    const s21::Color& color) {
  GLclampf r = static_cast<GLclampf>(static_cast<float>(color.GetR()) / 255.0);
  GLclampf g = static_cast<GLclampf>(static_cast<float>(color.GetG()) / 255.0);
  GLclampf b = static_cast<GLclampf>(static_cast<float>(color.GetB()) / 255.0);
  GLclampf a = static_cast<GLclampf>(static_cast<float>(color.GetA()) / 255.0);

  Color opengl_color = Color(r, g, b, a);
  return opengl_color;
}

Mat4 SceneFromView::GetProjectionMatrix(int width, int height) const {
  return view_scene_->GetProjectionMatrix();
}

Mat4 SceneFromView::GetViewMatrix() const {
  return view_scene_->GetViewMatrix();
}

}  // namespace s21::OpenGLRenderer
