// Declaration class ObjectFromView

#ifndef _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_OBJECT_FROM_VIEW_H
#define _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_OBJECT_FROM_VIEW_H

#include "../color.h"
#include "../opengl.h"
#include "model/color.h"
#include "model/mat4/mat4.h"
#include "model/view_object/view_object.h"
#include "object.h"

namespace s21::OpenGLRenderer {

class ObjectFromView : public Object {
 public:
  using LineTypes = Object::LineTypes;
  using VertexTypes = Object::VertexTypes;
  using VertexStorageType = Object::VertexStorageType;
  using PolygonMode = Object::PolygonMode;
  using Texture = Object::Texture;

  ObjectFromView(const ViewObject* view_object);
  virtual ~ObjectFromView();

  LineTypes GetLineType() const override;
  GLfloat GetLineSize() const override;
  Color GetLineColor() const override;
  VertexTypes GetVertexType() const override;
  GLfloat GetVertexSize() const override;
  Color GetVertexColor() const override;
  Color GetBaseColor() const override;

  const GLfloat* GetVertices() const override;
  GLint GetVerticesCount() const override;
  VertexStorageType GetVertexStorageType() const override;
  const GLint* GetFacePoint() const override;
  GLint GetFacePointCount() const override;
  const GLint* GetFaceLine() const override;
  GLint GetFaceLineCount() const override;
  const GLint* GetFaceTriangle() const override;
  GLint GetFaceTriangleCount() const override;

  Mat4 GetModelMatrix() const override;

  PolygonMode GetPolygonMode() const override;
  Texture GetTexture() const override;

 private:
  static s21::OpenGLRenderer::Color ColorToOpenGLColor(const s21::Color& color);
  static LineTypes LineTypeToOpenGLLineType(ViewObject::LineTypes type);
  static VertexTypes VertexTypeToOpenGLVertexType(ViewObject::VertexTypes type);
  static VertexStorageType VertexStorageTypeToOpenGLVertexStorageType(
      ViewObject::VerticesStorageType type);

  const ViewObject* view_object_;
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_OBJECT_FROM_VIEW_H
