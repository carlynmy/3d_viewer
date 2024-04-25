cmake_minimum_required(VERSION 3.5)

project(3d_viewer VERSION 0.1 LANGUAGES CXX)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/src/view
  ${CMAKE_CURRENT_SOURCE_DIR}/src/view/mainwindow
  ${CMAKE_CURRENT_SOURCE_DIR}/src/view/widgetlist
  ${CMAKE_CURRENT_SOURCE_DIR}/src/view/renderedlight
  ${CMAKE_CURRENT_SOURCE_DIR}/src/view/renderedobject
  ${QT_INCLUDES}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/3d_party/token_parser/include
  ${CMAKE_CURRENT_SOURCE_DIR}/3d_party/matrix/include  
  ${CMAKE_CURRENT_SOURCE_DIR}/3d_party/gif-h
  ${CMAKE_CURRENT_SOURCE_DIR}/3d_party/stb
  ${CMAKE_CURRENT_SOURCE_DIR}/3d_party/libjpeg
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(
  ${CMAKE_CURRENT_SOURCE_DIR}/3d_party/token_parser
  token_parser
)
add_subdirectory(
  ${CMAKE_CURRENT_SOURCE_DIR}/3d_party/matrix
  matrix
)


set(SOURCE_EXE src/main.cc)	

set(SOURCE_MODEL 
  src/model/model.cc
  src/model/model.h
  src/model/color.h
  src/model/gif_writer/gif_writer.h
  src/model/gif_writer/gif_writer.cc
  src/model/image_reader/image_reader.h
  src/model/image_reader/image_reader_bmp.h
  src/model/image_reader/image_reader_bmp.cc
  src/model/image_reader/factory_image_reader.h
  src/model/image_reader/factory_image_reader.cc
  src/model/image_writer/image_writer.h
  src/model/image_writer/image_writer_bmp.h
  src/model/image_writer/image_writer_bmp.cc
  src/model/image_writer/image_writer_jpeg.h
  src/model/image_writer/image_writer_jpeg.cc
  src/model/image_writer/factory_image_writer.h
  src/model/image_writer/factory_image_writer.cc
  src/model/canvas/canvas.h
  src/model/canvas/opengl_canvas.h
  src/model/mat4/mat4.h
  src/model/mat4/mat4.cc
  src/model/mat4/vec3.h
  src/model/mat4/vec3.cc
  src/model/opengl_renderer/color.h
  src/model/opengl_renderer/opengl.h
  src/model/opengl_renderer/opengl_renderer.h
  src/model/opengl_renderer/opengl_renderer.cc
  src/model/opengl_renderer/light_source/light_source.h
  src/model/opengl_renderer/light_source/light_source.cc
  src/model/opengl_renderer/object/object.h
  src/model/opengl_renderer/object/object_from_view.h
  src/model/opengl_renderer/object/object_from_view.cc
  src/model/opengl_renderer/object_renderer/factory.h
  src/model/opengl_renderer/object_renderer/factory.cc
  src/model/opengl_renderer/object_renderer/object_renderer.h
  src/model/opengl_renderer/object_renderer/object_renderer.cc
  src/model/opengl_renderer/object_renderer/object_renderer_color.h
  src/model/opengl_renderer/object_renderer/object_renderer_color.cc
  src/model/opengl_renderer/object_renderer/object_renderer_texture.h
  src/model/opengl_renderer/object_renderer/object_renderer_texture.cc
  src/model/opengl_renderer/object_renderer/object_renderer_v_color.h
  src/model/opengl_renderer/object_renderer/object_renderer_v_color.cc
  src/model/opengl_renderer/object_renderer/object_renderer_vt_color.h
  src/model/opengl_renderer/object_renderer/object_renderer_vt_color.cc
  src/model/opengl_renderer/object_renderer/object_renderer_vn_color.h
  src/model/opengl_renderer/object_renderer/object_renderer_vn_color.cc
  src/model/opengl_renderer/object_renderer/object_renderer_vtn_color.h
  src/model/opengl_renderer/object_renderer/object_renderer_vtn_color.cc
  src/model/opengl_renderer/object_renderer/object_renderer_vt_texture.h
  src/model/opengl_renderer/object_renderer/object_renderer_vt_texture.cc
  src/model/opengl_renderer/object_renderer/object_renderer_vtn_texture.h
  src/model/opengl_renderer/object_renderer/object_renderer_vtn_texture.cc
  src/model/opengl_renderer/object_renderer_keeper/object_renderer_keeper.h
  src/model/opengl_renderer/object_renderer_keeper/object_renderer_keeper.cc
  src/model/opengl_renderer/scene/scene.h
  src/model/opengl_renderer/scene/scene.cc
  src/model/opengl_renderer/scene/scene_from_view.h
  src/model/opengl_renderer/scene/scene_from_view.cc
  src/model/opengl_renderer/shader_keeper/shader_keeper.h
  src/model/opengl_renderer/shader_keeper/shader_keeper.cc
  src/model/opengl_renderer/shader_programm_keeper/shader_programm_keeper.h
  src/model/opengl_renderer/shader_programm_keeper/shader_programm_keeper.cc
  src/model/renderer/renderer.h
  src/model/renderer/renderer.cc
  src/model/renderer_imp/renderer_imp.h
  src/model/renderer_imp_opengl/renderer_imp_opengl.h
  src/model/renderer_imp_opengl/renderer_imp_opengl.cc
  src/model/view_object/view_object.h
  src/model/view_object/view_object.cc
  src/model/view_object/view_object_data.h
  src/model/view_object/view_object_data.cc
  src/model/view_object/data_parser/factory.h
  src/model/view_object/data_parser/factory.cc
  src/model/view_object/data_parser/parser.h
  src/model/view_object/data_parser/parser_obj.h
  src/model/view_object/data_parser/parser_obj.cc
  src/model/view_object/data_parser/parser_obj_file_data.h
  src/model/view_scene/view_scene.h
  src/model/view_scene/view_scene.cc
)	

set(SOURCE_CONTROLLER
  src/controller/controller.h
  src/controller/controller_default.cc
  src/controller/controller_default.h
)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(SOURCE_VIEW
  src/view/widgetlist/widgetlist.cc
  src/view/widgetlist/widgetlist.h
  src/view/mainwindow/line_widget_slots.cc
  src/view/mainwindow/slider_and_lineedit_scale_slot.cc
  src/view/mainwindow/sliders_and_lineedit_position_slots.cc
  src/view/mainwindow/sliders_and_lineedit_rotation_slots.cc
  src/view/mainwindow/connects.cc
  src/view/mainwindow/initial_setup_of_widgets.cc
  src/view/mainwindow/spec_widget_slots.cc
  src/view/mainwindow/texture_widget_slots.cc
  src/view/mainwindow/utils.cc
  src/view/mainwindow/vertex_widget_slots.cc
  src/view/mainwindow/widget_button_slots.cc  
  src/view/mainwindow/change_mainwindow_widgets.cc
  src/view/mainwindow/mainwindow.cc
  src/view/mainwindow/mainwindow.h
  src/view/mainwindow/mainwindow.ui
  src/view/renderedlight/renderedlight.cc
  src/view/renderedlight/renderedlight.h
  src/view/renderedlight/renderedlight.ui
  src/view/renderedobject/renderedobject.cc
  src/view/renderedobject/renderedobject.h
  src/view/renderedobject/renderedobject.ui
  src/view/canvas/qt_opengl_canvas.cc
  src/view/canvas/qt_opengl_canvas.h
)

set(SOURCE_TEST
  tests/test.cc
  tests/model/test_view_object_data_parser.cc
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-missing-field-initializers")


add_library(model STATIC ${SOURCE_MODEL})

if(APPLE)
  target_link_libraries(model
    "-framework OpenGL"
  )
else()
  target_link_libraries(model
    GL
    GLEW
  )
endif()

add_library(controller STATIC ${SOURCE_CONTROLLER})
add_library(view STATIC ${SOURCE_VIEW})

# Qt${QT_VERSION_MAJOR}::OpenGLWidgets
target_link_libraries(view PRIVATE
  Qt${QT_VERSION_MAJOR}::Widgets
)

add_executable(3d_viewer ${SOURCE_EXE})	

target_link_libraries(3d_viewer
  model
  controller
  view
  Qt${QT_VERSION_MAJOR}::Widgets
  matrix
  token_parser
)

add_executable(3d_viewer_test ${SOURCE_TEST})

target_link_libraries(3d_viewer_test
  model
  matrix
  token_parser
  gtest
) 



# target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# set_target_properties(untitled PROPERTIES
#     MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

# install(TARGETS untitled
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(untitled)
# endif()


