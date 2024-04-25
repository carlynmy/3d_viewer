#include "gif_writer.h"

extern "C" {
#include "gif.h"
}

namespace s21 {

GifWriter::GifWriter() { writer_ = new ::GifWriter(); }

GifWriter::~GifWriter() { delete reinterpret_cast<::GifWriter*>(writer_); }

GifWriter::ReturnCode GifWriter::StartGif(const std::string& filename,
                                          int width, int height) {
  if (!GifBegin(reinterpret_cast<::GifWriter*>(writer_), filename.c_str(),
                width, height, 2, 8, true))
    return ReturnCode::kCodeInvFilename;
  return ReturnCode::kCodeOk;
}

GifWriter::ReturnCode GifWriter::AddFrame(uint8_t* pixels, int width,
                                          int height) {
  if (!GifWriteFrame(reinterpret_cast<::GifWriter*>(writer_), pixels, width,
                     height, 2, 8, true))
    return ReturnCode::kCodeInvDataOrFileLost;
  return ReturnCode::kCodeOk;
}

GifWriter::ReturnCode GifWriter::EndGif() {
  if (!GifEnd(reinterpret_cast<::GifWriter*>(writer_)))
    return ReturnCode::kCodeFileDoesntFound;
  return ReturnCode::kCodeOk;
}

}  // namespace s21
