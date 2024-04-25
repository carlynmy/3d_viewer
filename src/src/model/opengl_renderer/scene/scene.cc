// Implementation class Scene

#include "scene.h"

#include <vector>

#include "../color.h"
#include "../light_source/light_source.h"
#include "../object/object.h"

namespace s21::OpenGLRenderer {

Scene::Scene() {}

Scene::~Scene() {
  for (auto i : objects_) delete i;
  for (auto i : light_sources_) delete i;
}

Scene::Objects::const_iterator Scene::ObjectsBegin() const {
  return objects_.begin();
}

Scene::Objects::const_iterator Scene::ObjectsEnd() const {
  return objects_.end();
}

Scene::LightSources::const_iterator Scene::LightSourcesBegin() const {
  return light_sources_.begin();
}

Scene::LightSources::const_iterator Scene::LightSourcesEnd() const {
  return light_sources_.end();
}

Scene::Objects& Scene::GetObjects() { return objects_; }

Scene::LightSources& Scene::GetLightSources() { return light_sources_; }

}  // namespace s21::OpenGLRenderer
