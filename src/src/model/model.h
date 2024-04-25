// Declarartion class Model

#ifndef _3D_VIEWER_MODEL_MODEL_H_
#define _3D_VIEWER_MODEL_MODEL_H_

#include "canvas/canvas.h"
#include "color.h"
#include "gif_writer/gif_writer.h"
#include "image_reader/factory_image_reader.h"
#include "image_reader/image_reader.h"
#include "image_writer/factory_image_writer.h"
#include "image_writer/image_writer.h"
#include "renderer/renderer.h"
#include "view_object/data_parser/parser.h"
#include "view_scene/view_scene.h"

namespace s21 {

class Model {
 public:
  enum ReturnCode {
    kCodeOk,
    kCodeInvFilename,
    kCodeInvObjFile,
    kCodeInvData,
    kCodeFileDoesntFound,
    kCodeInvDataOrFileLost,
    kCodeTooBigTexture
  };
  using ObjectId = void*;
  using LightSourceId = void*;
  using AxisId = ViewObject::AxisId;
  using ProjectionTypes = ViewScene::ProjectionTypes;
  using LineTypes = ViewObject::LineTypes;
  using VertexTypes = ViewObject::VertexTypes;
  using ImageType = FactoryImageWriter::ImageType;
  using PolygonMode = ViewObject::PolygonMode;

  Model();
  virtual ~Model();

  // ----------------------------------------------------------------------- //
  //                               Canvas                                    //
  // ----------------------------------------------------------------------- //

  /// @brief Set canvas where will be rendering
  void SetCanvas(Canvas* canvas);

  /// @brief Get canvas
  /// @return Canvas or nullptr if no canvas
  Canvas* GetCanvas();

  void SetWidth(int height);
  void SetHeight(int height);

  // ----------------------------------------------------------------------- //
  //                                Scene                                    //
  // ----------------------------------------------------------------------- //

  void RotateScene(AxisId axis, float value);

  void MoveScene(AxisId axis, float value);

  void ScaleScene(float value);

  void Render();

  void SetBackgroundColor(const Color& color);

  void SetProjectionType(ProjectionTypes type);

  void SetShowFloor(bool answer);

  void SetShowAxes(bool answer);

  void SetLightTrasser(bool answer);

  // ----------------------------------------------------------------------- //
  //                              Objects                                    //
  // ----------------------------------------------------------------------- //

  /// @brief Add object to scene
  /// @param filename filename with object in extention .obj
  /// @param object_id return parametr, object id
  /// @warning If ReturnCode not kCodeOk object_id will invalid
  /// @return kCodeOk if ok.
  /// @return kCodeInvFilename if invalid filename.
  /// @return kCodeInvObjFile if invalid file.
  ReturnCode AddObject(const std::string& filename, ObjectId& object_id);

  /// @brief Clone Object
  void CloneObject(ObjectId object_id, ObjectId& cloned_object);

  /// @brief Remove object from scene
  /// @param object_id object id returned by AddObject method
  /// @warning Undefined behavior if object_id is invalid
  void RemoveObject(ObjectId object_id);

  /// @brief Hide object meens dont draw it
  /// @param object_id object id returned by AddObject method
  /// @warning Undefined behavior if object_id is invalid
  void HideObject(ObjectId object_id, bool answer);

  /// @brief Rotate object to value by axis
  /// @warning Undefined behavior if object_id is invalid
  void RotateObject(ObjectId object_id, AxisId axis, float value);

  /// @brief Move object to value by axis
  /// @warning Undefined behavior if object_id is invalid
  void MoveObject(ObjectId object_id, AxisId axis, float value);

  /// @brief Scale object to value
  /// @warning Undefined behavior if object_id is invalid
  void ScaleObject(ObjectId object_id, float value);

  /// @warning Undefined behavior if object_id is invalid
  void SetLineTypeObject(ObjectId object_id, LineTypes type);

  /// @warning Undefined behavior if object_id is invalid
  void SetVertexTypeObject(ObjectId object_id, VertexTypes type);

  /// @warning Undefined behavior if object_id is invalid
  void SetLineSizeObject(ObjectId object_id, float size);

  /// @warning Undefined behavior if object_id is invalid
  void SetLineColorObject(ObjectId object_id, const Color& color);

  /// @warning Undefined behavior if object_id is invalid
  void SetVertexColorObject(ObjectId object_id, const Color& color);

  /// @warning Undefined behavior if object_id is invalid
  void SetVertexSizeObject(ObjectId object_id, float size);

  /// @warning Undefined behavior if object_id is invalid
  void SetBaseColorObject(ObjectId object_id, const Color& color);

  void SetPolygonModeObject(ObjectId object_id, PolygonMode mode);
  ReturnCode SetTextureObject(ObjectId object_id, const std::string& filename);

  /// @warning Undefined behavior if object_id is invalid
  std::string GetNameObject(ObjectId object_id);

  size_t GetVerticesCount(ObjectId object_id);

  size_t GetEdgesCount(ObjectId object_id);

  // ----------------------------------------------------------------------- //
  //                           Light sources                                 //
  // ----------------------------------------------------------------------- //

  void AddLightSource(LightSourceId& light_source_id);

  void RemoveLightSource(LightSourceId light_source_id);

  // ----------------------------------------------------------------------- //
  //                             Pictures                                    //
  // ----------------------------------------------------------------------- //

  ReturnCode SaveImage(const std::string& path, ImageType id);

  ReturnCode StartGif(const std::string& path);

  ReturnCode AddFrame();

  ReturnCode EndGif();

 private:
  static const int kMaxTextureWidth_;
  static const int kMaxTextureHeight_;

  ViewObject* GetObject(ObjectId object_id);
  ObjectId GetObjectId(ViewObject* object);
  LightSource* GetLightSource(LightSourceId light_source_id);
  LightSourceId GetLightSourceId(LightSource* light_source);

  ReturnCode ViewObjectParserCodeToCode(ViewObjectDataParser::ReturnCode code);
  ReturnCode ImageWriterCodeToCode(ImageWriter::ReturnCode code);
  ReturnCode ImageReaderCodeToCode(ImageReader::ReturnCode code);
  ReturnCode GifWriterCodeToCode(GifWriter::ReturnCode code);

  ViewScene scene_;
  Renderer renderer_;
  Canvas* canvas_;
  GifWriter gif_writer_;
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_MODEL_H_
