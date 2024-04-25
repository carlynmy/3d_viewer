// delcaration class ShaderKeeper

#ifndef _3D_VIEWER_MODEL_OPENGL_RENDERER_SHADER_KEEPER_SHADER_KEEPER_H_
#define _3D_VIEWER_MODEL_OPENGL_RENDERER_SHADER_KEEPER_SHADER_KEEPER_H_

#include <string>
#include <vector>

#include "../opengl.h"

namespace s21::OpenGLRenderer {

class ShaderKeeper {
 public:
  enum ShaderId {
    kShaderVertexVColor = 0,
    kShaderVertexVTColor,
    kShaderVertexVNColor,
    kShaderVertexVTNColor,
    kShaderVertexVTTexture,
    kShaderVertexVTNTexture,
    kShaderFragmentColor,
    kShaderFragmentTexture,
  };

  static ShaderKeeper* GetInsanse();
  static void FreeInsanse();

  GLuint GetShader(ShaderId id) const;

 private:
  ShaderKeeper();
  virtual ~ShaderKeeper();
  ShaderKeeper(const ShaderKeeper& other) = delete;
  ShaderKeeper(ShaderKeeper&& other) noexcept = delete;
  ShaderKeeper& operator=(const ShaderKeeper& other) = delete;
  ShaderKeeper& operator=(ShaderKeeper&& other) noexcept = delete;

  int ShaderIdToIdx(ShaderId id) const;
  void CreateVertexShader(const char* data, GLuint& shader);
  void CreateFragmentShader(const char* data, GLuint& shader);
  std::string FromFile(const std::string& filename) const;

  static ShaderKeeper* instanse_;

  static const int kShaderCount = 8;
  static const char* kDataShaderVertexVColor;
  static const char* kDataShaderVertexVTColor;
  static const char* kDataShaderVertexVNColor;
  static const char* kDataShaderVertexVTNColor;
  static const char* kDataShaderVertexVTTexture;
  static const char* kDataShaderVertexVTNTexture;
  static const char* kDataShaderFragmentColor;
  static const char* kDataShaderFragmentTexture;

  std::vector<GLuint> shaders_;
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_OPENGL_RENDERER_SHADER_KEEPER_SHADER_KEEPER_H_
