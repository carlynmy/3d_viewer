#include "factory_image_writer.h"

#include "image_writer_bmp.h"
#include "image_writer_jpeg.h"

namespace s21 {

ImageWriter* FactoryImageWriter::Create(ImageType id) {
  if (id == ImageType::kBMP) return new ImageWriterBMP;
  if (id == ImageType::kJPEG) return new ImageWriterJPEG;
  return nullptr;
}

}  // namespace s21
