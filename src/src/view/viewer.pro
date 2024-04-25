QT       += core gui opengl

macx {
    QT += openglwidgets
}

TEMPLATE = app

DESTDIR = $$PWD/../../build

TARGET = 3dviewer

QMAKE_CC = gcc


HEADERS += canvas/qt_opengl_canvas.h \
           mainwindow/*.h \
           renderedobject/*.h \
           widgetlist/*.h
    
FORMS +=   mainwindow/*.ui \
           renderedobject/*.ui \
           widgetlist/*.ui

SOURCES += canvas/qt_opengl_canvas.cc \
           mainwindow/*.cc \
           renderedobject/*.cc \
           widgetlist/*.cc

QT += core gui
QT += widgets
CONFIG += object_parallel_to_source
CONFIG += debug
QMAKE_CXXFLAGS += # -Wall -Werror -Wextra -Wno-deprecated-declarations

LIBS+= -lGLEW -lGL

RESOURCES += $$PWD/resources.qrc
UI_DIR += $$PWD/tmp/headers
MOC_DIR = $$PWD/tmp
RCC_DIR = $$PWD/tmp
OBJECTS_DIR = $$PWD/../obj/view/
