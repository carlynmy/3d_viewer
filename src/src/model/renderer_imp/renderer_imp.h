// Declaration class RendererImp

#ifndef _3D_VIEWER_MODEL_RENDERER_RENDERER_IMP_RENDERER_IMP_H_
#define _3D_VIEWER_MODEL_RENDERER_RENDERER_IMP_RENDERER_IMP_H_

#include <vector>

#include "../canvas/canvas.h"
#include "../view_scene/view_scene.h"

namespace s21 {

class RendererImp {
 public:
  RendererImp() {}
  virtual ~RendererImp(){};

  virtual void Render(const ViewScene* scene, Canvas* canvas) = 0;

  virtual std::vector<uint8_t> GetPixels(const ViewScene* scene, Canvas* canvas,
                                         int width, int heigth) = 0;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_RENDERER_RENDERER_IMP_RENDERER_IMP_H_
