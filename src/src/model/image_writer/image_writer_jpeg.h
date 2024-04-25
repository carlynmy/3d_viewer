// image writer bmp

#ifndef _3D_VIEWER_MODEL_IMAGE_WRITER_IMAGE_WRITER_JPG_H_
#define _3D_VIEWER_MODEL_IMAGE_WRITER_IMAGE_WRITER_JPG_H_

#include <cstdint>
#include <string>
#include <vector>

#include "image_writer.h"

namespace s21 {

class ImageWriterJPEG : public ImageWriter {
 public:
  using ReturnCode = ImageWriter::ReturnCode;

  ImageWriterJPEG();
  virtual ~ImageWriterJPEG();

  ReturnCode Write(const std::string& filename,
                   const std::vector<uint8_t>& bytes, int width,
                   int height) override;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_IMAGE_WRITER_IMAGE_WRITER_JPG_H_
