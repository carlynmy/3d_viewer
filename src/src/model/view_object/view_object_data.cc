// view object data

#include "view_object_data.h"

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

namespace s21 {

ViewObjectData::ViewObjectData() {}

ViewObjectData::~ViewObjectData() {}

void ViewObjectData::SetName(const std::string& name) { name_ = name; }

void ViewObjectData::SetName(std::string&& name) { name_ = std::move(name); }

void ViewObjectData::SetVerticesStorageType(
    VerticesStorageType vertices_storage_type) {
  vertices_storage_type_ = vertices_storage_type;
}

void ViewObjectData::SetVertices(const std::vector<float>& vertices) {
  vertices_ = vertices;
}

void ViewObjectData::SetVertices(std::vector<float>&& vertices) {
  vertices_ = std::move(vertices);
}

void ViewObjectData::SetFacesPoint(const std::vector<uint32_t>& faces) {
  faces_point_ = faces;
}

void ViewObjectData::SetFacesLine(const std::vector<uint32_t>& faces) {
  faces_line_ = faces;
}

void ViewObjectData::SetFacesTriangle(const std::vector<uint32_t>& faces) {
  faces_triangle_ = faces;
}

void ViewObjectData::SetFacesPoint(std::vector<uint32_t>&& faces) {
  faces_point_ = std::move(faces);
}

void ViewObjectData::SetFacesLine(std::vector<uint32_t>&& faces) {
  faces_line_ = std::move(faces);
}

void ViewObjectData::SetFacesTriangle(std::vector<uint32_t>&& faces) {
  faces_triangle_ = std::move(faces);
}

void ViewObjectData::SetMaxVertex(float value) { max_vertex_ = value; }

const std::string& ViewObjectData::GetName() const { return name_; }

ViewObjectData::VerticesStorageType ViewObjectData::GetVerticesStorageType()
    const {
  return vertices_storage_type_;
}

const std::vector<float>& ViewObjectData::GetVertices() const {
  return vertices_;
}

const std::vector<uint32_t>& ViewObjectData::GetFacesPoint() const {
  return faces_point_;
}

const std::vector<uint32_t>& ViewObjectData::GetFacesLine() const {
  return faces_line_;
}

const std::vector<uint32_t>& ViewObjectData::GetFacesTriangle() const {
  return faces_triangle_;
}

float ViewObjectData::GetMaxVertex() const { return max_vertex_; }

}  // namespace s21
