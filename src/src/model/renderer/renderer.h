// Declaration class Renderer

#ifndef _3D_VIEWER_MODEL_RENDERER_RENDERER_H_
#define _3D_VIEWER_MODEL_RENDERER_RENDERER_H_

#include <vector>

#include "../canvas/canvas.h"
#include "../renderer_imp/renderer_imp.h"
#include "../renderer_imp_opengl/renderer_imp_opengl.h"
#include "../view_scene/view_scene.h"

namespace s21 {

class Renderer {
 public:
  Renderer();
  virtual ~Renderer();

  void Render(const ViewScene* scene, Canvas* canvas);
  std::vector<uint8_t> GetPixels(const ViewScene* scene, Canvas* canvas,
                                 int width, int heigth);

 private:
  Renderer(const Renderer& other) = delete;
  Renderer(Renderer&& other) noexcept = delete;
  Renderer& operator=(const Renderer& other) = delete;
  Renderer& operator=(Renderer&& other) = delete;

  RendererImp* renderer_imp_;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_RENDERER_RENDERER_H_
