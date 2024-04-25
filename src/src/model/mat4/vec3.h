// vec3

#ifndef _3D_VIEWER_MODEL_MAT4_VEC3_H_
#define _3D_VIEWER_MODEL_MAT4_VEC3_H_

#include "matrix.h"

namespace s21 {

class Vec3 : public Matrix<float> {
 public:
  using value_type = Matrix::value_type;

  Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
  virtual ~Vec3();

  void Normalize();
  Vec3 Cross(const Vec3& other) const;
  value_type Dot(const Vec3& other) const;
  value_type Len() const;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_MAT4_VEC3H_
