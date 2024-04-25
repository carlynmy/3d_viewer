// delcaration class ObjectRendererKeeper

#ifndef _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_KEEPER_OBJECT_RENDERER_KEEPER_H_
#define _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_KEEPER_OBJECT_RENDERER_KEEPER_H_

#include <vector>

#include "../object_renderer/factory.h"
#include "../object_renderer/object_renderer.h"

namespace s21::OpenGLRenderer {

class ObjectRendererKeeper {
 public:
  using ObjectRendererType = FactoryObjectRenderer::ObjectRendererType;

  static ObjectRendererKeeper* GetInsanse();
  static void FreeInsanse();

  ObjectRenderer* GetObjectRenderer(ObjectRendererType id) const;

 private:
  ObjectRendererKeeper();
  virtual ~ObjectRendererKeeper();
  ObjectRendererKeeper(const ObjectRendererKeeper& other) = delete;
  ObjectRendererKeeper(ObjectRendererKeeper&& other) noexcept = delete;
  ObjectRendererKeeper& operator=(const ObjectRendererKeeper& other) = delete;
  ObjectRendererKeeper& operator=(ObjectRendererKeeper&& other) noexcept =
      delete;

  int ObjectRendererTypeToIdx(ObjectRendererType id) const;

  static ObjectRendererKeeper* instanse_;
  static const int kObjectRendererCount = 6;

  std::vector<ObjectRenderer*> object_renderers_;
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_KEEPER_OBJECT_RENDERER_KEEPER_H_
