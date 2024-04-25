// delcaration class ShaderProgrammKeeper

#ifndef _3D_VIEWER_MODEL_OPENGL_RENDERER_SHADER_PROGRAMM_KEEPER_SHADER_PROGRAMM_KEEPER_H_
#define _3D_VIEWER_MODEL_OPENGL_RENDERER_SHADER_PROGRAMM_KEEPER_SHADER_PROGRAMM_KEEPER_H_

#include <vector>

#include "../opengl.h"
#include "../shader_keeper/shader_keeper.h"

namespace s21::OpenGLRenderer {

class ShaderProgrammKeeper {
 public:
  enum ShaderProgrammId {
    kShaderVColor = 0,
    kShaderVTColor,
    kShaderVNColor,
    kShaderVTNColor,
    kShaderVTTexture,
    kShaderVTNTexture,
  };

  static ShaderProgrammKeeper* GetInsanse();
  static void FreeInsanse();

  GLuint GetShaderProgramm(ShaderProgrammId id) const;

 private:
  using ShaderId = ShaderKeeper::ShaderId;

  ShaderProgrammKeeper();
  virtual ~ShaderProgrammKeeper();
  ShaderProgrammKeeper(const ShaderProgrammKeeper& other) = delete;
  ShaderProgrammKeeper(ShaderProgrammKeeper&& other) noexcept = delete;
  ShaderProgrammKeeper& operator=(const ShaderProgrammKeeper& other) = delete;
  ShaderProgrammKeeper& operator=(ShaderProgrammKeeper&& other) noexcept =
      delete;

  int ShaderProgrammIdToIdx(ShaderProgrammId id) const;

  void CreateShaderProgramm(ShaderKeeper::ShaderId v, ShaderKeeper::ShaderId f,
                            GLuint& programm);

  static ShaderProgrammKeeper* instanse_;
  static const int kShaderProgrammCount = 6;

  std::vector<GLuint> shader_programms_;
};

}  // namespace s21::OpenGLRenderer

#endif  // _3D_VIEWER_MODEL_OPENGL_RENDERER_SHADER_PROGRAMM_KEEPER_SHADER_PROGRAMM_KEEPER_H_
