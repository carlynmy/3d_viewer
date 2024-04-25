// delcaration class ShaderProgrammKeeper

#include "shader_programm_keeper.h"

#include <vector>

#include "../opengl.h"
#include "../shader_keeper/shader_keeper.h"

namespace s21::OpenGLRenderer {

ShaderProgrammKeeper* ShaderProgrammKeeper::instanse_ = nullptr;

ShaderProgrammKeeper* ShaderProgrammKeeper::GetInsanse() {
  if (!instanse_) instanse_ = new ShaderProgrammKeeper();
  return instanse_;
}

void ShaderProgrammKeeper::FreeInsanse() {
  if (!instanse_) {
    delete instanse_;
    instanse_ = nullptr;
  }
}

GLuint ShaderProgrammKeeper::GetShaderProgramm(ShaderProgrammId id) const {
  return shader_programms_[ShaderProgrammIdToIdx(id)];
}

ShaderProgrammKeeper::ShaderProgrammKeeper() {
  shader_programms_.resize(kShaderProgrammCount);
  CreateShaderProgramm(ShaderId::kShaderVertexVColor,
                       ShaderId::kShaderFragmentColor,
                       shader_programms_[ShaderProgrammIdToIdx(kShaderVColor)]);
  CreateShaderProgramm(
      ShaderId::kShaderVertexVTColor, ShaderId::kShaderFragmentColor,
      shader_programms_[ShaderProgrammIdToIdx(kShaderVTColor)]);
  CreateShaderProgramm(
      ShaderId::kShaderVertexVNColor, ShaderId::kShaderFragmentColor,
      shader_programms_[ShaderProgrammIdToIdx(kShaderVNColor)]);
  CreateShaderProgramm(
      ShaderId::kShaderVertexVTNColor, ShaderId::kShaderFragmentColor,
      shader_programms_[ShaderProgrammIdToIdx(kShaderVTNColor)]);
  CreateShaderProgramm(
      ShaderId::kShaderVertexVTTexture, ShaderId::kShaderFragmentTexture,
      shader_programms_[ShaderProgrammIdToIdx(kShaderVTTexture)]);
  CreateShaderProgramm(
      ShaderId::kShaderVertexVTNTexture, ShaderId::kShaderFragmentTexture,
      shader_programms_[ShaderProgrammIdToIdx(kShaderVTNTexture)]);
}

ShaderProgrammKeeper::~ShaderProgrammKeeper() {
  glDeleteProgram(shader_programms_[ShaderProgrammIdToIdx(kShaderVColor)]);
  glDeleteProgram(shader_programms_[ShaderProgrammIdToIdx(kShaderVTColor)]);
  glDeleteProgram(shader_programms_[ShaderProgrammIdToIdx(kShaderVNColor)]);
  glDeleteProgram(shader_programms_[ShaderProgrammIdToIdx(kShaderVTNColor)]);
  glDeleteProgram(shader_programms_[ShaderProgrammIdToIdx(kShaderVTTexture)]);
  glDeleteProgram(shader_programms_[ShaderProgrammIdToIdx(kShaderVTNTexture)]);
}

int ShaderProgrammKeeper::ShaderProgrammIdToIdx(ShaderProgrammId id) const {
  return static_cast<int>(id);
}

void ShaderProgrammKeeper::CreateShaderProgramm(ShaderKeeper::ShaderId v,
                                                ShaderKeeper::ShaderId f,
                                                GLuint& programm) {
  programm = glCreateProgram();
  glAttachShader(programm, ShaderKeeper::GetInsanse()->GetShader(v));
  glAttachShader(programm, ShaderKeeper::GetInsanse()->GetShader(f));
  glLinkProgram(programm);
}

}  // namespace s21::OpenGLRenderer
