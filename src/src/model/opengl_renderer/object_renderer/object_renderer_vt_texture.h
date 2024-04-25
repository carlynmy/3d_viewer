// Declaration class ObjectRendererVTTexture

#ifndef _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_OBJECT_RENDERER_VT_TEXTURE_H_
#define _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_OBJECT_RENDERER_VT_TEXTURE_H_

#include <string>

#include "../object/object.h"
#include "../scene/scene.h"
#include "../shader_programm_keeper/shader_programm_keeper.h"
#include "object_renderer_texture.h"

namespace s21::OpenGLRenderer {

class ObjectRendererVTTexture : public ObjectRendererTexture {
 public:
  ObjectRendererVTTexture();
  virtual ~ObjectRendererVTTexture();

  void Render(const Scene* scene, const Object* object,
              OpenGLCanvas* canvas) override;

 private:
  static const ShaderProgrammKeeper::ShaderProgrammId kProgramm;
  static const std::string kVarTextureName;
  static const std::string kVarNameMatProjecion;
  static const std::string kVarNameMatView;
  static const std::string kVarNameModel;

  void SetVariables(const Scene* scene, const Object* object,
                    OpenGLCanvas* canvas);
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_OBJECT_RENDERER_VTN_TEXTURE_H_
