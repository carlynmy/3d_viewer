#ifndef _3D_VIEWER_MODEL_GIF_CREATOR_GIF_CREATOR_H_
#define _3D_VIEWER_MODEL_GIF_CREATOR_GIF_CREATOR_H_

#include <cstdint>
#include <string>
#include <vector>

namespace s21 {

class GifWriter {
 public:
  enum ReturnCode {
    kCodeOk,
    kCodeInvDataOrFileLost,
    kCodeFileDoesntFound,
    kCodeInvFilename
  };

  GifWriter();
  virtual ~GifWriter();

  ReturnCode StartGif(const std::string& filename, int width, int height);

  ReturnCode AddFrame(uint8_t* pixels, int width, int height);

  ReturnCode EndGif();

 private:
  void* writer_;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_GIF_CREATOR_GIF_CREATOR_H_
