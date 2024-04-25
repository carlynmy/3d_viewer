// mat4

#ifndef _3D_VIEWER_MODEL_MAT4_MAT4_H_
#define _3D_VIEWER_MODEL_MAT4_MAT4_H_

#include "matrix.h"
#include "vec3.h"

namespace s21 {

class Mat4 : public Matrix<float> {
 public:
  using value_type = Matrix::value_type;
  Mat4();
  virtual ~Mat4();

  void Move(float x, float y, float z);
  void Scale(float v);
  void RotateX(float v);
  void RotateY(float v);
  void RotateZ(float v);

  static Mat4 MoveMatrix(float x, float y, float z);
  static Mat4 RotateXMatrix(float v);
  static Mat4 RotateYMatrix(float v);
  static Mat4 RotateZMatrix(float v);
  static Mat4 ScaleMatrix(float v);

  static Mat4 OthroMatrix(float left, float right, float bottom, float top,
                          float z_near, float z_far);

  static Mat4 FrustoMatrix(float left, float right, float bottom, float top,
                           float z_near, float z_far);

  static Mat4 PerspectiveMatrix(float fov, float aspect, float z_near,
                                float z_far);

  static Mat4 LookAt(const Vec3& eye, const Vec3& center, const Vec3& up);
};

//   static Mat4 PerspectiveMatrix(float left, float right, float bottom,
//                                 float top, float z_near, float z_far) {
//     Mat4 m;
//     // m.data_[0 * 4 + 0] = 2 * z_near / (right - left);
//     // m.data_[0 * 4 + 1] = 0;
//     // m.data_[0 * 4 + 2] = (right + left) / (right - left);
//     // m.data_[0 * 4 + 3] = 0;

//     // m.data_[1 * 4 + 0] = 0;
//     // m.data_[1 * 4 + 1] = 2 * z_near / (top - bottom);
//     // m.data_[1 * 4 + 2] = (top + bottom) / (top - bottom);
//     // m.data_[1 * 4 + 3] = 0;

//     // m.data_[2 * 4 + 0] = 0;
//     // m.data_[2 * 4 + 1] = 0;
//     // m.data_[2 * 4 + 2] = -(z_far + z_near) / (z_far - z_near);
//     // m.data_[2 * 4 + 3] = -2 * z_far * z_near / (z_far - z_near);

//     // m.data_[3 * 4 + 0] = 0;
//     // m.data_[3 * 4 + 1] = 0;
//     // m.data_[3 * 4 + 2] = -1;
//     // m.data_[3 * 4 + 3] = 0;

//     // m.data_[0 * 4 + 0] = 2 * z_near / (right - left);
//     // m.data_[1 * 4 + 0] = 0;
//     // m.data_[2 * 4 + 0] = (right + left) / (right - left);
//     // m.data_[3 * 4 + 0] = 0;
//     // m.data_[0 * 4 + 1] = 0;
//     // m.data_[1 * 4 + 1] = 2 * z_near / (top - bottom);
//     // m.data_[2 * 4 + 1] = (top + bottom) / (top - bottom);
//     // m.data_[3 * 4 + 1] = 0;
//     // m.data_[0 * 4 + 2] = 0;
//     // m.data_[1 * 4 + 2] = 0;
//     // m.data_[2 * 4 + 2] = -(z_far + z_near) / (z_far - z_near);
//     // m.data_[3 * 4 + 2] = -2 * z_far * z_near / (z_far - z_near);
//     // m.data_[0 * 4 + 3] = 0;
//     // m.data_[1 * 4 + 3] = 0;
//     // m.data_[2 * 4 + 3] = -1;
//     // m.data_[3 * 4 + 3] = 0;

//     m.data_[0 * 4 + 0] = 1;
//     m.data_[0 * 4 + 1] = 0;
//     m.data_[0 * 4 + 2] = 0;
//     m.data_[0 * 4 + 3] = 0;

//     m.data_[1 * 4 + 0] = 1;
//     m.data_[1 * 4 + 1] = 0;
//     m.data_[1 * 4 + 2] = 0;
//     m.data_[1 * 4 + 3] = 0;
//     m.data_[2 * 4 + 0] = 0;
//     m.data_[2 * 4 + 1] = 0;
//     m.data_[2 * 4 + 2] = -(z_far + z_near) / (z_far - z_near);
//     m.data_[2 * 4 + 3] = 1;
//     m.data_[3 * 4 + 0] = 0;
//     m.data_[3 * 4 + 1] = 0;
//     m.data_[3 * 4 + 2] = -(2 * z_far * z_near) / (z_far - z_near);
//     m.data_[3 * 4 + 3] = 0;

//     return m;
//   }

//   static Mat4 PerspectiveMatrix1(float fov, float aspect, float z_near,
//                                  float z_far) {
//     float f = 1.0 / tan(fov / 2);
//     Mat4 m;
//     m.data_[0 * 4 + 0] = f / aspect;
//     m.data_[1 * 4 + 0] = 0;
//     m.data_[2 * 4 + 0] = 0;
//     m.data_[3 * 4 + 0] = 0;
//     m.data_[0 * 4 + 1] = 0;
//     m.data_[1 * 4 + 1] = 1;
//     m.data_[2 * 4 + 1] = 0;
//     m.data_[3 * 4 + 1] = 0;
//     m.data_[0 * 4 + 2] = 0;
//     m.data_[1 * 4 + 2] = 0;
//     m.data_[2 * 4 + 2] = -(z_far + z_near) / (z_far - z_near);
//     m.data_[3 * 4 + 2] = -(2 * z_far * z_near) / (z_far - z_near);
//     m.data_[0 * 4 + 3] = 0;
//     m.data_[1 * 4 + 3] = 0;
//     m.data_[2 * 4 + 3] = -1;
//     m.data_[3 * 4 + 3] = 1;

//     return m;
//   }

//  private:
//   float* data_;
// };

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_MAT4_MAT4_H_
