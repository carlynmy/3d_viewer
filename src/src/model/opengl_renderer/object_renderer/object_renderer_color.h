// Declaration class ObjectRenderer

#ifndef _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_OBJECT_RENDERER_COLOR_H_
#define _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_OBJECT_RENDERER_COLOR_H_

#include <string>

#include "../color.h"
#include "../object/object.h"
#include "object_renderer.h"

namespace s21::OpenGLRenderer {

class ObjectRendererColor : public ObjectRenderer {
 public:
  ObjectRendererColor();
  virtual ~ObjectRendererColor();

 protected:
  void SetColor(const Color& color, const std::string& var_name);
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_OBJECT_RENDERER_COLOR_H_
