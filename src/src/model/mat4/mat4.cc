// Mat4

#include "mat4.h"

#include <cmath>

namespace s21 {

Mat4 Mat4::MoveMatrix(float x, float y, float z) {
  Mat4 m;

  m(0, 0) = 1;
  m(0, 1) = 0;
  m(0, 2) = 0;
  m(0, 3) = x;

  m(1, 0) = 0;
  m(1, 1) = 1;
  m(1, 2) = 0;
  m(1, 3) = y;

  m(2, 0) = 0;
  m(2, 1) = 0;
  m(2, 2) = 1;
  m(2, 3) = z;

  m(3, 0) = 0;
  m(3, 1) = 0;
  m(3, 2) = 0;
  m(3, 3) = 1;

  return m;
}
Mat4 Mat4::RotateXMatrix(float v) {
  Mat4 m;

  m(0, 0) = 1;
  m(0, 1) = 0;
  m(0, 2) = 0;
  m(0, 3) = 0;

  m(1, 0) = 0;
  m(1, 1) = std::cos(v);
  m(1, 2) = -std::sin(v);
  m(1, 3) = 0;

  m(2, 0) = 0;
  m(2, 1) = std::sin(v);
  m(2, 2) = std::cos(v);
  m(2, 3) = 0;

  m(3, 0) = 0;
  m(3, 1) = 0;
  m(3, 2) = 0;
  m(3, 3) = 1;

  return m;
}
Mat4 Mat4::RotateYMatrix(float v) {
  Mat4 m;

  m(0, 0) = std::cos(v);
  m(0, 1) = 0;
  m(0, 2) = std::sin(v);
  m(0, 3) = 0;

  m(1, 0) = 0;
  m(1, 1) = 1;
  m(1, 2) = 0;
  m(1, 3) = 0;

  m(2, 0) = -std::sin(v);
  m(2, 1) = 0;
  m(2, 2) = std::cos(v);
  m(2, 3) = 0;

  m(3, 0) = 0;
  m(3, 1) = 0;
  m(3, 2) = 0;
  m(3, 3) = 1;

  return m;
}
Mat4 Mat4::RotateZMatrix(float v) {
  Mat4 m;

  m(0, 0) = std::cos(v);
  m(0, 1) = -std::sin(v);
  m(0, 2) = 0;
  m(0, 3) = 0;

  m(1, 0) = std::sin(v);
  m(1, 1) = std::cos(v);
  m(1, 2) = 0;
  m(1, 3) = 0;

  m(2, 0) = 0;
  m(2, 1) = 0;
  m(2, 2) = 1;
  m(2, 3) = 0;

  m(3, 0) = 0;
  m(3, 1) = 0;
  m(3, 2) = 0;
  m(3, 3) = 1;

  return m;
}
Mat4 Mat4::ScaleMatrix(float v) {
  Mat4 m;

  m(0, 0) = v;
  m(0, 1) = 0;
  m(0, 2) = 0;
  m(0, 3) = 0;

  m(1, 0) = 0;
  m(1, 1) = v;
  m(1, 2) = 0;
  m(1, 3) = 0;

  m(2, 0) = 0;
  m(2, 1) = 0;
  m(2, 2) = v;
  m(2, 3) = 0;

  m(3, 0) = 0;
  m(3, 1) = 0;
  m(3, 2) = 0;
  m(3, 3) = 1;

  return m;
}

Mat4::Mat4() : Matrix(4, 4) {
  (*this)(0, 0) = 1;
  (*this)(0, 1) = 0;
  (*this)(0, 2) = 0;
  (*this)(0, 3) = 0;

  (*this)(1, 0) = 0;
  (*this)(1, 1) = 1;
  (*this)(1, 2) = 0;
  (*this)(1, 3) = 0;

  (*this)(2, 0) = 0;
  (*this)(2, 1) = 0;
  (*this)(2, 2) = 1;
  (*this)(2, 3) = 0;

  (*this)(3, 0) = 0;
  (*this)(3, 1) = 0;
  (*this)(3, 2) = 0;
  (*this)(3, 3) = 1;
}

Mat4::~Mat4() {}

void Mat4::Move(float x, float y, float z) {
  (*this)(3, 0) += x;
  (*this)(3, 1) += y;
  (*this)(3, 2) += z;
}

void Mat4::Scale(float v) {
  (*this)(0, 0) *= v;
  (*this)(1, 1) *= v;
  (*this)(2, 2) *= v;
  (*this)(3, 0) *= v;
  (*this)(3, 1) *= v;
  (*this)(3, 2) *= v;
}

void Mat4::RotateX(float v) {
  //
}

void Mat4::RotateY(float v) {
  //
}

void Mat4::RotateZ(float v) {
  //
}

Mat4 Mat4::OthroMatrix(float left, float right, float bottom, float top,
                       float z_near, float z_far) {
  Mat4 m;

  m(0, 0) = 2 / (right - left);
  m(0, 1) = 0;
  m(0, 2) = 0;
  m(0, 3) = -(right + left) / (right - left);

  m(1, 0) = 0;
  m(1, 1) = 2 / (top - bottom);
  m(1, 2) = 0;
  m(1, 3) = -(top + bottom) / (top - bottom);

  m(2, 0) = 0;
  m(2, 1) = 0;
  m(2, 2) = -2 / (z_far - z_near);
  m(2, 3) = -(z_far + z_near) / (z_far - z_near);

  m(3, 0) = 0;
  m(3, 1) = 0;
  m(3, 2) = 0;
  m(3, 3) = 1;

  return m;
}

Mat4 Mat4::PerspectiveMatrix(float fov, float aspect, float z_near,
                             float z_far) {
  Mat4 m;
  value_type const rad = fov;
  value_type tan_half_fov = tan(rad / value_type(2));

  m(0, 0) = value_type(1) / (aspect * tan_half_fov);
  m(0, 1) = 0;
  m(0, 2) = 0;
  m(0, 3) = 0;

  m(1, 0) = 0;
  m(1, 1) = value_type(1) / (tan_half_fov);
  m(1, 2) = 0;
  m(1, 3) = 0;

  m(2, 0) = 0;
  m(2, 1) = 0;
  m(2, 2) = -(z_far + z_near) / (z_far - z_near);
  m(2, 3) = -value_type(1);

  m(3, 0) = 0;
  m(3, 1) = 0;
  m(3, 2) = -(value_type(2) * z_far * z_near) / (z_far - z_near);
  m(3, 3) = 1;

  return m;
}

Mat4 Mat4::FrustoMatrix(float left, float right, float bottom, float top,
                        float z_near, float z_far) {
  Mat4 m;

  m(0, 0) = 2 * z_near / (right - left);
  m(0, 1) = 0;
  m(0, 2) = (right + left) / (right - left);
  m(0, 3) = 0;

  m(1, 0) = 0;
  m(1, 1) = 2 * z_near / (top - bottom);
  m(1, 2) = (top + bottom) / (top - bottom);
  m(1, 3) = 0;

  m(2, 0) = 0;
  m(2, 1) = 0;
  m(2, 2) = -(z_far + z_near) / (z_far - z_near);
  m(2, 3) = -2 * z_far * z_near / (z_far - z_near);

  m(3, 0) = 0;
  m(3, 1) = 0;
  m(3, 2) = -1;
  m(3, 3) = 1;

  return m;
}

Mat4 Mat4::LookAt(const Vec3& eye, const Vec3& center, const Vec3& up) {
  Vec3 x, y, z;
  z = eye;
  z.SubMatrix(center);
  z.Normalize();
  y = up;
  x = y.Cross(z);
  y = z.Cross(x);
  x.Normalize();
  y.Normalize();

  Mat4 mat;
  mat(0, 0) = x(0, 0);
  mat(0, 1) = x(0, 1);
  mat(0, 2) = x(0, 2);
  mat(0, 3) = -x.Dot(eye);
  mat(1, 0) = y(0, 0);
  mat(1, 1) = y(0, 1);
  mat(1, 2) = y(0, 2);
  mat(1, 3) = -y.Dot(eye);
  mat(2, 0) = z(0, 0);
  mat(2, 1) = z(0, 1);
  mat(2, 2) = z(0, 2);
  mat(2, 3) = -z.Dot(eye);
  mat(3, 0) = 0;
  mat(3, 1) = 0;
  mat(3, 2) = 0;
  mat(3, 3) = 1.0f;

  return mat;
}

}  // namespace s21
