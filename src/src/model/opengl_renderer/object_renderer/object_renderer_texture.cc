// Implementation class ObjectRenderer

#include "object_renderer_texture.h"

#include <string>

#include "../color.h"
#include "../object/object.h"
#include "object_renderer.h"

namespace s21::OpenGLRenderer {

ObjectRendererTexture::ObjectRendererTexture() {
  glGenTextures(1, &texture_id_);
}

ObjectRendererTexture::~ObjectRendererTexture() {
  glDeleteTextures(1, &texture_id_);
}

void ObjectRendererTexture::SetTexture(Object::Texture tex,
                                       const std::string& var_name) {
  UseProgramm();
  glBindTexture(GL_TEXTURE_2D, texture_id_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, tex.format_, tex.width_, tex.height_, 0,
               tex.format_, tex.type_, tex.data_);
  glGenerateMipmap(GL_TEXTURE_2D);

  GLuint id;
  id = glGetUniformLocation(GetProgramm(), var_name.c_str());
  glUniform1i(id, 0);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture_id_);
}

}  // namespace s21::OpenGLRenderer
