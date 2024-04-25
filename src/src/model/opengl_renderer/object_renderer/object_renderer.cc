// Implementation class ObjectRenderer

#include "object_renderer.h"

#include <string>

#include "../object/object.h"
#include "../opengl.h"
#include "../scene/scene.h"
#include "model/mat4/mat4.h"

namespace s21::OpenGLRenderer {

ObjectRenderer::ObjectRenderer() { glGenBuffers(1, &vbo_); }

ObjectRenderer::~ObjectRenderer() { glDeleteBuffers(1, &vbo_); }

void ObjectRenderer::SetProgramm(GLuint shader_programm) {
  shader_programm_ = shader_programm;
}

GLuint ObjectRenderer::GetProgramm() { return shader_programm_; }

void ObjectRenderer::UseProgramm() { glUseProgram(shader_programm_); }

void ObjectRenderer::SetVBOData(const GLfloat* vertices, GLuint count) {
  UseVBO();
  glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), vertices,
               GL_STATIC_DRAW);
}

void ObjectRenderer::UseVBO() { glBindBuffer(GL_ARRAY_BUFFER, vbo_); }

void ObjectRenderer::SetUniformMat4(const Mat4& mat,
                                    const std::string& var_name) {
  UseProgramm();
  GLuint id = glGetUniformLocation(shader_programm_, var_name.c_str());
  glUniformMatrix4fv(id, 1, GL_FALSE, mat.GetData());
}

void ObjectRenderer::DrawVertex(const Object* object) {
  if (object->GetVertexType() == Object::VertexTypes::kVertexTypeNone) return;
  UseVBO();
  UseProgramm();
  glDrawElements(GL_POINTS, object->GetFacePointCount(), GL_UNSIGNED_INT,
                 object->GetFacePoint());
  glDrawElements(GL_POINTS, object->GetFaceLineCount(), GL_UNSIGNED_INT,
                 object->GetFaceLine());
  glDrawElements(GL_POINTS, object->GetFaceTriangleCount(), GL_UNSIGNED_INT,
                 object->GetFaceTriangle());
}

void ObjectRenderer::DrawPolygons(const Object* object) {
  UseVBO();
  UseProgramm();
  glDrawElements(GL_POINTS, object->GetFacePointCount(), GL_UNSIGNED_INT,
                 object->GetFacePoint());
  glDrawElements(GL_LINES, object->GetFaceLineCount(), GL_UNSIGNED_INT,
                 object->GetFaceLine());
  glDrawElements(GL_TRIANGLES, object->GetFaceTriangleCount(), GL_UNSIGNED_INT,
                 object->GetFaceTriangle());
}

}  // namespace s21::OpenGLRenderer
