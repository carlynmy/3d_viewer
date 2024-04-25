// Implementation class ObjectRendererVNColor

#include "object_renderer_vn_color.h"

#include <string>

#include "../object/object.h"
#include "../scene/scene.h"
#include "../shader_programm_keeper/shader_programm_keeper.h"

namespace s21::OpenGLRenderer {

const ShaderProgrammKeeper::ShaderProgrammId ObjectRendererVNColor::kProgramm =
    ShaderProgrammKeeper::kShaderVNColor;
const std::string ObjectRendererVNColor::kVarColorName = "color";
const std::string ObjectRendererVNColor::kVarNameMatProjecion = "projection";
const std::string ObjectRendererVNColor::kVarNameMatView = "view";
const std::string ObjectRendererVNColor::kVarNameModel = "model";

ObjectRendererVNColor::ObjectRendererVNColor() {
  SetProgramm(ShaderProgrammKeeper::GetInsanse()->GetShaderProgramm(kProgramm));
}

ObjectRendererVNColor::~ObjectRendererVNColor() {}

void ObjectRendererVNColor::Render(const Scene* scene, const Object* object,
                                   OpenGLCanvas* canvas) {
  SetVBOData(object->GetVertices(), object->GetVerticesCount());

  SetVariables(scene, object, canvas);

  SetColor(object->GetVertexColor(), kVarColorName);
  DrawVertex(object);
  SetColor(object->GetLineColor(), kVarColorName);
  DrawPolygons(object);
}

void ObjectRendererVNColor::SetVariables(const Scene* scene,
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

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
                        (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
                        (void*)(3 * sizeof(GLfloat)));
  glEnableVertexAttribArray(1);
}

}  // namespace s21::OpenGLRenderer
