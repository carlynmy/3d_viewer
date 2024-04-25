// Declaration class ViewScene

#include "view_scene.h"

#include <cmath>
#include <limits>
#include <memory>
#include <utility>

#include "../color.h"
#include "model/view_object/view_object.h"

namespace s21 {

ViewScene::ViewScene() {
  objects_ = Objects();
  light_sources_ = LightSources();
  background_color_ = Color(0, 0, 0, 0);
  projection_type_ = ProjectionTypes::kPrTypeCentral;
  show_floor_ = false;
  light_trasser_ = false;

  move_x_ = 0.0f;
  move_y_ = 0.0f;
  move_z_ = 0.0f;
  rotate_x_ = 0.0f;
  rotate_y_ = 0.0f;
  rotate_z_ = 0.0f;
  scale_ = 1.0f;

  width_ = 10;
  height_ = 10;

  CreateAxisObjects();
  CreateFloorObject();
  Rotate(AxisId::kAxisX, -M_PI / 4);
  Rotate(AxisId::kAxisY, M_PI / 4);
}

ViewScene::~ViewScene() {}

void ViewScene::SetWidth(int width) { width_ = width; }

void ViewScene::SetHeight(int width) { height_ = width; }

void ViewScene::Rotate(AxisId axis, float value) {
  value *= -1;
  switch (axis) {
    case AxisId::kAxisX:
      rotate_x_ += value;
      break;
    case AxisId::kAxisY:
      rotate_y_ += value;
      break;
    default:
      rotate_z_ += value;
      break;
  }
}

void ViewScene::Move(AxisId axis, float value) {
  value *= -1;
  switch (axis) {
    case AxisId::kAxisX:
      move_x_ += value;
      break;
    case AxisId::kAxisY:
      move_y_ += value;
      break;
    default:
      move_z_ += value;
      break;
  }
}

void ViewScene::Scale(float value) {
  if (value <= 1e-6) return;
  scale_ *= value;
}

void ViewScene::SetBackgroundColor(const Color& color) {
  background_color_ = color;
}

void ViewScene::SetProjectionType(ProjectionTypes type) {
  projection_type_ = type;
}

const Color& ViewScene::GetBackgroundColor() const { return background_color_; }

ViewScene::ProjectionTypes ViewScene::GetProjectionType() const {
  return projection_type_;
}

void ViewScene::SetShowFloor(bool answer) {
  auto iter = objects_.begin();
  for (int i = 0; i < 3; ++i) ++iter;
  iter->SetHide(!answer);
  show_floor_ = answer;
}

bool ViewScene::IsFloorShow() const { return show_floor_; }

void ViewScene::SetShowAxes(bool answer) {
  auto iter = objects_.begin();
  iter->SetHide(!answer);
  ++iter;
  iter->SetHide(!answer);
  ++iter;
  iter->SetHide(!answer);
}

void ViewScene::SetLightTrasser(bool answer) { light_trasser_ = answer; }

bool ViewScene::IsLightTrasser() const { return light_trasser_; }

ViewObject* ViewScene::AddObject(const ViewObject& object) {
  objects_.push_back(object);
  Objects::iterator i = objects_.end();
  --i;
  return &*i;
}

ViewObject* ViewScene::AddObject(ViewObject&& object) {
  objects_.push_back(std::move(object));
  Objects::iterator i = objects_.end();
  --i;
  return &*i;
}

LightSource* ViewScene::AddLightSource(const LightSource& light_source) {
  light_sources_.push_back(light_source);
  LightSources::iterator i = light_sources_.end();
  --i;
  return &*i;
}

LightSource* ViewScene::AddLightSource(LightSource&& light_source) {
  light_sources_.push_back(std::move(light_source));
  LightSources::iterator i = light_sources_.end();
  --i;
  return &*i;
}

void ViewScene::RemoveObject(const ViewObject* object) {
  Objects::iterator iter = objects_.begin();
  while (&*iter != object) ++iter;
  objects_.erase(iter);
}

void ViewScene::RemoveLightSource(const LightSource* light_source) {
  LightSources::iterator iter = light_sources_.begin();
  while (&*iter != light_source) ++iter;
  light_sources_.erase(iter);
}

ViewScene::Objects::iterator ViewScene::BeginObjects() {
  return objects_.begin();
}

ViewScene::Objects::iterator ViewScene::EndObjects() { return objects_.end(); }

ViewScene::LightSources::iterator ViewScene::BeginLightSources() {
  return light_sources_.begin();
}

ViewScene::LightSources::iterator ViewScene::EndLightSources() {
  return light_sources_.end();
}

ViewScene::Objects::const_iterator ViewScene::BeginObjects() const {
  return objects_.begin();
}

ViewScene::Objects::const_iterator ViewScene::EndObjects() const {
  return objects_.end();
}

ViewScene::LightSources::const_iterator ViewScene::BeginLightSources() const {
  return light_sources_.begin();
}

ViewScene::LightSources::const_iterator ViewScene::EndLightSources() const {
  return light_sources_.end();
}

Mat4 ViewScene::GetViewMatrix() const {
  Vec3 camera_pos = Vec3(0.0f, 0.0f, 3.0f);
  Vec3 camera_center = Vec3(0, 0, 0);
  Vec3 camera_up = Vec3(0.0f, 1.0f, 0.0f);

  Mat4 mat = Mat4::LookAt(camera_pos, camera_center, camera_up);
  mat.MulMatrix(Mat4::RotateXMatrix(rotate_x_));
  mat.MulMatrix(Mat4::RotateYMatrix(rotate_y_));
  mat.MulMatrix(Mat4::RotateZMatrix(rotate_z_));
  mat.MulMatrix(Mat4::ScaleMatrix(scale_));
  mat.MulMatrix(Mat4::MoveMatrix(move_x_, move_y_, move_z_));

  return mat;
}

Mat4 ViewScene::GetProjectionMatrix() const {
  Mat4 matrix;
  float ratio = static_cast<float>(width_) / height_;
  float left = -1.0f;
  float right = 1.0f;
  float bottom = -1.0f;
  float top = 1.0f;

  if (width_ > height_) {
    left *= ratio;
    right *= ratio;
  } else {
    bottom /= ratio;
    top /= ratio;
  }

  ViewScene::ProjectionTypes vs_type = GetProjectionType();
  switch (vs_type) {
    case ViewScene::kPrTypeParallel:
      return Mat4::PerspectiveMatrix(M_PI / 4, ratio, 1, -1.0f);
      break;

    default:
      break;
  }
  return Mat4::OthroMatrix(left, right, bottom, top, -100.0, 100.0);

  return matrix;
}

void ViewScene::CreateAxisObjects() {
  ViewObject axis_x, axis_y, axis_z;
  std::shared_ptr<ViewObjectData> axis_x_data(new ViewObjectData);
  std::shared_ptr<ViewObjectData> axis_y_data(new ViewObjectData);
  std::shared_ptr<ViewObjectData> axis_z_data(new ViewObjectData);

  axis_x.SetHide(false);
  axis_x.SetLineType(ViewObject::LineTypes::kLineTypeSolid);
  axis_x.SetVertexType(ViewObject::VertexTypes::kVertexTypeNone);
  axis_x.SetLineSize(1);
  axis_x.SetLineColor(Color(255, 0, 0, 255));
  axis_x.SetVertexColor(Color(255, 0, 0, 255));
  axis_x.SetVertexSize(1);
  axis_x.SetBaseColor(Color(255, 0, 0, 255));

  axis_y.SetHide(false);
  axis_y.SetLineType(ViewObject::LineTypes::kLineTypeSolid);
  axis_y.SetVertexType(ViewObject::VertexTypes::kVertexTypeNone);
  axis_y.SetLineSize(1);
  axis_y.SetLineColor(Color(0, 255, 0, 255));
  axis_y.SetVertexColor(Color(0, 255, 0, 255));
  axis_y.SetVertexSize(1);
  axis_y.SetBaseColor(Color(0, 255, 0, 255));

  axis_z.SetHide(false);
  axis_z.SetLineType(ViewObject::LineTypes::kLineTypeSolid);
  axis_z.SetVertexType(ViewObject::VertexTypes::kVertexTypeNone);
  axis_z.SetLineSize(1);
  axis_z.SetLineColor(Color(0, 0, 255, 255));
  axis_z.SetVertexColor(Color(0, 0, 255, 255));
  axis_z.SetVertexSize(1);
  axis_z.SetBaseColor(Color(0, 0, 255, 255));

  axis_x_data->SetVerticesStorageType(
      ViewObjectData::kVerticesStorageTypeVertices);
  axis_x_data->SetVertices({-100.0f, 0, 0, 100.0f, 0, 0});
  axis_x_data->SetFacesPoint({});
  axis_x_data->SetFacesLine({0, 1});
  axis_x_data->SetFacesTriangle({});
  axis_x_data->SetMaxVertex({ViewObject::kCoefBaseScale});

  axis_y_data->SetVerticesStorageType(
      ViewObjectData::kVerticesStorageTypeVertices);
  axis_y_data->SetVertices({0, -100.0f, 0, 0, 100.0f, 0});
  axis_y_data->SetFacesPoint({});
  axis_y_data->SetFacesLine({0, 1});
  axis_y_data->SetFacesTriangle({});
  axis_y_data->SetMaxVertex({ViewObject::kCoefBaseScale});

  axis_z_data->SetVerticesStorageType(
      ViewObjectData::kVerticesStorageTypeVertices);
  axis_z_data->SetVertices({0, 0, -100.0f, 0, 0, 100.0f});
  axis_z_data->SetFacesPoint({});
  axis_z_data->SetFacesLine({0, 1});
  axis_z_data->SetFacesTriangle({});
  axis_z_data->SetMaxVertex({ViewObject::kCoefBaseScale});

  axis_x.SetData(axis_x_data);
  axis_y.SetData(axis_y_data);
  axis_z.SetData(axis_z_data);

  AddObject(axis_x);
  AddObject(axis_y);
  AddObject(axis_z);
}

void ViewScene::CreateFloorObject() {
  ViewObject floor;
  std::shared_ptr<ViewObjectData> floor_data(new ViewObjectData);

  floor.SetHide(false);
  floor.SetLineType(ViewObject::LineTypes::kLineTypeSolid);
  floor.SetVertexType(ViewObject::VertexTypes::kVertexTypeNone);
  floor.SetLineSize(1);
  floor.SetLineColor(Color(100, 100, 100, 255));
  floor.SetVertexColor(Color(100, 100, 100, 255));
  floor.SetVertexSize(1);
  floor.SetBaseColor(Color(100, 100, 100, 255));

  const float l = -100.0f, r = 100.0f, d = 0.1f;
  std::vector<float> verteces;
  std::vector<uint32_t> indexes;

  for (float curr = l; curr <= r; curr += d) {
    verteces.push_back(curr);
    verteces.push_back(0);
    verteces.push_back(-100.0f);
    indexes.push_back(verteces.size() / 3 - 1);
    verteces.push_back(curr);
    verteces.push_back(0);
    verteces.push_back(100.0f);
    indexes.push_back(verteces.size() / 3 - 1);
  }

  for (float curr = l; curr <= r; curr += d) {
    verteces.push_back(-100.0f);
    verteces.push_back(0);
    verteces.push_back(curr);
    indexes.push_back(verteces.size() / 3 - 1);
    verteces.push_back(100.0f);
    verteces.push_back(0);
    verteces.push_back(curr);
    indexes.push_back(verteces.size() / 3 - 1);
  }

  floor_data->SetVerticesStorageType(
      ViewObjectData::kVerticesStorageTypeVertices);
  floor_data->SetVertices(verteces);
  floor_data->SetFacesPoint({});
  floor_data->SetFacesLine(indexes);
  floor_data->SetFacesTriangle({});
  floor_data->SetMaxVertex({ViewObject::kCoefBaseScale});

  floor.SetData(floor_data);
  AddObject(floor);
}

}  // namespace s21
