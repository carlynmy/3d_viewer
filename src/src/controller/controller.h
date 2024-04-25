// Declaration class Controller

#ifndef _3D_VIEWER_CONTROLLER_CONTROLLER_H_
#define _3D_VIEWER_CONTROLLER_CONTROLLER_H_

#include <string>

#include "../model/model.h"

namespace s21 {

/// @brief Interface to controller
class Controller {
 public:
  using ReturnCode = Model::ReturnCode;
  using ObjectId = Model::ObjectId;
  using LightSourceId = Model::LightSourceId;
  using AxisId = Model::AxisId;
  using ProjectionTypes = Model::ProjectionTypes;
  using LineTypes = Model::LineTypes;
  using VertexTypes = Model::VertexTypes;
  using ImageType = Model::ImageType;
  using PolygonMode = Model::PolygonMode;

  Controller() {}
  virtual ~Controller() {}

  // ----------------------------------------------------------------------- //
  //                               Canvas                                    //
  // ----------------------------------------------------------------------- //

  /// @brief Set canvas where will be rendering
  virtual void SetCanvas(Canvas* canvas) = 0;

  /// @brief Get canvas
  /// @return Canvas or nullptr if no canvas
  virtual Canvas* GetCanvas() = 0;

  virtual void SetWidth(int widht) = 0;
  virtual void SetHeight(int height) = 0;

  // ----------------------------------------------------------------------- //
  //                                Scene                                    //
  // ----------------------------------------------------------------------- //

  virtual void RotateScene(AxisId axis, float value) = 0;

  virtual void MoveScene(AxisId axis, float value) = 0;

  virtual void ScaleScene(float value) = 0;

  virtual void Render() = 0;

  virtual void SetBackgroundColor(const Color& color) = 0;

  virtual void SetProjectionType(ProjectionTypes type) = 0;

  virtual void SetShowFloor(bool answer) = 0;

  virtual void SetShowAxes(bool answer) = 0;

  virtual void SetLightTrasser(bool answer) = 0;

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
  virtual ReturnCode AddObject(const std::string& filename,
                               ObjectId& object_id) = 0;

  virtual void CloneObject(ObjectId object_id, ObjectId& cloned_object) = 0;

  /// @brief Remove object from scene
  /// @param object_id object id returned by AddObject method
  /// @warning Undefined behavior if object_id is invalid
  virtual void RemoveObject(ObjectId object_id) = 0;

  /// @brief Hide object meens dont draw it
  /// @param object_id object id returned by AddObject method
  /// @warning Undefined behavior if object_id is invalid
  virtual void HideObject(ObjectId object_id, bool answer) = 0;

  /// @brief Rotate object to value by axis
  /// @warning Undefined behavior if object_id is invalid
  virtual void RotateObject(ObjectId object_id, AxisId axis, float value) = 0;

  /// @brief Move object to value by axis
  /// @warning Undefined behavior if object_id is invalid
  virtual void MoveObject(ObjectId object_id, AxisId axis, float value) = 0;

  /// @brief Scale object to value
  /// @warning Undefined behavior if object_id is invalid
  virtual void ScaleObject(ObjectId object_id, float value) = 0;

  /// @warning Undefined behavior if object_id is invalid
  virtual void SetLineTypeObject(ObjectId object_id, LineTypes type) = 0;

  /// @warning Undefined behavior if object_id is invalid
  virtual void SetVertexTypeObject(ObjectId object_id, VertexTypes type) = 0;

  /// @warning Undefined behavior if object_id is invalid
  virtual void SetLineSizeObject(ObjectId object_id, float size) = 0;

  /// @warning Undefined behavior if object_id is invalid
  virtual void SetLineColorObject(ObjectId object_id, const Color& color) = 0;

  /// @warning Undefined behavior if object_id is invalid
  virtual void SetVertexColorObject(ObjectId object_id, const Color& color) = 0;

  /// @warning Undefined behavior if object_id is invalid
  virtual void SetVertexSizeObject(ObjectId object_id, float size) = 0;

  /// @warning Undefined behavior if object_id is invalid
  virtual void SetBaseColorObject(ObjectId object_id, const Color& color) = 0;

  virtual void SetPolygonModeObject(ObjectId object_id, PolygonMode mode) = 0;
  virtual ReturnCode SetTextureObject(ObjectId object_id,
                                      const std::string& filename) = 0;

  /// @warning Undefined behavior if object_id is invalid
  virtual std::string GetNameObject(ObjectId object_id) = 0;

  virtual size_t GetVerticesCount(ObjectId object_id) = 0;

  virtual size_t GetEdgesCount(ObjectId object_id) = 0;

  // ----------------------------------------------------------------------- //
  //                           Light sources                                 //
  // ----------------------------------------------------------------------- //

  virtual void AddLightSource(LightSourceId& light_source_id) = 0;

  virtual void RemoveLightSource(LightSourceId light_source_id) = 0;

  // ----------------------------------------------------------------------- //
  //                             Pictures                                    //
  // ----------------------------------------------------------------------- //

  virtual ReturnCode SaveImage(const std::string& path, ImageType id) = 0;

  virtual ReturnCode StartGif(const std::string& path) = 0;

  virtual ReturnCode AddFrame() = 0;

  virtual ReturnCode EndGif() = 0;
};

}  // namespace s21

#endif  // _3D_VIEWER_CONTROLLER_CONTROLLER_H_
