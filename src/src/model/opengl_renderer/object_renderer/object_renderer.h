// Declaration class ObjectRenderer

#ifndef _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_OBJECT_RENDERER_H_
#define _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_OBJECT_RENDERER_H_

#include <string>

#include "../object/object.h"
#include "../opengl.h"
#include "../scene/scene.h"
#include "model/canvas/opengl_canvas.h"
#include "model/mat4/mat4.h"

namespace s21::OpenGLRenderer {

class ObjectRenderer {
 public:
  ObjectRenderer();
  virtual ~ObjectRenderer();

  virtual void Render(const Scene* scene, const Object* object,
                      OpenGLCanvas* canvas) = 0;

 protected:
  void SetProgramm(GLuint shader_programm);
  GLuint GetProgramm();
  void UseProgramm();
  void SetVBOData(const GLfloat* vertices, GLuint count);
  void UseVBO();

  void SetUniformMat4(const Mat4& mat, const std::string& var_name);

  void DrawVertex(const Object* object);
  void DrawPolygons(const Object* object);

 private:
  GLuint shader_programm_;
  GLuint vbo_;
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_RENDERER_OBJECT_RENDERER_H_
