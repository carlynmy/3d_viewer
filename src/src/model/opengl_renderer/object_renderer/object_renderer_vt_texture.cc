// Implementation class ObjectRendererVTTexture

#include "object_renderer_vt_texture.h"

#include <string>

#include "../object/object.h"
#include "../scene/scene.h"
#include "../shader_programm_keeper/shader_programm_keeper.h"

namespace s21::OpenGLRenderer {

const ShaderProgrammKeeper::ShaderProgrammId
    ObjectRendererVTTexture::kProgramm =
        ShaderProgrammKeeper::kShaderVTNTexture;
const std::string ObjectRendererVTTexture::kVarTextureName = "texture1";
const std::string ObjectRendererVTTexture::kVarNameMatProjecion = "projection";
const std::string ObjectRendererVTTexture::kVarNameMatView = "view";
const std::string ObjectRendererVTTexture::kVarNameModel = "model";

ObjectRendererVTTexture::ObjectRendererVTTexture() {
  SetProgramm(ShaderProgrammKeeper::GetInsanse()->GetShaderProgramm(kProgramm));
}

ObjectRendererVTTexture::~ObjectRendererVTTexture() {}

void ObjectRendererVTTexture::Render(const Scene* scene, const Object* object,
                                     OpenGLCanvas* canvas) {
  SetVBOData(object->GetVertices(), object->GetVerticesCount());

  SetVariables(scene, object, canvas);

  SetTexture(object->GetTexture(), kVarTextureName);

  DrawVertex(object);
  DrawPolygons(object);
}

void ObjectRendererVTTexture::SetVariables(const Scene* scene,
                                           const Object* object,
                                           OpenGLCanvas* canvas) {
  Mat4 mat_projection =
      scene->GetProjectionMatrix(canvas->GetWidth(), canvas->GetHeight());
  Mat4 mat_view = scene->GetViewMatrix();
  Mat4 mat_model = object->GetModelMatrix();
  mat_projection.Transpose();
  mat_view.Transpose();
  mat_model.Transpose();
  SetUniformMat4(mat_projection, kVarNameMatProjecion);
  SetUniformMat4(mat_view, kVarNameMatView);
  SetUniformMat4(mat_model, kVarNameModel);

  UseProgramm();
  UseVBO();

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
                        (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
                        (void*)(3 * sizeof(GLfloat)));
  glEnableVertexAttribArray(1);
}

}  // namespace s21::OpenGLRenderer
