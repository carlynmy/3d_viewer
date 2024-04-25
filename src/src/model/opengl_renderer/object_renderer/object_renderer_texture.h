// Declaration class ObjectRenderer

#ifndef _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_OBJECT_RENDERER_TEXTURE_H_
#define _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_OBJECT_RENDERER_TEXTURE_H_

#include <string>

#include "../color.h"
#include "../object/object.h"
#include "object_renderer.h"

namespace s21::OpenGLRenderer {

class ObjectRendererTexture : public ObjectRenderer {
 public:
  ObjectRendererTexture();
  virtual ~ObjectRendererTexture();

 protected:
  void SetTexture(Object::Texture tex, const std::string& var_name);

 private:
  GLuint texture_id_;
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_OBJECT_RENDERER_TEXTURE_H_
