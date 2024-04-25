// OpengGL

#ifndef _3D_VIEWER_MODEL_RENDEERER_IMP_OPENGL_OPENGL_H_
#define _3D_VIEWER_MODEL_RENDEERER_IMP_OPENGL_OPENGL_H_

#ifndef __APPLE__

#define GLEW_STATIC
#include <GL/glew.h>

#else

#define glGenVertexArrays glGenVertexArraysAPPLE
#define glBindVertexArray glBindVertexArrayAPPLE
#define glDeleteVertexArrays glDeleteVertexArraysAPPLE

#endif  // __APPLE__

#ifndef __APPLE__
#include <GL/gl.h>
#else
#include <OpenGL/gl.h>
#endif  // __APPLE__

#endif  // _3D_VIEWER_MODEL_RENDEERER_IMP_OPENGL_OPENGL_H_
