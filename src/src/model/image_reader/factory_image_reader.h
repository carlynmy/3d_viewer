#ifndef _3D_VIEWER_MODEL_IMAGE_READER_FACTORY_IMAGE_READER_H_
#define _3D_VIEWER_MODEL_IMAGE_READER_FACTORY_IMAGE_READER_H_

#include "image_reader.h"

namespace s21 {

class FactoryImageReader {
 public:
  enum ImageReaderType { kBMP };
  FactoryImageReader() {}
  virtual ~FactoryImageReader() {}

  virtual ImageReader* Create(ImageReaderType id);
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_IMAGE_READER_FACTORY_IMAGE_READER_H_