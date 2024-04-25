// image reader bmp

#include "image_reader_bmp.h"

#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "image_reader.h"

#define STBI_ONLY_BMP
#define STB_IMAGE_IMPLEMENTATION
extern "C" {
#include "stb_image.h"
}

namespace s21 {

ImageReaderBMP::ImageReaderBMP() {}

ImageReaderBMP::~ImageReaderBMP() {}

ImageReaderBMP::ReturnCode ImageReaderBMP::Read(const std::string& filename,
                                                std::vector<uint8_t>& bytes,
                                                int& width, int& height,
                                                int& channels) {
  unsigned char* ptr =
      stbi_load(filename.c_str(), &width, &height, &channels, 3);
  if (ptr == nullptr) return kCodeInvFile;
  if (channels != 3 && channels != 4) {
    stbi_image_free(ptr);
    return kCodeInvFile;
  }

  bytes.resize(width * height * channels + 5);
  for (int i = 0; i < width * height * channels; ++i) {
    bytes[i] = ptr[i];
  }
  stbi_image_free(ptr);

  return kCodeOk;
}

}  // namespace s21
