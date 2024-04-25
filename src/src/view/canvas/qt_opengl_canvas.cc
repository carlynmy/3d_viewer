// Implementation class QTOpenGLCanvas

#include "qt_opengl_canvas.h"

#include <QOpenGLWidget>

namespace s21 {

QTOpenGLCanvas::QTOpenGLCanvas() {}

QTOpenGLCanvas::~QTOpenGLCanvas() {}

void QTOpenGLCanvas::StartRender() { opengl_widget_->makeCurrent(); }

void QTOpenGLCanvas::EndRender() { opengl_widget_->doneCurrent(); }

void QTOpenGLCanvas::SetOpenGLWidget(QOpenGLWidget* opengl_widget) {
  opengl_widget_ = opengl_widget;
}

QOpenGLWidget* QTOpenGLCanvas::GetOpenGLWidget() const {
  return opengl_widget_;
}

}  // namespace s21
