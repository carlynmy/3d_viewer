#ifndef _3D_VIEWER_VIEW_MAINWINDOW_MAINWINDOW_H_
#define _3D_VIEWER_VIEW_MAINWINDOW_MAINWINDOW_H_

#include <QColor>
#include <QLabel>
#include <QMainWindow>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QSettings>
#include <QSize>
#include <QSlider>
#include <QTimer>
#include <cmath>
#include <list>

#include "../../controller/controller.h"
#include "../canvas/qt_opengl_canvas.h"
#include "../renderedlight/renderedlight.h"
#include "../renderedobject/renderedobject.h"
#include "../widgetlist/widgetlist.h"

namespace Ui {
class MainWindow;
}

namespace s21 {

class MainWindow : public QMainWindow {
 public:
  using ObjectId = Controller::ObjectId;
  using LightSourceId = Controller::LightSourceId;
  using ReturnCode = Controller::ReturnCode;
  using PolygonMod = Controller::PolygonMode;

  enum SelectedType { kSelectedScene, kSelectedObject, kSelectedLightSource };

  MainWindow(s21::Controller* controller, QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  // Add light or objects
  void ButtonAddObjectsClicked();
  void PrintErrorForNotAddedObject(ReturnCode code);
  void ButtonAddLightClicked();
  void ButtonCloneObjectClicked();

  // Delete light or objects
  void ButtonsRemoveObjectClicked(RenderedObject* obj);

  //  Show or hide widgets on mainwindow
  void ButtonRotateHideClicked();
  void ButtonPositionHideClicked();
  void ButtonSchaleHideClicked();
  void ButtonLinesHideClicked();
  void ButtonVertexHideClicked();
  void ButtonTextureHideClicked();
  void ButtonSpecHideClicked();

  // Widget Position slots
  void SlidersPositionXChanged();
  void SlidersPositionYChanged();
  void SlidersPositionZChanged();
  void LineEditPositionXChanged();
  void LineEditPositionYChanged();
  void LineEditPositionZChanged();

  // Widget Rotation slots
  void SlidersRotationXChanged();
  void SlidersRotationYChanged();
  void SlidersRotationZChanged();
  void LineEditRotationXChanged();
  void LineEditRotationYChanged();
  void LineEditRotationZChanged();

  // Widget Scale slots
  void SlidersScaleChanged();
  void LineEditScaleChanged();

  // Widget Lines slots
  void RadioButtonLinesSolidToggled();
  void RadioButtonLinesDottedToggled();
  void ButtonChangeColorLinesClicked();
  void LineEditSizeLineChanged();

  // Widget Vertex slots
  void ComboBoxVertexTypeChanged();
  void ButtonChangeColorVertexClicked();
  void LineEditSizeVertexChanged();

  // Widget Texture slots
  void ButtonAddTextureClicked();
  void ComboBoxCurrentPolygonModChanged(const QString& text);

  // Widget Spec Function slots
  void ButtonSwitchProjectionClicked();
  void ButtonChangeColorBackgroundClicked();
  void ButtonSaveJPEGClicked();
  void ButtonSaveBMPClicked();
  void ButtonSaveGIFClicked();
  void CheckBoxShowFloorStateChanged();
  void CheckBoxShowAxesStateChanged();

  void SelectObjectCalled(RenderedObject* obj);
  void FromROPolygonToMWPolygon(RenderedObject::PolygonMode mode);
  RenderedObject::PolygonMode FromMWPolygonToROPolygon(
      Controller::PolygonMode mode);
  void SelectLightSourceCalled(RenderedLight* obj, LightSourceId id);
  void SelectScene();
  void ShowHideObjectCalled(RenderedObject* obj, bool state);

  void ShowNumberOfVerticesEdgesCalled(RenderedObject* obj);
  void DeleteObjectInfoCalled();

  void AddFrameToGif();
  void ClearInfoLabel();

 private:
  enum FileType { kJPEG, kBMP, kGIF };

  void InitScrollArea();
  void InitSlider(QSlider* slider, int min, int max, int start_value, int step);
  void InitSliders();
  void UiConnect();
  void InitCanvas();
  void InitLineEdit();

  void RenderedObjectConnects(RenderedObject* obj);
  void ShowHideWidgetConnects();
  void PositionWidgetConnects();
  void RotationWidgetConnects();
  void ScaleWidgetConnects();
  void LinesWidgetConnects();
  void VertexWidgetConnects();
  void TextureWidgetConnects();
  void SpecFuncConnects();

  int FloatToScrollRotate(float value);
  int FloatToScrollMove(float value);
  int FloatToScrollScale(float value);

  float ScroolToFloatRotate(int value);
  float ScroolToFloatMove(int value);
  float ScroolToFloatScale(int value);

  float StringToFloat(const QString& str);

  void UpdatePrevSelected();
  void SetCurrentScrollValues();
  void SetCurrentButtonsColor();
  QString GetColorStyleString(QColor color) const;

  void resizeEvent(QResizeEvent* event) override;
  void closeEvent(QCloseEvent* event) override;

  void SaveSettings();
  void LoadSettings();
  void LoadBackgroundColor(const QSettings& settings);
  void LoadProjection(const QSettings& settings);
  void LoadVertexSettings(const QSettings& settings, RenderedObject* object_id);
  void LoadLineSettings(const QSettings& settings, RenderedObject* object_id);

  void UsePrevObjectSettings(RenderedObject* object_id);
  void UseDefaultObjectSettings(RenderedObject* object_id);
  void UseClonedObjectSettings(RenderedObject* object_id);

  void PrintImageError(ReturnCode code);
  void PrintGifError(ReturnCode code);

  QString CreateNameForFile(FileType type);

  Ui::MainWindow* ui;
  s21::Controller* controller_;
  RenderedObject* new_obj_ = nullptr;
  RenderedObject* old_obj_ = nullptr;
  QTOpenGLCanvas* canvas_;
  QSize size_gl_widget_;
  QLabel* info_label_ = nullptr;
  QTimer timer_;
  QTimer gif_timer_;
  int8_t count_frame_ = 0;
  bool is_gif_started_ = false;

  SelectedType selected_type_;
  union {
    RenderedObject* selected_object_;
    RenderedLight* selected_light_;
  };

  // values scene actions
  float rotate_x_ = 0;
  float rotate_y_ = 0;
  float rotate_z_ = 0;
  float move_x_ = 0;
  float move_y_ = 0;
  float move_z_ = 0;
  float scale_ = 1;

  // current values in scrools and lines
  float current_rotate_x_ = 0;
  float current_rotate_y_ = 0;
  float current_rotate_z_ = 0;
  float current_move_x_ = 0;
  float current_move_y_ = 0;
  float current_move_z_ = 0;
  float current_scale_ = 1;
  uint8_t current_line_type_ = Controller::LineTypes::kLineTypeSolid;
  float current_line_size_ = 1;
  uint8_t current_vertex_type_ = Controller::VertexTypes::kVertexTypeNone;
  float current_vertex_size_ = 1;

  PolygonMod current_polygon_mode_;

  QColor current_line_color_;
  QColor current_vertex_color_;

  // consts to scrool to float cast
  inline static const int kSliderMoveMin = -100;
  inline static const int kSliderMoveMax = 100;
  inline static const int kSliderRotateMin = -100;
  inline static const int kSliderRotateMax = 100;
  inline static const int kSliderScaleMin = 1;
  inline static const int kSliderScaleMax = 100;

  inline static const float kRealMoveMin = -2.0;
  inline static const float kRealMoveMax = 2.0;
  inline static const float kRealRotateMin = -2 * M_PI;
  inline static const float kRealRotateMax = 2 * M_PI;
  inline static const float kRealScaleMin = 0.1;
  inline static const float kRealScaleMax = 10.0;

  // const str for projection
  inline static const std::string kParallel = "Параллельная";
  inline static const std::string kCentral = "Центральная";

  inline static const QString kPolygonModeFillStr = "Полигональная модель";
  inline static const QString kPolygonModeLineStr = "Каркасная модель";
  inline static const QString kPolygonModeTextureStr = "Текстурная модель";

  inline static const QString kVertexTypeNoneStr = "Отсутствуют";
  inline static const QString kVertexTypeCircleStr = "Круглые";
  inline static const QString kVertexTypeSquareStr = "Квадратные";

  static inline const QSize kMinSqrollArea = QSize(260, 0);

  static inline const QSize kMinSizePositionWidget = QSize(240, 30);
  static inline const QSize kMaxSizePositionWidget = QSize(240, 160);

  static inline const QSize kMinSizeRotationWidget = QSize(240, 30);
  static inline const QSize kMaxSizeRotationWidget = QSize(240, 160);

  static inline const QSize kMinSizeScaleWidget = QSize(240, 30);
  static inline const QSize kMaxSizeScaleWidget = QSize(240, 80);

  static inline const QSize kMinSizeVertexWidget = QSize(240, 30);
  static inline const QSize kMaxSizeVertexWidget = QSize(240, 170);

  static inline const QSize kMinSizeLinesWidget = QSize(240, 30);
  static inline const QSize kMaxSizeLinesWidget = QSize(240, 160);

  static inline const QSize kMinSizeTextureWidget = QSize(240, 30);
  static inline const QSize kMaxSizeTextureWidget = QSize(240, 130);

  static inline const QSize kMinSizeSpecWidget = QSize(240, 40);
  static inline const QSize kMaxSizeSpecWidget = QSize(240, 373);

  static inline const QString kShowWindowText = "-";
  static inline const QString kHideWindowText = "-";
};

}  // namespace s21

#endif  // _3D_VIEWER_VIEW_MAINWINDOW_H_
