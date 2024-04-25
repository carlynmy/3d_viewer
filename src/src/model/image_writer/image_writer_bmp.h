// image writer bmp

#ifndef _3D_VIEWER_MODEL_IMAGE_WRITER_IMAGE_WRITER_BMP_H_
#define _3D_VIEWER_MODEL_IMAGE_WRITER_IMAGE_WRITER_BMP_H_

#include <cstdint>
#include <string>
#include <vector>

#include "image_writer.h"

namespace s21 {

class ImageWriterBMP : public ImageWriter {
 public:
  using ReturnCode = ImageWriter::ReturnCode;

  ImageWriterBMP();
  virtual ~ImageWriterBMP();

  ReturnCode Write(const std::string& filename,
                   const std::vector<uint8_t>& bytes, int width,
                   int height) override;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_IMAGE_WRITER_IMAGE_WRITER_BMP_H_
