// Declaration class ViewObject

#ifndef _3D_VIEWER_MODEL_VIEW_OBJECT_VIEW_OBJECT_H_
#define _3D_VIEWER_MODEL_VIEW_OBJECT_VIEW_OBJECT_H_

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "model/color.h"
#include "model/mat4/mat4.h"
#include "view_object_data.h"

namespace s21 {

class ObjectParser;

class ViewObject {
 public:
  enum ReturnCode { kCodeOk, kCodeFileDontOpen, kCodeInvFile };
  enum AxisId { kAxisX, kAxisY, kAxisZ };
  enum LineTypes { kLineTypeSolid, kLineTypeDotted };
  enum VertexTypes { kVertexTypeNone, kVertexTypeCircle, kVertexTypeSquare };
  using VerticesStorageType = ViewObjectData::VerticesStorageType;
  enum PolygonMode { kPolygonModeLine, kPolygonModeFill, kPolygonModeTexture };
  struct Texture {
    enum Format { kFormatRGB, kFormatRGBA };
    int width_;
    int height_;
    Format format_;
    std::vector<uint8_t> bytes_;
  };

  ViewObject();
  virtual ~ViewObject();

  void SetHide(bool answer);
  void SetLineType(LineTypes type);
  void SetVertexType(VertexTypes type);
  void SetLineSize(float size);
  void SetLineColor(const Color& color);
  void SetVertexColor(const Color& color);
  void SetVertexSize(float size);
  void SetBaseColor(const Color& color);
  void SetName(const std::string& name);
  void SetPolygonMode(PolygonMode mode);
  void SetTexture(const Texture& tex);

  bool IsHide() const;
  LineTypes GetLineType() const;
  VertexTypes GetVertexType() const;
  float GetLineSize() const;
  const Color& GetLineColor() const;
  const Color& GetVertexColor() const;
  float GetVertexSize() const;
  const Color& GetBaseColor() const;
  const std::string& GetName() const;
  PolygonMode GetPolygonMode() const;
  const Texture& GetTexture() const;

  void Rotate(AxisId axis, float value);
  void Move(AxisId axis, float value);
  void Scale(float value);
  void ClearTransformation();

  Mat4 GetModelMatrix() const;

  VerticesStorageType GetVerticesStorageType() const;
  const std::vector<float>& GetVertices() const;
  const std::vector<uint32_t>& GetFacesPoint() const;
  const std::vector<uint32_t>& GetFacesLine() const;
  const std::vector<uint32_t>& GetFacesTriangle() const;

  std::shared_ptr<ViewObjectData> GetData() const;
  void SetData(std::shared_ptr<ViewObjectData> data);

  size_t GetVerticesCount() const;

  size_t GetEdgesCount() const;

  static const float kCoefBaseScale;

 private:
  std::string name_;
  bool is_hide_;
  LineTypes line_type_;
  VertexTypes vertex_type_;
  float line_size_;
  Color line_color_;
  Color vertex_color_;
  float vertex_size_;
  Color base_color_;
  PolygonMode polygon_mode_;
  Texture texture_;

  float max_vertex_;

  float move_x_;
  float move_y_;
  float move_z_;
  float scale_;
  AxisId last_rot_axis_;
  float last_rot_value_;
  Mat4 rotation_matrix_;

  std::shared_ptr<ViewObjectData> data_;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_VIEW_OBJECT_VIEW_OBJECT_H_
