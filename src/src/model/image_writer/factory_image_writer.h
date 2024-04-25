#ifndef _3D_VIEWER_MODEL_IMAGE_WRITER_FACTORY_IMAGE_WRITER_H_
#define _3D_VIEWER_MODEL_IMAGE_WRITER_FACTORY_IMAGE_WRITER_H_

#include "image_writer.h"

namespace s21 {

class FactoryImageWriter {
 public:
  enum ImageType { kBMP, kJPEG };
  FactoryImageWriter() {}
  virtual ~FactoryImageWriter() {}

  virtual ImageWriter* Create(ImageType id);
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_IMAGE_WRITER_FACTORY_IMAGE_WRITER_H_