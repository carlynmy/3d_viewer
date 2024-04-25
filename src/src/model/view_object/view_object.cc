// Implementation class ViewObject

#include "view_object.h"

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "model/color.h"
#include "model/mat4/mat4.h"
#include "view_object_data.h"

namespace s21 {

const float ViewObject::kCoefBaseScale = 0.5;

ViewObject::ViewObject() {
  name_ = "";
  is_hide_ = false;
  line_type_ = LineTypes::kLineTypeSolid;
  vertex_type_ = VertexTypes::kVertexTypeNone;
  line_size_ = 1.0;
  line_color_ = Color(0, 0, 255, 0);
  vertex_color_ = Color(255, 0, 0, 0);
  vertex_size_ = 1.0;
  polygon_mode_ = PolygonMode::kPolygonModeLine;
  texture_.format_ = Texture::Format::kFormatRGB;
  texture_.height_ = 0;
  texture_.width_ = 0;

  base_color_ = Color(0, 255, 0, 0);
  max_vertex_ = 0;

  move_x_ = 0;
  move_y_ = 0;
  move_z_ = 0;
  scale_ = 1;
  last_rot_axis_ = kAxisX;
  last_rot_value_ = 0;

  data_ = nullptr;
}

ViewObject::~ViewObject() {}

void ViewObject::SetHide(bool answer) { is_hide_ = answer; }

void ViewObject::SetLineType(LineTypes type) { line_type_ = type; }

void ViewObject::SetVertexType(VertexTypes type) { vertex_type_ = type; }

void ViewObject::SetLineSize(float size) { line_size_ = size; }

void ViewObject::SetLineColor(const Color& color) { line_color_ = color; }

void ViewObject::SetVertexColor(const Color& color) { vertex_color_ = color; }

void ViewObject::SetVertexSize(float size) { vertex_size_ = size; }

void ViewObject::SetBaseColor(const Color& color) { base_color_ = color; }

void ViewObject::SetName(const std::string& name) { name_ = name; }

bool ViewObject::IsHide() const { return is_hide_; }

void ViewObject::SetPolygonMode(PolygonMode mode) { polygon_mode_ = mode; }

void ViewObject::SetTexture(const Texture& tex) { texture_ = tex; }

ViewObject::LineTypes ViewObject::GetLineType() const { return line_type_; }

ViewObject::VertexTypes ViewObject::GetVertexType() const {
  return vertex_type_;
}

float ViewObject::GetLineSize() const { return line_size_; }

const Color& ViewObject::GetLineColor() const { return line_color_; }

const Color& ViewObject::GetVertexColor() const { return vertex_color_; }

float ViewObject::GetVertexSize() const { return vertex_size_; }

const Color& ViewObject::GetBaseColor() const { return base_color_; }

const std::string& ViewObject::GetName() const { return name_; }

ViewObject::PolygonMode ViewObject::GetPolygonMode() const {
  return polygon_mode_;
}

const ViewObject::Texture& ViewObject::GetTexture() const { return texture_; }

void ViewObject::Rotate(AxisId axis, float value) {
  if (axis == last_rot_axis_) {
    last_rot_value_ += value;

  } else {
    switch (last_rot_axis_) {
      case kAxisX:
        rotation_matrix_.MulMatrix(Mat4::RotateXMatrix(last_rot_value_));
        break;

      case kAxisY:
        rotation_matrix_.MulMatrix(Mat4::RotateYMatrix(last_rot_value_));
        break;

      default:
        rotation_matrix_.MulMatrix(Mat4::RotateZMatrix(last_rot_value_));
        break;
    }

    last_rot_axis_ = axis;
    last_rot_value_ = value;
  }
}

void ViewObject::Move(AxisId axis, float value) {
  switch (axis) {
    case AxisId::kAxisX:
      move_x_ += value;
      break;

    case AxisId::kAxisY:
      move_y_ += value;
      break;

    case AxisId::kAxisZ:
      move_z_ += value;
      break;

    default:
      break;
  }
}

void ViewObject::Scale(float value) {
  if (value <= 1e-6) return;
  scale_ *= value;
}

void ViewObject::ClearTransformation() {
  move_x_ = 0;
  move_y_ = 0;
  move_z_ = 0;
  scale_ = 0;

  last_rot_axis_ = kAxisX;
  last_rot_value_ = 0;
  rotation_matrix_ = Mat4();
}

Mat4 ViewObject::GetModelMatrix() const {
  Mat4 view_matrix;
  view_matrix.MulMatrix(Mat4::MoveMatrix(move_x_, move_y_, move_z_));
  view_matrix.MulMatrix(
      Mat4::ScaleMatrix(scale_ * kCoefBaseScale / data_->GetMaxVertex()));
  view_matrix.MulMatrix(rotation_matrix_);
  switch (last_rot_axis_) {
    case kAxisX:
      view_matrix.MulMatrix(Mat4::RotateXMatrix(last_rot_value_));
      break;

    case kAxisY:
      view_matrix.MulMatrix(Mat4::RotateYMatrix(last_rot_value_));
      break;

    default:
      view_matrix.MulMatrix(Mat4::RotateZMatrix(last_rot_value_));
      break;
  }

  return view_matrix;
}

ViewObject::VerticesStorageType ViewObject::GetVerticesStorageType() const {
  return data_->GetVerticesStorageType();
}

size_t ViewObject::GetVerticesCount() const {
  switch (GetVerticesStorageType()) {
    case VerticesStorageType::kVerticesStorageTypeVertices:
      return GetVertices().size() / 3;
      break;
    case VerticesStorageType::kVerticesStorageTypeVerticesTexture:
      return GetVertices().size() / 5;
      break;
    case VerticesStorageType::kVerticesStorageTypeVerticesNormale:
      return GetVertices().size() / 6;
      break;
    default:
      break;
  }

  return GetVertices().size() / 8;
}

size_t ViewObject::GetEdgesCount() const {
  return GetFacesLine().size() / 2 + GetFacesTriangle().size() / 3;
}

const std::vector<float>& ViewObject::GetVertices() const {
  return data_->GetVertices();
}

const std::vector<uint32_t>& ViewObject::GetFacesPoint() const {
  return data_->GetFacesPoint();
}

const std::vector<uint32_t>& ViewObject::GetFacesLine() const {
  return data_->GetFacesLine();
}

const std::vector<uint32_t>& ViewObject::GetFacesTriangle() const {
  return data_->GetFacesTriangle();
}

std::shared_ptr<ViewObjectData> ViewObject::GetData() const { return data_; }

void ViewObject::SetData(std::shared_ptr<ViewObjectData> data) { data_ = data; }

}  // namespace s21
