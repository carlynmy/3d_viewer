// Declaration class OpenGLRenderer

#ifndef _3D_VIEWER_MODEL_OPENGL_RENDERER_OPENGL_RENDERER_H_
#define _3D_VIEWER_MODEL_OPENGL_RENDERER_OPENGL_RENDERER_H_

#include "color.h"
#include "model/canvas/opengl_canvas.h"
#include "object_renderer/factory.h"
#include "opengl.h"
#include "scene/scene.h"

namespace s21::OpenGLRenderer {

class OpenGLRender {
 public:
  OpenGLRender();
  virtual ~OpenGLRender();

  void Render(const Scene* scene, OpenGLCanvas* canvas);

  std::vector<uint8_t> GetPixels(const Scene* scene, OpenGLCanvas* canvas,
                                 int width, int heigth);

 private:
  using ObjectRendererType = FactoryObjectRenderer::ObjectRendererType;

  void InitState();
  void Clear(const Color& color);
  void RenderObject(const Scene* scene, const Object* object,
                    OpenGLCanvas* canvas);
  ObjectRendererType DefineRendererType(const Object* object) const;
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_OPENGL_RENDERER_OPENGL_RENDERER_H_
