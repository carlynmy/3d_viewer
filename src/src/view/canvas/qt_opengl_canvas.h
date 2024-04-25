// Decalaration class QTOpenGLCanvas

#ifndef _3D_VIEWER_VIEW_CANVAS_QT_OPENGL_CANVAS_H_
#define _3D_VIEWER_VIEW_CANVAS_QT_OPENGL_CANVAS_H_

#include <QOpenGLWidget>

#include "../../model/canvas/opengl_canvas.h"

namespace s21 {

/// @brief OpenGLCanvas for qt, require QOpenGLWidget, render will be happen in
/// QopenGLWidget
class QTOpenGLCanvas : public OpenGLCanvas {
 public:
  QTOpenGLCanvas();
  virtual ~QTOpenGLCanvas();

  /// @warning Undefined behavior if QOpenGLWidget not set or invalid
  void StartRender() override;

  /// @warning Undefined behavior if QOpenGLWidget not set or invalid
  void EndRender() override;

  /// @brief Set QOpenGLWidget
  void SetOpenGLWidget(QOpenGLWidget* opengl_widget);

  /// @warning Undefined behavior if QOpenGLWidget not set
  QOpenGLWidget* GetOpenGLWidget() const;

 private:
  QOpenGLWidget* opengl_widget_;
};

}  // namespace s21

#endif  // _3D_VIEWER_VIEW_CANVAS_QT_OPENGL_CANVAS_H_
