// Declaration class ControllerDefault

#include "controller_default.h"

#include "../model/model.h"
#include "controller.h"

namespace s21 {

ControllerDefault::ControllerDefault(Model* model) { model_ = model; }

ControllerDefault::~ControllerDefault() {}

// ------------------------------------------------------------------------- //
//                                Canvas                                     //
// ------------------------------------------------------------------------- //

void ControllerDefault::SetCanvas(Canvas* canvas) { model_->SetCanvas(canvas); }

Canvas* ControllerDefault::GetCanvas() { return model_->GetCanvas(); }

void ControllerDefault::SetWidth(int widht) { model_->SetWidth(widht); }

void ControllerDefault::SetHeight(int height) { model_->SetHeight(height); }

// ------------------------------------------------------------------------- //
//                                 Scene                                     //
// ------------------------------------------------------------------------- //

void ControllerDefault::RotateScene(AxisId axis, float value) {
  model_->RotateScene(axis, value);
}

void ControllerDefault::MoveScene(AxisId axis, float value) {
  model_->MoveScene(axis, value);
}

void ControllerDefault::ScaleScene(float value) { model_->ScaleScene(value); }

void ControllerDefault::Render() { model_->Render(); }

void ControllerDefault::SetBackgroundColor(const Color& color) {
  model_->SetBackgroundColor(color);
}

void ControllerDefault::SetProjectionType(ProjectionTypes type) {
  model_->SetProjectionType(type);
}

void ControllerDefault::SetShowFloor(bool answer) {
  model_->SetShowFloor(answer);
}

void ControllerDefault::SetShowAxes(bool answer) {
  model_->SetShowAxes(answer);
}

void ControllerDefault::SetLightTrasser(bool answer) {
  model_->SetLightTrasser(answer);
}

// ------------------------------------------------------------------------- //
//                               Objects                                     //
// ------------------------------------------------------------------------- //

ControllerDefault::ReturnCode ControllerDefault::AddObject(
    const std::string& filename, ObjectId& object_id) {
  return model_->AddObject(filename, object_id);
}

void ControllerDefault::CloneObject(ObjectId object_id,
                                    ObjectId& cloned_object) {
  model_->CloneObject(object_id, cloned_object);
}

void ControllerDefault::RemoveObject(ObjectId object_id) {
  model_->RemoveObject(object_id);
}

void ControllerDefault::HideObject(ObjectId object_id, bool answer) {
  model_->HideObject(object_id, answer);
}

void ControllerDefault::RotateObject(ObjectId object_id, AxisId axis,
                                     float value) {
  model_->RotateObject(object_id, axis, value);
}

void ControllerDefault::MoveObject(ObjectId object_id, AxisId axis,
                                   float value) {
  model_->MoveObject(object_id, axis, value);
}

void ControllerDefault::ScaleObject(ObjectId object_id, float value) {
  model_->ScaleObject(object_id, value);
}

void ControllerDefault::SetLineTypeObject(ObjectId object_id, LineTypes type) {
  model_->SetLineTypeObject(object_id, type);
}

void ControllerDefault::SetVertexTypeObject(ObjectId object_id,
                                            VertexTypes type) {
  model_->SetVertexTypeObject(object_id, type);
}

void ControllerDefault::SetLineSizeObject(ObjectId object_id, float size) {
  model_->SetLineSizeObject(object_id, size);
}

void ControllerDefault::SetLineColorObject(ObjectId object_id,
                                           const Color& color) {
  model_->SetLineColorObject(object_id, color);
}

void ControllerDefault::SetVertexColorObject(ObjectId object_id,
                                             const Color& color) {
  model_->SetVertexColorObject(object_id, color);
}

void ControllerDefault::SetVertexSizeObject(ObjectId object_id, float size) {
  model_->SetVertexSizeObject(object_id, size);
}

void ControllerDefault::SetBaseColorObject(ObjectId object_id,
                                           const Color& color) {
  model_->SetBaseColorObject(object_id, color);
}

void ControllerDefault::SetPolygonModeObject(ObjectId object_id,
                                             PolygonMode mode) {
  model_->SetPolygonModeObject(object_id, mode);
}

ControllerDefault::ReturnCode ControllerDefault::SetTextureObject(
    ObjectId object_id, const std::string& filename) {
  return model_->SetTextureObject(object_id, filename);
}

std::string ControllerDefault::GetNameObject(ObjectId object_id) {
  return model_->GetNameObject(object_id);
}

size_t ControllerDefault::GetVerticesCount(ObjectId object_id) {
  return model_->GetVerticesCount(object_id);
}

size_t ControllerDefault::GetEdgesCount(ObjectId object_id) {
  return model_->GetEdgesCount(object_id);
}

// ------------------------------------------------------------------------- //
//                            Light sources                                  //
// ------------------------------------------------------------------------- //

void ControllerDefault::AddLightSource(LightSourceId& light_source_id) {
  model_->AddLightSource(light_source_id);
}

void ControllerDefault::RemoveLightSource(LightSourceId light_source_id) {
  model_->RemoveLightSource(light_source_id);
}

// ------------------------------------------------------------------------- //
//                              Pictures                                     //
// ------------------------------------------------------------------------- //

ControllerDefault::ReturnCode ControllerDefault::SaveImage(
    const std::string& path, ImageType id) {
  return model_->SaveImage(path, id);
}

ControllerDefault::ReturnCode ControllerDefault::StartGif(
    const std::string& path) {
  return model_->StartGif(path);
}

ControllerDefault::ReturnCode ControllerDefault::AddFrame() {
  return model_->AddFrame();
}

ControllerDefault::ReturnCode ControllerDefault::EndGif() {
  return model_->EndGif();
}

}  // namespace s21
