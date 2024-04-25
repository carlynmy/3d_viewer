// Implementation class ObjectRendererKeeper

#include "object_renderer_keeper.h"

#include <vector>

#include "../object_renderer/factory.h"
#include "../object_renderer/object_renderer.h"

namespace s21::OpenGLRenderer {

ObjectRendererKeeper* ObjectRendererKeeper::instanse_ = nullptr;

ObjectRendererKeeper* ObjectRendererKeeper::GetInsanse() {
  if (!instanse_) instanse_ = new ObjectRendererKeeper();
  return instanse_;
}

void ObjectRendererKeeper::FreeInsanse() {
  if (!instanse_) {
    delete instanse_;
    instanse_ = nullptr;
  }
}

ObjectRenderer* ObjectRendererKeeper::GetObjectRenderer(
    ObjectRendererType id) const {
  return object_renderers_[ObjectRendererTypeToIdx(id)];
}

ObjectRendererKeeper::ObjectRendererKeeper() {
  object_renderers_.resize(kObjectRendererCount);
  FactoryObjectRenderer factory;

  ObjectRendererType type;
  type = ObjectRendererType::kTypeVColor;
  object_renderers_[ObjectRendererTypeToIdx(type)] = factory.Create(type);
  type = ObjectRendererType::kTypeVTColor;
  object_renderers_[ObjectRendererTypeToIdx(type)] = factory.Create(type);
  type = ObjectRendererType::kTypeVNColor;
  object_renderers_[ObjectRendererTypeToIdx(type)] = factory.Create(type);
  type = ObjectRendererType::kTypeVTNColor;
  object_renderers_[ObjectRendererTypeToIdx(type)] = factory.Create(type);
  type = ObjectRendererType::kTypeVTTexture;
  object_renderers_[ObjectRendererTypeToIdx(type)] = factory.Create(type);
  type = ObjectRendererType::kTypeVTNTexture;
  object_renderers_[ObjectRendererTypeToIdx(type)] = factory.Create(type);
}

ObjectRendererKeeper::~ObjectRendererKeeper() {
  for (auto i : object_renderers_) delete i;
}

int ObjectRendererKeeper::ObjectRendererTypeToIdx(ObjectRendererType id) const {
  return static_cast<int>(id);
}

}  // namespace s21::OpenGLRenderer
