// Declaration class Canvas

#ifndef _3D_VIEWER_MODEL_CANVAS_CANVAS_H_
#define _3D_VIEWER_MODEL_CANVAS_CANVAS_H_

namespace s21 {

/// @brief Abstract canvas to render, have only size
class Canvas {
 public:
  Canvas() : Canvas(0, 0) {}

  Canvas(int width, int height) : width_(width), height_(height) {}

  virtual ~Canvas() {}

  void SetWidth(int width) { width_ = width; }
  void SetHeight(int height) { height_ = height; }

  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }

 private:
  int width_;
  int height_;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_CANVAS_H_