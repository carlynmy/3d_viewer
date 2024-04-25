// Declaration class ControllerDefault

#ifndef _3D_VIEWER_CONTROLLER_CONTROLLER_DEFAULT_H_
#define _3D_VIEWER_CONTROLLER_CONTROLLER_DEFAULT_H_

#include "../model/model.h"
#include "controller.h"

namespace s21 {

/// @brief Interface to controller
class ControllerDefault : public Controller {
 public:
  using ReturnCode = Model::ReturnCode;
  using ObjectId = Model::ObjectId;
  using LightSourceId = Model::LightSourceId;
  using AxisId = Model::AxisId;
  using ProjectionTypes = Model::ProjectionTypes;
  using LineTypes = Model::LineTypes;
  using VertexTypes = Model::VertexTypes;
  using PolygonMode = Model::PolygonMode;

  ControllerDefault(Model* model);
  virtual ~ControllerDefault();

  // ----------------------------------------------------------------------- //
  //                               Canvas                                    //
  // ----------------------------------------------------------------------- //

  /// @brief Set canvas where will be rendering
  void SetCanvas(Canvas* canvas) override;

  /// @brief Get canvas
  /// @return Canvas or nullptr if no canvas
  Canvas* GetCanvas() override;

  void SetWidth(int widht) override;
  void SetHeight(int height) override;

  // ----------------------------------------------------------------------- //
  //                                Scene                                    //
  // ----------------------------------------------------------------------- //

  void RotateScene(AxisId axis, float value) override;

  void MoveScene(AxisId axis, float value) override;

  void ScaleScene(float value) override;

  void Render() override;

  void SetBackgroundColor(const Color& color) override;

  void SetProjectionType(ProjectionTypes type) override;

  void SetShowFloor(bool answer) override;

  void SetShowAxes(bool answer) override;

  void SetLightTrasser(bool answer) override;

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
  ReturnCode AddObject(const std::string& filename,
                       ObjectId& object_id) override;

  void CloneObject(ObjectId object_id, ObjectId& cloned_object) override;

  /// @brief Remove object from scene
  /// @param object_id object id returned by AddObject method
  /// @warning Undefined behavior if object_id is invalid
  void RemoveObject(ObjectId object_id) override;

  /// @brief Hide object meens dont draw it
  /// @param object_id object id returned by AddObject method
  /// @warning Undefined behavior if object_id is invalid
  void HideObject(ObjectId object_id, bool answer) override;

  /// @brief Rotate object to value by axis
  /// @warning Undefined behavior if object_id is invalid
  void RotateObject(ObjectId object_id, AxisId axis, float value) override;

  /// @brief Move object to value by axis
  /// @warning Undefined behavior if object_id is invalid
  void MoveObject(ObjectId object_id, AxisId axis, float value) override;

  /// @brief Scale object to value
  /// @warning Undefined behavior if object_id is invalid
  void ScaleObject(ObjectId object_id, float value) override;

  /// @warning Undefined behavior if object_id is invalid
  void SetLineTypeObject(ObjectId object_id, LineTypes type) override;

  /// @warning Undefined behavior if object_id is invalid
  void SetVertexTypeObject(ObjectId object_id, VertexTypes type) override;

  /// @warning Undefined behavior if object_id is invalid
  void SetLineSizeObject(ObjectId object_id, float size) override;

  /// @warning Undefined behavior if object_id is invalid
  void SetLineColorObject(ObjectId object_id, const Color& color) override;

  /// @warning Undefined behavior if object_id is invalid
  void SetVertexColorObject(ObjectId object_id, const Color& color) override;

  /// @warning Undefined behavior if object_id is invalid
  void SetVertexSizeObject(ObjectId object_id, float size) override;

  /// @warning Undefined behavior if object_id is invalid
  void SetBaseColorObject(ObjectId object_id, const Color& color) override;

  void SetPolygonModeObject(ObjectId object_id, PolygonMode mode) override;
  ReturnCode SetTextureObject(ObjectId object_id,
                              const std::string& filename) override;

  /// @warning Undefined behavior if object_id is invalid
  std::string GetNameObject(ObjectId object_id) override;

  size_t GetVerticesCount(ObjectId object_id) override;

  size_t GetEdgesCount(ObjectId object_id) override;

  // ----------------------------------------------------------------------- //
  //                           Light sources                                 //
  // ----------------------------------------------------------------------- //

  void AddLightSource(LightSourceId& light_source_id) override;

  void RemoveLightSource(LightSourceId light_source_id) override;

  // ----------------------------------------------------------------------- //
  //                             Pictures                                    //
  // ----------------------------------------------------------------------- //

  ReturnCode SaveImage(const std::string& path, ImageType id) override;

  ReturnCode StartGif(const std::string& path) override;

  ReturnCode AddFrame() override;

  ReturnCode EndGif() override;

 private:
  Model* model_;
};

}  // namespace s21

#endif  // _3D_VIEWER_CONTROLLER_CONTROLLER_DEFAULT_H_
