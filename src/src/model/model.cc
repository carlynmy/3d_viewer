// Implementation class Model

#include "model.h"

#include <memory>
#include <utility>

#include "canvas/canvas.h"
#include "color.h"
#include "renderer/renderer.h"
#include "view_object/data_parser/factory.h"
#include "view_object/data_parser/parser.h"
#include "view_object/view_object.h"
#include "view_object/view_object_data.h"
#include "view_scene/view_scene.h"

namespace s21 {

const int Model::kMaxTextureWidth_ = 1000;
const int Model::kMaxTextureHeight_ = 1000;

Model::Model() {}

Model::~Model() {}

// ----------------------------------------------------------------------- //
//                               Canvas                                    //
// ----------------------------------------------------------------------- //

void Model::SetCanvas(Canvas* canvas) { canvas_ = canvas; }

Canvas* Model::GetCanvas() { return canvas_; }

void Model::SetWidth(int height) {
  canvas_->SetWidth(height);
  scene_.SetWidth(height);
}

void Model::SetHeight(int height) {
  canvas_->SetHeight(height);
  scene_.SetHeight(height);
}

// ----------------------------------------------------------------------- //
//                                Scene                                    //
// ----------------------------------------------------------------------- //

void Model::RotateScene(AxisId axis, float value) {
  scene_.Rotate(axis, value);
}

void Model::MoveScene(AxisId axis, float value) { scene_.Move(axis, value); }

void Model::ScaleScene(float value) { scene_.Scale(value); }

void Model::Render() { renderer_.Render(&scene_, canvas_); }

void Model::SetBackgroundColor(const Color& color) {
  scene_.SetBackgroundColor(color);
}

void Model::SetProjectionType(ProjectionTypes type) {
  scene_.SetProjectionType(type);
}

void Model::SetShowFloor(bool answer) { scene_.SetShowFloor(answer); }

void Model::SetShowAxes(bool answer) { scene_.SetShowAxes(answer); }

void Model::SetLightTrasser(bool answer) { scene_.SetLightTrasser(answer); }

// ----------------------------------------------------------------------- //
//                              Objects                                    //
// ----------------------------------------------------------------------- //

Model::ReturnCode Model::AddObject(const std::string& filename,
                                   ObjectId& object_id) {
  ViewObjectDataParserFactory factory;
  ViewObjectDataParser* parser =
      factory.Create(ViewObjectDataParserFactory::kTypeObj);
  std::shared_ptr<ViewObjectData> object_data(new ViewObjectData());
  ViewObjectDataParser::ReturnCode parser_code =
      parser->Parse(filename, *object_data);

  delete parser;

  ReturnCode code = ViewObjectParserCodeToCode(parser_code);
  if (code != kCodeOk) return code;

  ViewObject object;
  object.SetData(object_data);
  object.SetName(object_data->GetName());
  object_id = GetObjectId(scene_.AddObject(object));
  return kCodeOk;
}

void Model::CloneObject(ObjectId object_id, ObjectId& cloned_object) {
  ViewObject new_object;
  ViewObject* object = GetObject(object_id);
  new_object.SetData(object->GetData());
  new_object.SetName(object->GetName() + " copy");
  cloned_object = object_id = GetObjectId(scene_.AddObject(new_object));
}

void Model::RemoveObject(ObjectId object_id) {
  scene_.RemoveObject(GetObject(object_id));
}

void Model::HideObject(ObjectId object_id, bool answer) {
  GetObject(object_id)->SetHide(answer);
}

void Model::RotateObject(ObjectId object_id, AxisId axis, float value) {
  GetObject(object_id)->Rotate(axis, value);
}

void Model::MoveObject(ObjectId object_id, AxisId axis, float value) {
  GetObject(object_id)->Move(axis, value);
}

void Model::ScaleObject(ObjectId object_id, float value) {
  GetObject(object_id)->Scale(value);
}

void Model::SetLineTypeObject(ObjectId object_id, LineTypes type) {
  GetObject(object_id)->SetLineType(type);
}

void Model::SetVertexTypeObject(ObjectId object_id, VertexTypes type) {
  GetObject(object_id)->SetVertexType(type);
}

void Model::SetLineSizeObject(ObjectId object_id, float size) {
  GetObject(object_id)->SetLineSize(size);
}

void Model::SetLineColorObject(ObjectId object_id, const Color& color) {
  GetObject(object_id)->SetLineColor(color);
}

void Model::SetVertexColorObject(ObjectId object_id, const Color& color) {
  GetObject(object_id)->SetVertexColor(color);
}

void Model::SetVertexSizeObject(ObjectId object_id, float size) {
  GetObject(object_id)->SetVertexSize(size);
}

void Model::SetBaseColorObject(ObjectId object_id, const Color& color) {
  GetObject(object_id)->SetBaseColor(color);
}

void Model::SetPolygonModeObject(ObjectId object_id, PolygonMode mode) {
  GetObject(object_id)->SetPolygonMode(mode);
}

Model::ReturnCode Model::SetTextureObject(ObjectId object_id,
                                          const std::string& filename) {
  FactoryImageReader factory;
  ImageReader* reader =
      factory.Create(FactoryImageReader::ImageReaderType::kBMP);
  ViewObject::Texture tex;
  int channels = 3;
  ImageReader::ReturnCode code =
      reader->Read(filename, tex.bytes_, tex.width_, tex.height_, channels);
  tex.format_ = ViewObject::Texture::Format::kFormatRGB;
  if (channels == 4) tex.format_ = ViewObject::Texture::Format::kFormatRGBA;

  delete reader;

  if (code != ImageReader::ReturnCode::kCodeOk)
    return ImageReaderCodeToCode(code);
  if (tex.width_ > kMaxTextureWidth_ || tex.height_ > kMaxTextureHeight_)
    return ReturnCode::kCodeTooBigTexture;

  GetObject(object_id)->SetTexture(tex);
  return ReturnCode::kCodeOk;
}

std::string Model::GetNameObject(ObjectId object_id) {
  return GetObject(object_id)->GetName();
}

size_t Model::GetVerticesCount(ObjectId object_id) {
  return GetObject(object_id)->GetVerticesCount();
}

size_t Model::GetEdgesCount(ObjectId object_id) {
  return GetObject(object_id)->GetEdgesCount();
}

// ----------------------------------------------------------------------- //
//                           Light sources                                 //
// ----------------------------------------------------------------------- //

void Model::AddLightSource(LightSourceId& light_source_id) {
  (void)light_source_id;
}

void Model::RemoveLightSource(LightSourceId light_source_id) {
  (void)light_source_id;
}

// ----------------------------------------------------------------------- //
//                               Utils                                     //
// ----------------------------------------------------------------------- //

ViewObject* Model::GetObject(ObjectId object_id) {
  return reinterpret_cast<ViewObject*>(object_id);
}

Model::ObjectId Model::GetObjectId(ViewObject* object) {
  return reinterpret_cast<ObjectId>(object);
}

LightSource* Model::GetLightSource(LightSourceId light_source_id) {
  return reinterpret_cast<LightSource*>(light_source_id);
}

Model::LightSourceId Model::GetLightSourceId(LightSource* light_source) {
  return reinterpret_cast<LightSourceId>(light_source);
}

Model::ReturnCode Model::ViewObjectParserCodeToCode(
    ViewObjectDataParser::ReturnCode parser_code) {
  switch (parser_code) {
    case ViewObjectDataParser::ReturnCode::kCodeFileDontOpen:
      return ReturnCode::kCodeInvFilename;
      break;
    case ViewObjectDataParser::ReturnCode::kCodeInvalidFile:
      return ReturnCode::kCodeInvObjFile;
      break;
    default:
      break;
  }
  return kCodeOk;
}

Model::ReturnCode Model::ImageWriterCodeToCode(ImageWriter::ReturnCode code) {
  switch (code) {
    case ImageWriter::ReturnCode::kCodeInvData:
      return ReturnCode::kCodeInvData;
      break;

    default:
      break;
  }
  return ReturnCode::kCodeOk;
}

Model::ReturnCode Model::ImageReaderCodeToCode(ImageReader::ReturnCode code) {
  switch (code) {
    case ImageReader::ReturnCode::kCodeFileDontOpen:
      return ReturnCode::kCodeFileDoesntFound;
      break;
    case ImageReader::ReturnCode::kCodeInvFile:
      return ReturnCode::kCodeInvDataOrFileLost;
      break;
    default:
      break;
  }
  return ReturnCode::kCodeOk;
}

Model::ReturnCode Model::GifWriterCodeToCode(GifWriter::ReturnCode code) {
  switch (code) {
    case GifWriter::ReturnCode::kCodeFileDoesntFound:
      return ReturnCode::kCodeInvFilename;
      break;
    case GifWriter::ReturnCode::kCodeInvDataOrFileLost:
      return ReturnCode::kCodeInvDataOrFileLost;
      break;
    case GifWriter::ReturnCode::kCodeInvFilename:
      return ReturnCode::kCodeInvFilename;
      break;
    default:
      break;
  }
  return ReturnCode::kCodeOk;
}

// ------------------------------------------------------------------------- //
//                              Pictures                                     //
// ------------------------------------------------------------------------- //

Model::ReturnCode Model::SaveImage(const std::string& path, ImageType id) {
  int width = canvas_->GetWidth();
  int heigth = canvas_->GetHeight();
  std::vector<uint8_t> pixels =
      renderer_.GetPixels(&scene_, canvas_, width, heigth);

  FactoryImageWriter factory;
  ImageWriter* writer = factory.Create(id);

  ImageWriter::ReturnCode code = writer->Write(path, pixels, width, heigth);

  delete writer;

  return ImageWriterCodeToCode(code);
}

Model::ReturnCode Model::StartGif(const std::string& path) {
  int width = canvas_->GetWidth();
  int heigth = canvas_->GetHeight();
  GifWriter::ReturnCode code = gif_writer_.StartGif(path, width, heigth);

  return GifWriterCodeToCode(code);
}

Model::ReturnCode Model::AddFrame() {
  int width = canvas_->GetWidth();
  int heigth = canvas_->GetHeight();
  std::vector<uint8_t> pixels =
      renderer_.GetPixels(&scene_, canvas_, width, heigth);
  GifWriter::ReturnCode code =
      gif_writer_.AddFrame(pixels.data(), width, heigth);

  return GifWriterCodeToCode(code);
}

Model::ReturnCode Model::EndGif() {
  GifWriter::ReturnCode code = gif_writer_.EndGif();
  return GifWriterCodeToCode(code);
}

}  // namespace s21
