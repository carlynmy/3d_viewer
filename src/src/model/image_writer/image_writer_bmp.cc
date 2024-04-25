// image writer bmp

#include "image_writer_bmp.h"

#include <cstdint>
#include <string>
#include <vector>

#include "image_writer.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
extern "C" {
#include "stb_image_write.h"
}

namespace s21 {

ImageWriterBMP::ImageWriterBMP() {}

ImageWriterBMP::~ImageWriterBMP() {}

ImageWriterBMP::ReturnCode ImageWriterBMP::Write(
    const std::string& filename, const std::vector<uint8_t>& bytes, int width,
    int height) {
  int err_code =
      stbi_write_bmp(filename.c_str(), width, height, 4, bytes.data());
  if (err_code == 0) return ReturnCode::kCodeInvData;

  return ReturnCode::kCodeOk;
}

}  // namespace s21
