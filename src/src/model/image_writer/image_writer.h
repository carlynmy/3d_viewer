// Interface image writer

#ifndef _3D_VIEWER_MODEL_IMAGE_WRITER_IMAGE_WRITER_H_
#define _3D_VIEWER_MODEL_IMAGE_WRITER_IMAGE_WRITER_H_

#include <cstdint>
#include <string>
#include <vector>

namespace s21 {

class ImageWriter {
 public:
  enum ReturnCode { kCodeOk, kCodeInvData, kCodeInvFilename };

  ImageWriter() {}
  virtual ~ImageWriter() {}

  virtual ReturnCode Write(const std::string& filename,
                           const std::vector<uint8_t>& bytes, int width,
                           int height) = 0;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_IMAGE_WRITER_IMAGE_WRITER_H_
