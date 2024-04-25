// Implementation class RendererImpOpenGL

#include "renderer_imp_opengl.h"

#include "../canvas/canvas.h"
#include "../canvas/opengl_canvas.h"
#include "../opengl_renderer/opengl_renderer.h"
#include "../opengl_renderer/scene/scene.h"
#include "../opengl_renderer/scene/scene_from_view.h"
#include "../view_scene/view_scene.h"

namespace s21 {

RendererImpOpenGL::RendererImpOpenGL() {}

RendererImpOpenGL::~RendererImpOpenGL() {}

void RendererImpOpenGL::Render(const ViewScene* scene, Canvas* canvas) {
  OpenGLRenderer::SceneFromView opengl_scene =
      OpenGLRenderer::SceneFromView(scene);

  OpenGLCanvas* opengl_canvas = reinterpret_cast<OpenGLCanvas*>(canvas);
  opengl_renderer_.Render(&opengl_scene, opengl_canvas);
}

std::vector<uint8_t> RendererImpOpenGL::GetPixels(const ViewScene* scene,
                                                  Canvas* canvas, int width,
                                                  int heigth) {
  OpenGLRenderer::SceneFromView opengl_scene =
      OpenGLRenderer::SceneFromView(scene);

  OpenGLCanvas* opengl_canvas = reinterpret_cast<OpenGLCanvas*>(canvas);

  std::vector<uint8_t> pixels =
      opengl_renderer_.GetPixels(&opengl_scene, opengl_canvas, width, heigth);

  Matrix<uint8_t> m(heigth, width * 4);

  int k = 0;
  for (int i = heigth - 1; i >= 0; --i) {
    for (int j = 0; j < width * 4; ++j) {
      m(i, j) = pixels[k];
      ++k;
    }
  }

  k = 0;
  for (int i = 0; i < heigth; ++i) {
    for (int j = 0; j < width * 4; ++j) {
      pixels[k] = m(i, j);
      ++k;
    }
  }

  return pixels;
}

}  // namespace s21
