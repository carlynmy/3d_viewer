#include "factory_image_reader.h"

#include "image_reader_bmp.h"

namespace s21 {

ImageReader* FactoryImageReader::Create(ImageReaderType id) {
  if (id == ImageReaderType::kBMP) return new ImageReaderBMP;
  return nullptr;
}

}  // namespace s21
