// implementation class ShaderKeeper

#include "shader_keeper.h"

#include <cstddef>
#include <fstream>
#include <string>
#include <utility>

#include "../opengl.h"

namespace s21::OpenGLRenderer {

ShaderKeeper* ShaderKeeper::instanse_ = nullptr;

ShaderKeeper* ShaderKeeper::GetInsanse() {
  if (!instanse_) instanse_ = new ShaderKeeper();
  return instanse_;
}

void ShaderKeeper::FreeInsanse() {
  if (instanse_) {
    delete instanse_;
    instanse_ = nullptr;
  }
}

GLuint ShaderKeeper::GetShader(ShaderId id) const {
  return shaders_[ShaderIdToIdx(id)];
}

ShaderKeeper::ShaderKeeper() {
  shaders_.resize(kShaderCount);
  CreateVertexShader(kDataShaderVertexVColor,
                     shaders_[ShaderIdToIdx(kShaderVertexVColor)]);
  CreateVertexShader(kDataShaderVertexVTColor,
                     shaders_[ShaderIdToIdx(kShaderVertexVTColor)]);
  CreateVertexShader(kDataShaderVertexVNColor,
                     shaders_[ShaderIdToIdx(kShaderVertexVNColor)]);
  CreateVertexShader(kDataShaderVertexVTNColor,
                     shaders_[ShaderIdToIdx(kShaderVertexVTNColor)]);
  CreateVertexShader(kDataShaderVertexVTTexture,
                     shaders_[ShaderIdToIdx(kShaderVertexVTTexture)]);
  CreateVertexShader(kDataShaderVertexVTNTexture,
                     shaders_[ShaderIdToIdx(kShaderVertexVTNTexture)]);
  CreateFragmentShader(kDataShaderFragmentColor,
                       shaders_[ShaderIdToIdx(kShaderFragmentColor)]);
  CreateFragmentShader(kDataShaderFragmentTexture,
                       shaders_[ShaderIdToIdx(kShaderFragmentTexture)]);
}

ShaderKeeper::~ShaderKeeper() {
  glDeleteShader(shaders_[ShaderIdToIdx(kShaderVertexVColor)]);
  glDeleteShader(shaders_[ShaderIdToIdx(kShaderVertexVTColor)]);
  glDeleteShader(shaders_[ShaderIdToIdx(kShaderVertexVNColor)]);
  glDeleteShader(shaders_[ShaderIdToIdx(kShaderVertexVTNColor)]);
  glDeleteShader(shaders_[ShaderIdToIdx(kShaderVertexVTTexture)]);
  glDeleteShader(shaders_[ShaderIdToIdx(kShaderVertexVTNTexture)]);
  glDeleteShader(shaders_[ShaderIdToIdx(kShaderFragmentColor)]);
  glDeleteShader(shaders_[ShaderIdToIdx(kShaderFragmentTexture)]);
}

void ShaderKeeper::CreateVertexShader(const char* data, GLuint& shader) {
  shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(shader, 1, &data, NULL);
  glCompileShader(shader);
}

void ShaderKeeper::CreateFragmentShader(const char* data, GLuint& shader) {
  shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(shader, 1, &data, NULL);
  glCompileShader(shader);
}

int ShaderKeeper::ShaderIdToIdx(ShaderId id) const {
  return static_cast<int>(id);
}

std::string ShaderKeeper::FromFile(const std::string& filename) const {
  std::ifstream file(filename);
  file.seekg(0, std::ios::end);
  size_t size = file.tellg();
  std::string buffer(size, ' ');
  file.seekg(0);
  file.read(&buffer[0], size);
  return buffer;
}

const char* ShaderKeeper::kDataShaderVertexVColor =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main() {\n"
    "  gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
    "}\n\0";

const char* ShaderKeeper::kDataShaderVertexVTColor =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 aTexCoord;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main() {\n"
    "  gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
    "}\n\0";

const char* ShaderKeeper::kDataShaderVertexVNColor =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aNormaleCoord;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main() {\n"
    "  gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
    "}\n\0";

const char* ShaderKeeper::kDataShaderVertexVTNColor =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 aTexCoord;\n"
    "layout (location = 2) in vec3 aNormaleCoord;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main() {\n"
    "  gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
    "}\n\0";

const char* ShaderKeeper::kDataShaderVertexVTTexture =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 aTexCoord;\n"
    "out vec2 TexCoord;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main() {\n"
    "  gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
    "  TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
    "}\n\0";

const char* ShaderKeeper::kDataShaderVertexVTNTexture =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 aTexCoord;\n"
    "layout (location = 3) in vec3 aNormaleCoord;\n"
    "out vec2 TexCoord;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main() {\n"
    "  gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
    "  TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
    "}\n\0";

const char* ShaderKeeper::kDataShaderFragmentColor =
    "#version 330 core\n"
    "uniform vec4 color;\n"
    "void main() {\n"
    "  gl_FragColor = color;\n"
    "}\n\0";

const char* ShaderKeeper::kDataShaderFragmentTexture =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec2 TexCoord;\n"
    "uniform sampler2D Texture;\n"
    "void main() {\n"
    "  FragColor = texture(Texture, TexCoord);\n"
    "}\n\0";

}  // namespace s21::OpenGLRenderer
