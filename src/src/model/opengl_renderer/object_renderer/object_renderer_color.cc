// Implementation class ObjectRenderer

#include "object_renderer_color.h"

#include <string>

#include "../color.h"
#include "../object/object.h"
#include "object_renderer.h"

namespace s21::OpenGLRenderer {

ObjectRendererColor::ObjectRendererColor() {}

ObjectRendererColor::~ObjectRendererColor() {}

void ObjectRendererColor::SetColor(const Color& color,
                                   const std::string& var_name) {
  UseProgramm();
  int loc = glGetUniformLocation(GetProgramm(), var_name.c_str());
  glUniform4f(loc, color.GetR(), color.GetG(), color.GetB(), color.GetA());
}

}  // namespace s21::OpenGLRenderer
