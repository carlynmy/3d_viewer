// Delcaration class Object

#ifndef _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_OBJECT_H
#define _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_OBJECT_H

#include "../color.h"
#include "../opengl.h"
#include "model/mat4/mat4.h"

namespace s21::OpenGLRenderer {

/// @brief Interface to Object
class Object {
 public:
  enum LineTypes { kLineTypeSolid, kLineTypeDotted };
  enum VertexTypes { kVertexTypeNone, kVertexTypeCircle, kVertexTypeSquare };
  enum VertexStorageType {
    kVertexStorageVertex,
    kVertexStorageVertexTexture,
    kVertexStorageVertexNormale,
    kVertexStorageVertexTextureNormale
  };
  enum PolygonMode {
    kPolygonModeLine,
    kPolygonModeFill,
    kPolygonModeTexture,
  };

  struct Texture {
    GLsizei width_;
    GLsizei height_;
    GLenum format_;
    GLenum type_;
    void* data_;
  };

  Object() {}
  virtual ~Object(){};

  virtual LineTypes GetLineType() const = 0;
  virtual GLfloat GetLineSize() const = 0;
  virtual Color GetLineColor() const = 0;
  virtual VertexTypes GetVertexType() const = 0;
  virtual GLfloat GetVertexSize() const = 0;
  virtual Color GetVertexColor() const = 0;
  virtual Color GetBaseColor() const = 0;

  virtual const GLfloat* GetVertices() const = 0;
  virtual GLint GetVerticesCount() const = 0;
  virtual VertexStorageType GetVertexStorageType() const = 0;
  virtual const GLint* GetFacePoint() const = 0;
  virtual GLint GetFacePointCount() const = 0;
  virtual const GLint* GetFaceLine() const = 0;
  virtual GLint GetFaceLineCount() const = 0;
  virtual const GLint* GetFaceTriangle() const = 0;
  virtual GLint GetFaceTriangleCount() const = 0;

  virtual Mat4 GetModelMatrix() const = 0;

  virtual PolygonMode GetPolygonMode() const = 0;
  virtual Texture GetTexture() const = 0;
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_OPENGL_RENDERER_OBJECT_OBJECT_H
