// Declaration class OpenGLRenderer

#include "opengl_renderer.h"

#include "color.h"
#include "model/canvas/opengl_canvas.h"
#include "object_renderer_keeper/object_renderer_keeper.h"
#include "opengl.h"
#include "scene/scene.h"
#include "shader_keeper/shader_keeper.h"
#include "shader_programm_keeper/shader_programm_keeper.h"

namespace s21::OpenGLRenderer {

OpenGLRender::OpenGLRender() {}

OpenGLRender::~OpenGLRender() {
  ObjectRendererKeeper::FreeInsanse();
  ShaderProgrammKeeper::FreeInsanse();
  ShaderKeeper::FreeInsanse();
}

void OpenGLRender::Render(const Scene* scene, OpenGLCanvas* canvas) {
  canvas->StartRender();

  InitState();
  glViewport(0, 0, canvas->GetWidth(), canvas->GetHeight());
  Clear(scene->GetBackgroundColor());

  for (auto i = scene->ObjectsBegin(); i != scene->ObjectsEnd(); ++i) {
    RenderObject(scene, *i, canvas);
  }

  canvas->EndRender();
}

void OpenGLRender::InitState() {
#ifndef __APPLE__
  glewExperimental = GL_TRUE;
  glewInit();
#endif
  glEnable(GL_DEPTH_TEST);
}

void OpenGLRender::Clear(const Color& color) {
  glClearColor(color.GetR(), color.GetG(), color.GetB(), color.GetA());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRender::RenderObject(const Scene* scene, const Object* object,
                                OpenGLCanvas* canvas) {
  ObjectRendererType type = DefineRendererType(object);
  ObjectRenderer* object_renderer =
      ObjectRendererKeeper::GetInsanse()->GetObjectRenderer(type);

  if (object->GetPolygonMode() == Object::PolygonMode::kPolygonModeLine)
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  else
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  if (object->GetLineType() == Object::LineTypes::kLineTypeDotted) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x5);
  } else
    glDisable(GL_LINE_STIPPLE);
  glLineWidth(object->GetLineSize());

  if (object->GetVertexType() == Object::VertexTypes::kVertexTypeCircle) {
    glEnable(GL_POINT_SMOOTH);
  } else {
    glDisable(GL_POINT_SMOOTH);
  }
  glPointSize(object->GetVertexSize());

  object_renderer->Render(scene, object, canvas);
}

OpenGLRender::ObjectRendererType OpenGLRender::DefineRendererType(
    const Object* object) const {
  if (object->GetPolygonMode() == Object::PolygonMode::kPolygonModeTexture &&
      (object->GetVertexStorageType() ==
           Object::VertexStorageType::kVertexStorageVertexTexture ||
       object->GetVertexStorageType() ==
           Object::VertexStorageType::kVertexStorageVertexTextureNormale)) {
    switch (object->GetVertexStorageType()) {
      case Object::VertexStorageType::kVertexStorageVertexTexture:
        return ObjectRendererType::kTypeVTTexture;
        break;
      default:
        break;
    }
    return ObjectRendererType::kTypeVTNTexture;
  }

  switch (object->GetVertexStorageType()) {
    case Object::VertexStorageType::kVertexStorageVertexNormale:
      return ObjectRendererType::kTypeVNColor;
      break;
    case Object::VertexStorageType::kVertexStorageVertexTexture:
      return ObjectRendererType::kTypeVTColor;
      break;
    case Object::VertexStorageType::kVertexStorageVertexTextureNormale:
      return ObjectRendererType::kTypeVTNColor;
      break;
    default:
      break;
  }
  return ObjectRendererType::kTypeVColor;
}

std::vector<uint8_t> OpenGLRender::GetPixels(const Scene* scene,
                                             OpenGLCanvas* canvas, int width,
                                             int heigth) {
  canvas->StartRender();

  InitState();
  glViewport(0, 0, canvas->GetWidth(), canvas->GetHeight());
  Clear(scene->GetBackgroundColor());

  for (auto i = scene->ObjectsBegin(); i != scene->ObjectsEnd(); ++i) {
    RenderObject(scene, *i, canvas);
  }

  std::vector<uint8_t> pixels(width * heigth * 4);
  uint8_t* ptr = pixels.data();
  glReadPixels(0, 0, width, heigth, GL_RGBA, GL_UNSIGNED_BYTE, ptr);

  canvas->EndRender();

  return pixels;
}

}  // namespace s21::OpenGLRenderer
