// Implementation class FactoryObjectRenderer

#include "factory.h"

#include "object_renderer.h"
#include "object_renderer_v_color.h"
#include "object_renderer_vn_color.h"
#include "object_renderer_vt_color.h"
#include "object_renderer_vt_texture.h"
#include "object_renderer_vtn_color.h"
#include "object_renderer_vtn_texture.h"

namespace s21::OpenGLRenderer {

FactoryObjectRenderer::FactoryObjectRenderer() {}

FactoryObjectRenderer::~FactoryObjectRenderer() {}

ObjectRenderer* FactoryObjectRenderer::Create(ObjectRendererType type) {
  switch (type) {
    case ObjectRendererType::kTypeVColor:
      return new ObjectRendererVColor();
      break;
    case ObjectRendererType::kTypeVTColor:
      return new ObjectRendererVTColor();
      break;
    case ObjectRendererType::kTypeVNColor:
      return new ObjectRendererVNColor();
      break;
    case ObjectRendererType::kTypeVTNColor:
      return new ObjectRendererVTNColor();
      break;
    case ObjectRendererType::kTypeVTTexture:
      return new ObjectRendererVTTexture();
      break;
    case ObjectRendererType::kTypeVTNTexture:
      return new ObjectRendererVTNTexture();
      break;
    default:
      break;
  }

  return nullptr;
}

}  // namespace s21::OpenGLRenderer
