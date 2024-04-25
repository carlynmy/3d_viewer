// Declaration class Scene

#ifndef _3D_VIEWER_MODEL_OPENGL_RENDERER_SCENE_SCENE_H
#define _3D_VIEWER_MODEL_OPENGL_RENDERER_SCENE_SCENE_H

#include <vector>

#include "../color.h"
#include "../light_source/light_source.h"
#include "../object/object.h"
#include "model/mat4/mat4.h"

namespace s21::OpenGLRenderer {

/// @brief Scene for OpenGLRenderer
class Scene {
 public:
  using Objects = std::vector<Object*>;
  using LightSources = std::vector<LightSource*>;
  enum ProjectionTypes { kPrTypeCentral, kPrTypeParallel };

  Scene();
  virtual ~Scene();

  virtual Color GetBackgroundColor() const = 0;
  virtual ProjectionTypes GetProjectionType() const = 0;
  virtual GLboolean IsFloorShow() const = 0;
  virtual GLboolean IsLightTrasser() const = 0;

  virtual Mat4 GetProjectionMatrix(int width, int height) const = 0;
  virtual Mat4 GetViewMatrix() const = 0;

  Objects::const_iterator ObjectsBegin() const;
  Objects::const_iterator ObjectsEnd() const;
  LightSources::const_iterator LightSourcesBegin() const;
  LightSources::const_iterator LightSourcesEnd() const;

 protected:
  Objects& GetObjects();
  LightSources& GetLightSources();

 private:
  Objects objects_;
  LightSources light_sources_;
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_OPENGL_RENDERER_SCENE_SCENE_H
