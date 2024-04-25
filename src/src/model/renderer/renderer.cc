// Implementation class Renderer

#include "renderer.h"

#include "../canvas/canvas.h"
#include "../renderer_imp/renderer_imp.h"
#include "../renderer_imp_opengl/renderer_imp_opengl.h"
#include "../view_scene/view_scene.h"

namespace s21 {

Renderer::Renderer() { renderer_imp_ = new RendererImpOpenGL(); }

Renderer::~Renderer() { delete renderer_imp_; }

void Renderer::Render(const ViewScene* scene, Canvas* canvas) {
  return renderer_imp_->Render(scene, canvas);
}

std::vector<uint8_t> Renderer::GetPixels(const ViewScene* scene, Canvas* canvas,
                                         int width, int heigth) {
  return renderer_imp_->GetPixels(scene, canvas, width, heigth);
}

}  // namespace s21
