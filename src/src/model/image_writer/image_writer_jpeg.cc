#include "image_writer_jpeg.h"

extern "C" {
#include "stb_image_write.h"
}

namespace s21 {
ImageWriterJPEG ::ImageWriterJPEG() {}

ImageWriterJPEG ::~ImageWriterJPEG() {}

ImageWriterJPEG::ReturnCode ImageWriterJPEG::Write(
    const std::string& filename, const std::vector<uint8_t>& bytes, int width,
    int height) {
  int err_code =
      stbi_write_jpg(filename.c_str(), width, height, 4, bytes.data(), 100);
  if (err_code == 0) return ReturnCode::kCodeInvData;

  return ReturnCode::kCodeOk;
}

}  // namespace s21
