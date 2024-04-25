// Declaration class FactoryObjectRenderer

#ifndef _3D_VIEWER_MODEL_OPENGL_RENDERER_OJBECT_RENDERER_FACTORY_H_
#define _3D_VIEWER_MODEL_OPENGL_RENDERER_OJBECT_RENDERER_FACTORY_H_

#include "object_renderer.h"

namespace s21::OpenGLRenderer {

class FactoryObjectRenderer {
 public:
  enum ObjectRendererType {
    kTypeVColor,
    kTypeVTColor,
    kTypeVNColor,
    kTypeVTNColor,
    kTypeVTTexture,
    kTypeVTNTexture,
  };

  FactoryObjectRenderer();
  virtual ~FactoryObjectRenderer();

  /// @brief Construct new instanse ObjectRenderer
  virtual ObjectRenderer* Create(ObjectRendererType type);
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_OPENGL_RENDERER_OJBECT_RENDERER_FACTORY_H_
