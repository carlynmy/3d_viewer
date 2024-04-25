// Implementation class ObjectFromView

#include "object_from_view.h"

#include "../color.h"
#include "../opengl.h"
#include "model/color.h"
#include "model/mat4/mat4.h"
#include "model/view_object/view_object.h"
#include "object.h"

namespace s21::OpenGLRenderer {

ObjectFromView::ObjectFromView(const ViewObject* view_object) {
  view_object_ = view_object;
}

ObjectFromView::~ObjectFromView() {}

ObjectFromView::LineTypes ObjectFromView::GetLineType() const {
  return LineTypeToOpenGLLineType(view_object_->GetLineType());
}

GLfloat ObjectFromView::GetLineSize() const {
  return static_cast<GLfloat>(view_object_->GetLineSize());
}

s21::OpenGLRenderer::Color ObjectFromView::GetLineColor() const {
  return ColorToOpenGLColor(view_object_->GetLineColor());
}

ObjectFromView::VertexTypes ObjectFromView::GetVertexType() const {
  return VertexTypeToOpenGLVertexType(view_object_->GetVertexType());
}

GLfloat ObjectFromView::GetVertexSize() const {
  return static_cast<GLfloat>(view_object_->GetVertexSize());
}

s21::OpenGLRenderer::Color ObjectFromView::GetVertexColor() const {
  return ColorToOpenGLColor(view_object_->GetVertexColor());
}

s21::OpenGLRenderer::Color ObjectFromView::GetBaseColor() const {
  return ColorToOpenGLColor(view_object_->GetBaseColor());
}

const GLfloat* ObjectFromView::GetVertices() const {
  const float* vertices = view_object_->GetVertices().data();
  return reinterpret_cast<const GLfloat*>(vertices);
}

GLint ObjectFromView::GetVerticesCount() const {
  size_t vertices_count = view_object_->GetVertices().size();
  return static_cast<GLint>(vertices_count);
}

ObjectFromView::VertexStorageType ObjectFromView::GetVertexStorageType() const {
  return VertexStorageTypeToOpenGLVertexStorageType(
      view_object_->GetVerticesStorageType());
}

const GLint* ObjectFromView::GetFacePoint() const {
  const uint32_t* vertices = view_object_->GetFacesPoint().data();
  return reinterpret_cast<const GLint*>(vertices);
}

GLint ObjectFromView::GetFacePointCount() const {
  size_t face_count = view_object_->GetFacesPoint().size();
  return static_cast<GLint>(face_count);
}

const GLint* ObjectFromView::GetFaceLine() const {
  const uint32_t* vertices = view_object_->GetFacesLine().data();
  return reinterpret_cast<const GLint*>(vertices);
}

GLint ObjectFromView::GetFaceLineCount() const {
  size_t face_count = view_object_->GetFacesLine().size();
  return static_cast<GLint>(face_count);
}

const GLint* ObjectFromView::GetFaceTriangle() const {
  const uint32_t* vertices = view_object_->GetFacesTriangle().data();
  return reinterpret_cast<const GLint*>(vertices);
}

GLint ObjectFromView::GetFaceTriangleCount() const {
  size_t face_count = view_object_->GetFacesTriangle().size();
  return static_cast<GLint>(face_count);
}

Mat4 ObjectFromView::GetModelMatrix() const {
  return view_object_->GetModelMatrix();
}

ObjectFromView::PolygonMode ObjectFromView::GetPolygonMode() const {
  ViewObject::PolygonMode mode = view_object_->GetPolygonMode();
  switch (mode) {
    case ViewObject::PolygonMode::kPolygonModeFill:
      return PolygonMode::kPolygonModeFill;
      break;
    case ViewObject::PolygonMode::kPolygonModeTexture:
      return PolygonMode::kPolygonModeTexture;
      break;
    default:
      break;
  }
  return PolygonMode::kPolygonModeLine;
}

ObjectFromView::Texture ObjectFromView::GetTexture() const {
  ViewObject::Texture v_tex = view_object_->GetTexture();
  Texture tex;

  GLenum tex_format = GL_RGB;
  if (v_tex.format_ == ViewObject::Texture::Format::kFormatRGBA)
    tex_format = GL_RGBA;
  tex.width_ = static_cast<GLsizei>(v_tex.width_);
  tex.height_ = static_cast<GLsizei>(v_tex.height_);
  tex.format_ = tex_format;
  tex.type_ = GL_UNSIGNED_BYTE;
  tex.data_ = v_tex.bytes_.data();

  return tex;
}

s21::OpenGLRenderer::Color ObjectFromView::ColorToOpenGLColor(
    const s21::Color& color) {
  GLclampf r = static_cast<GLclampf>(static_cast<float>(color.GetR()) / 255.0);
  GLclampf g = static_cast<GLclampf>(static_cast<float>(color.GetG()) / 255.0);
  GLclampf b = static_cast<GLclampf>(static_cast<float>(color.GetB()) / 255.0);
  GLclampf a = static_cast<GLclampf>(static_cast<float>(color.GetA()) / 255.0);

  s21::OpenGLRenderer::Color opengl_color =
      s21::OpenGLRenderer::Color(r, g, b, a);
  return opengl_color;
}

ObjectFromView::LineTypes ObjectFromView::LineTypeToOpenGLLineType(
    ViewObject::LineTypes type) {
  switch (type) {
    case ViewObject::kLineTypeDotted:
      return Object::kLineTypeDotted;
      break;
    default:
      break;
  }
  return Object::kLineTypeSolid;
}

ObjectFromView::VertexTypes ObjectFromView::VertexTypeToOpenGLVertexType(
    ViewObject::VertexTypes type) {
  switch (type) {
    case ViewObject::kVertexTypeCircle:
      return Object::kVertexTypeCircle;
      break;
    case ViewObject::kVertexTypeSquare:
      return Object::kVertexTypeSquare;
      break;
    default:
      break;
  }
  return Object::kVertexTypeNone;
}

ObjectFromView::VertexStorageType
ObjectFromView::VertexStorageTypeToOpenGLVertexStorageType(
    ViewObject::VerticesStorageType type) {
  switch (type) {
    case ViewObject::VerticesStorageType::kVerticesStorageTypeVerticesTexture:
      return Object::kVertexStorageVertexTexture;
      break;
    case ViewObject::VerticesStorageType::kVerticesStorageTypeVerticesNormale:
      return Object::kVertexStorageVertexNormale;
      break;
    case ViewObject::VerticesStorageType::
        kVerticesStorageTypeVerticesTextureNormale:
      return Object::kVertexStorageVertexTextureNormale;
      break;
    default:
      break;
  }
  return Object::kVertexStorageVertex;
}

}  // namespace s21::OpenGLRenderer
