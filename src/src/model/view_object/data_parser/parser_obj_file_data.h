#ifndef _3D_VIEWER_VIEW_OBJECT_DATA_PARSER_PARSER_OBJ_FILE_DATA_H_
#define _3D_VIEWER_VIEW_OBJECT_DATA_PARSER_PARSER_OBJ_FILE_DATA_H_

#include <cstdint>
#include <string>
#include <vector>

namespace s21 {

struct ParserObjFileData {
  enum FaceType {
    kVerteces,
    kVertecesNormale,
    kVertecesTexture,
    kAll,
  };
  std::string name_;
  std::vector<float> verteces_;
  std::vector<float> textures_;
  std::vector<float> normales_;
  float max_vertex_ = 0;
  bool face_type_defined_;
  FaceType face_type_;
  std::vector<float> array_verteces_;
  std::vector<uint32_t> faces_point_;
  std::vector<uint32_t> faces_line_;
  std::vector<uint32_t> faces_triangle_;
};

}  // namespace s21

#endif  // _3D_VIEWER_VIEW_OBJECT_DATA_PARSER_PARSER_OBJ_FILE_DATA_H_
