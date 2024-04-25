//

//

#ifndef _3D_VIEWER_MODEL_OPENGL_RENDERER_COLOR_H_
#define _3D_VIEWER_MODEL_OPENGL_RENDERER_COLOR_H_

#include "opengl.h"

namespace s21::OpenGLRenderer {

class Color {
 public:
  Color() : Color(0.0, 0.0, 0.0, 0.0) {}

  Color(GLclampf r, GLclampf g, GLclampf b, GLclampf a = 0.0)
      : r_(r), g_(g), b_(b), a_(a) {}

  Color(const Color& other) {
    r_ = other.r_;
    g_ = other.g_;
    b_ = other.b_;
    a_ = other.a_;
  }

  Color& operator=(const Color& other) {
    if (this == &other) return *this;

    r_ = other.r_;
    g_ = other.g_;
    b_ = other.b_;
    a_ = other.a_;

    return *this;
  }

  ~Color() {}

  void SetR(GLclampf r) { r_ = r; }
  void SetG(GLclampf g) { g_ = g; }
  void SetB(GLclampf b) { b_ = b; }
  void SetA(GLclampf a) { a_ = a; }

  GLclampf GetR() const { return r_; }
  GLclampf GetG() const { return g_; }
  GLclampf GetB() const { return b_; }
  GLclampf GetA() const { return a_; }

 private:
  GLclampf r_;
  GLclampf g_;
  GLclampf b_;
  GLclampf a_;
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_OPENGL_RENDERER_COLOR_H_
