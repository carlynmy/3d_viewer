// view object data

#ifndef _3D_VIEWER_MODEL_VIEW_OBJECT_VIEW_OBJECT_DATA_H_
#define _3D_VIEWER_MODEL_VIEW_OBJECT_VIEW_OBJECT_DATA_H_

#include <cstdint>
#include <string>
#include <vector>

namespace s21 {

class ViewObjectData {
 public:
  enum VerticesStorageType {
    kVerticesStorageTypeVertices,
    kVerticesStorageTypeVerticesTexture,
    kVerticesStorageTypeVerticesNormale,
    kVerticesStorageTypeVerticesTextureNormale,
  };

  ViewObjectData();
  virtual ~ViewObjectData();

  void SetName(const std::string& name);
  void SetName(std::string&& name);
  void SetVerticesStorageType(VerticesStorageType vertices_storage_type);
  void SetVertices(const std::vector<float>& vertices);
  void SetVertices(std::vector<float>&& vertices);
  void SetFacesPoint(const std::vector<uint32_t>& faces);
  void SetFacesLine(const std::vector<uint32_t>& faces);
  void SetFacesTriangle(const std::vector<uint32_t>& faces);
  void SetFacesPoint(std::vector<uint32_t>&& faces);
  void SetFacesLine(std::vector<uint32_t>&& faces);
  void SetFacesTriangle(std::vector<uint32_t>&& faces);
  void SetMaxVertex(float value);

  const std::string& GetName() const;
  VerticesStorageType GetVerticesStorageType() const;
  const std::vector<float>& GetVertices() const;
  const std::vector<uint32_t>& GetFacesPoint() const;
  const std::vector<uint32_t>& GetFacesLine() const;
  const std::vector<uint32_t>& GetFacesTriangle() const;
  float GetMaxVertex() const;

 private:
  std::string name_;

  VerticesStorageType vertices_storage_type_;
  std::vector<float> vertices_;

  std::vector<uint32_t> faces_point_;
  std::vector<uint32_t> faces_line_;
  std::vector<uint32_t> faces_triangle_;

  float max_vertex_;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_VIEW_OBJECT_VIEW_OBJECT_DATA_H_
