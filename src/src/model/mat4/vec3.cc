
#include "vec3.h"

#include <cmath>

#include "matrix.h"

namespace s21 {

Vec3::Vec3(float x, float y, float z) : Matrix(1, 3) {
  (*this)(0, 0) = x;
  (*this)(0, 1) = y;
  (*this)(0, 2) = z;
}

Vec3::~Vec3() {}

void Vec3::Normalize() {
  value_type len = Len();
  (*this)(0, 0) = (*this)(0, 0) / len;
  (*this)(0, 1) = (*this)(0, 1) / len;
  (*this)(0, 2) = (*this)(0, 2) / len;
}

Vec3 Vec3::Cross(const Vec3& other) const {
  Vec3 vec;
  vec(0, 0) = (*this)(0, 1) * (other)(0, 2) - (*this)(0, 2) * (other)(0, 1);
  vec(0, 1) = (*this)(0, 2) * (other)(0, 0) - (*this)(0, 0) * (other)(0, 2);
  vec(0, 2) = (*this)(0, 0) * (other)(0, 1) - (*this)(0, 1) * (other)(0, 0);
  return vec;
}

Vec3::value_type Vec3::Dot(const Vec3& other) const {
  value_type res = ((*this)(0, 0) * (other)(0, 0)) +
                   ((*this)(0, 1) * (other)(0, 1)) +
                   ((*this)(0, 2) * (other)(0, 2));
  return res;
}

Vec3::value_type Vec3::Len() const {
  value_type len = ((*this)(0, 0) * (*this)(0, 0)) +
                   ((*this)(0, 1) * (*this)(0, 1)) +
                   ((*this)(0, 2) * (*this)(0, 2));
  return std::sqrt(len);
}

}  // namespace s21
