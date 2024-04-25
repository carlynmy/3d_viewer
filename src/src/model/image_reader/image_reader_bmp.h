// image reader bmp

#ifndef _3D_VIEWER_MODEL_IMAGE_READER_IMAGE_READER_BMP_H_
#define _3D_VIEWER_MODEL_IMAGE_READER_IMAGE_READER_BMP_H_

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

#include "image_reader.h"

namespace s21 {

class ImageReaderBMP : public ImageReader {
 public:
  using ReturnCode = ImageReader::ReturnCode;

  ImageReaderBMP();
  virtual ~ImageReaderBMP();

  ReturnCode Read(const std::string& filename, std::vector<uint8_t>& bytes,
                  int& width, int& height, int& chanells) override;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_IMAGE_READER_IMAGE_READER_BMP_H_
