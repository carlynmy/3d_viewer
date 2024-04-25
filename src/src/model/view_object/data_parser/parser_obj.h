// view object data parser obj

#ifndef _3D_VIEWER_VIEW_OBJECT_VIEW_OBJECT_DATA_PARSER_PARSER_OBJ_H_
#define _3D_VIEWER_VIEW_OBJECT_VIEW_OBJECT_DATA_PARSER_PARSER_OBJ_H_

#include <string>

#include "../view_object_data.h"
#include "parser.h"
#include "parser_obj_file_data.h"
#include "token_parser.h"

namespace s21 {

class ViewObjectDataParserOBJ : public ViewObjectDataParser {
 public:
  using ReturnCode = ViewObjectDataParser::ReturnCode;

  ViewObjectDataParserOBJ();
  virtual ~ViewObjectDataParserOBJ();

  ReturnCode Parse(const std::string& filename,
                   ViewObjectData& object_data) override;

 private:
  enum Token {
    kTokenSlash,
    kTokenName,
    kTokenVerteces,
    kTokenFace,
    kTokenNormal,
    kTokenTexture,
    kTokenHashTag
  };

  using FaceType = ParserObjFileData::FaceType;

  ReturnCode ParseLine(ParserObjFileData& file_data, const std::string& str);
  ReturnCode ParseName(ParserObjFileData& file_data);
  ReturnCode ParseVerteces(ParserObjFileData& file_data);
  ReturnCode ParseNormal(ParserObjFileData& file_data);
  ReturnCode ParseTexture(ParserObjFileData& file_data);
  ReturnCode ParseFace(ParserObjFileData& file_data);
  void DefineFaceType(ParserObjFileData& file_data);
  void ParseFaceVerteces(ParserObjFileData& file_data);
  void ParseFaceVertecesNormale(ParserObjFileData& file_data);
  void ParseFaceVertecesTexture(ParserObjFileData& file_data);
  void ParseFaceAll(ParserObjFileData& file_data);
  TokenParser::Token NextTokenIntOrSlash();
  std::string NameFromFilename(const std::string& filename);

  static const std::vector<TokenParser::TokenId> kTokens_;
  static const TokenParser::Settings kSettings_;
  static const std::string kStrTokenSlash;
  static const std::string kStrTokenName;
  static const std::string kStrTokenVerteces;
  static const std::string kStrTokenFace;
  static const std::string kStrTokenNormal;
  static const std::string kStrTokenTexture;
  static const std::string kStrTokenHashTag;

  TokenParser token_parser_;
};

}  // namespace s21

#endif  // _3D_VIEWER_VIEW_OBJECT_VIEW_OBJECT_DATA_PARSER_PARSER_OBJ_H_
