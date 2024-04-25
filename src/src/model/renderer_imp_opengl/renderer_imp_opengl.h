// Declaration class RendererImpOpenGL

#ifndef _3D_VIEWER_MODEL_RENDERER_RENDERER_IMP_RENDERER_IMP_OPENGL_RENDERER_IMP_OPENGL
#define _3D_VIEWER_MODEL_RENDERER_RENDERER_IMP_RENDERER_IMP_OPENGL_RENDERER_IMP_OPENGL

#include "../canvas/canvas.h"
#include "../opengl_renderer/opengl_renderer.h"
#include "../renderer_imp/renderer_imp.h"
#include "../view_scene/view_scene.h"

namespace s21 {

class RendererImpOpenGL : public RendererImp {
 public:
  RendererImpOpenGL();
  virtual ~RendererImpOpenGL();

  void Render(const ViewScene* scene, Canvas* canvas) override;

  std::vector<uint8_t> GetPixels(const ViewScene* scene, Canvas* canvas,
                                 int width, int heigth) override;

 private:
  OpenGLRenderer::OpenGLRender opengl_renderer_;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_RENDERER_RENDERER_IMP_RENDERER_IMP_OPENGL_RENDERER_IMP_OPENGL
