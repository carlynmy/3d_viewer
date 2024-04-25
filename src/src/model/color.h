// Declaration class Color

#ifndef _3D_VIEWER_MODEL_COLOR_H_
#define _3D_VIEWER_MODEL_COLOR_H_

#include <cstdint>

namespace s21 {

class Color {
 public:
  Color() : Color(0, 0, 0, 0) {}

  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
      : r_(r), g_(g), b_(b), a_(a) {}

  virtual ~Color() {}

  void SetR(uint8_t r) { r_ = r; }
  void SetG(uint8_t g) { g_ = g; }
  void SetB(uint8_t b) { b_ = b; }
  void SetA(uint8_t a) { a_ = a; }

  uint8_t GetR() const { return r_; }
  uint8_t GetG() const { return g_; }
  uint8_t GetB() const { return b_; }
  uint8_t GetA() const { return a_; }

 private:
  uint8_t r_;
  uint8_t g_;
  uint8_t b_;
  uint8_t a_;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_COLOR_H_
