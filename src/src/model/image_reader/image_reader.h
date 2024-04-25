// Interface image reader

#ifndef _3D_VIEWER_MODEL_IMAGE_READER_IMAGE_READER_H_
#define _3D_VIEWER_MODEL_IMAGE_READER_IMAGE_READER_H_

#include <cstdint>
#include <string>
#include <vector>

namespace s21 {

class ImageReader {
 public:
  enum ReturnCode { kCodeOk, kCodeFileDontOpen, kCodeInvFile };

  ImageReader() {}
  virtual ~ImageReader() {}

  virtual ReturnCode Read(const std::string& filename,
                          std::vector<uint8_t>& bytes, int& width, int& height,
                          int& channels) = 0;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_IMAGE_READER_IMAGE_READER_H_
