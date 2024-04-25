// Declaration class OpenGLCanvas

#ifndef _3D_VIEWER_MODEL_CANVAS_OPENGL_CANVAS_H_
#define _3D_VIEWER_MODEL_CANVAS_OPENGL_CANVAS_H_

#include "canvas.h"

namespace s21 {

/// @brief Abstract Canvas for OpenGLRenderer. Expect creation OpenGLContext and
/// make it current by StartRender method, and release context by EndRender.
class OpenGLCanvas : public Canvas {
 public:
  OpenGLCanvas() : Canvas() {}
  OpenGLCanvas(int width, int height) : Canvas(width, height) {}
  virtual ~OpenGLCanvas() {}

  virtual void StartRender() = 0;
  virtual void EndRender() = 0;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_CANVAS_OPENGL_CANVAS_H_
