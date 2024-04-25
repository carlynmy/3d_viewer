// view object data parser obj

#include "parser_obj.h"

#include <fstream>
#include <string>
#include <utility>
#include <vector>

#include "../view_object_data.h"
#include "parser_obj_file_data.h"

namespace s21 {

ViewObjectDataParserOBJ::ViewObjectDataParserOBJ() {
  token_parser_.SetSettings(kSettings_);
}

ViewObjectDataParserOBJ::~ViewObjectDataParserOBJ() {}

ViewObjectDataParserOBJ::ReturnCode ViewObjectDataParserOBJ::Parse(
    const std::string& filename, ViewObjectData& object) {
  std::ifstream file(filename);
  if (file.fail()) return ReturnCode::kCodeFileDontOpen;
  file.sync_with_stdio(false);
  ParserObjFileData file_data;
  file_data.name_ = "";
  file_data.max_vertex_ = 0;
  file_data.face_type_defined_ = false;
  file_data.face_type_ = FaceType::kVerteces;
  std::string str;
  while (std::getline(file, str)) {
    ParseLine(file_data, str);
  }

  if (file_data.face_type_ == FaceType::kVerteces)
    object.SetVertices(std::move(file_data.verteces_));
  else
    object.SetVertices(std::move(file_data.array_verteces_));
  object.SetFacesPoint(std::move(file_data.faces_point_));
  object.SetFacesLine(std::move(file_data.faces_line_));
  object.SetFacesTriangle(std::move(file_data.faces_triangle_));
  object.SetMaxVertex(file_data.max_vertex_);
  if (file_data.name_ == "")
    object.SetName(std::move(NameFromFilename(filename)));
  else
    object.SetName(std::move(file_data.name_));
  if (!file_data.face_type_defined_) file_data.face_type_ = FaceType::kVerteces;
  switch (file_data.face_type_) {
    case FaceType::kVerteces:
      object.SetVerticesStorageType(
          ViewObjectData::VerticesStorageType::kVerticesStorageTypeVertices);
      break;
    case FaceType::kVertecesTexture:
      object.SetVerticesStorageType(ViewObjectData::VerticesStorageType::
                                        kVerticesStorageTypeVerticesTexture);
      break;
    case FaceType::kVertecesNormale:
      object.SetVerticesStorageType(ViewObjectData::VerticesStorageType::
                                        kVerticesStorageTypeVerticesNormale);
      break;
    default:
      object.SetVerticesStorageType(
          ViewObjectData::VerticesStorageType::
              kVerticesStorageTypeVerticesTextureNormale);
      break;
  }

  return ReturnCode::kCodeOk;
}

ViewObjectDataParserOBJ::ReturnCode ViewObjectDataParserOBJ::ParseLine(
    ParserObjFileData& file_data, const std::string& str) {
  token_parser_.SetStr(str);
  TokenParser::Token token = token_parser_.NextTokenIdAny();
  if (!token.IsIdToken()) return kCodeInvalidFile;

  Token token_id = static_cast<Token>(token.GetId());
  switch (token_id) {
    case kTokenName:
      return ParseName(file_data);
      break;
    case kTokenVerteces:
      return ParseVerteces(file_data);
      break;
    case kTokenNormal:
      return ParseNormal(file_data);
      break;
    case kTokenTexture:
      return ParseTexture(file_data);
      break;
    case kTokenFace:
      return ParseFace(file_data);
      break;
    default:
      break;
  }
  return kCodeInvalidFile;
}

ViewObjectDataParserOBJ::ReturnCode ViewObjectDataParserOBJ::ParseName(
    ParserObjFileData& file_data) {
  file_data.name_ = std::move(token_parser_.NextWord());
  return ReturnCode::kCodeOk;
}

ViewObjectDataParserOBJ::ReturnCode ViewObjectDataParserOBJ::ParseVerteces(
    ParserObjFileData& file_data) {
  TokenParser::Token token_x = token_parser_.NextFloat();
  TokenParser::Token token_y = token_parser_.NextFloat();
  TokenParser::Token token_z = token_parser_.NextFloat();

  if (token_x.IsNull() || token_y.IsNull() || token_z.IsNull())
    return kCodeInvalidFile;

  file_data.verteces_.push_back(token_x.GetFloat());
  file_data.verteces_.push_back(token_y.GetFloat());
  file_data.verteces_.push_back(token_z.GetFloat());

  if (std::abs(token_x.GetFloat()) > file_data.max_vertex_)
    file_data.max_vertex_ = std::abs(token_x.GetFloat());
  if (std::abs(token_y.GetFloat()) > file_data.max_vertex_)
    file_data.max_vertex_ = std::abs(token_y.GetFloat());
  if (std::abs(token_z.GetFloat()) > file_data.max_vertex_)
    file_data.max_vertex_ = std::abs(token_z.GetFloat());

  return kCodeOk;
}

ViewObjectDataParserOBJ::ReturnCode ViewObjectDataParserOBJ::ParseNormal(
    ParserObjFileData& file_data) {
  TokenParser::Token token_x = token_parser_.NextFloat();
  TokenParser::Token token_y = token_parser_.NextFloat();
  TokenParser::Token token_z = token_parser_.NextFloat();

  if (token_x.IsNull() || token_y.IsNull() || token_z.IsNull())
    return kCodeInvalidFile;

  file_data.normales_.push_back(token_x.GetFloat());
  file_data.normales_.push_back(token_y.GetFloat());
  file_data.normales_.push_back(token_z.GetFloat());

  return kCodeOk;
}

ViewObjectDataParserOBJ::ReturnCode ViewObjectDataParserOBJ::ParseTexture(
    ParserObjFileData& file_data) {
  TokenParser::Token token_u = token_parser_.NextFloat();
  TokenParser::Token token_v = token_parser_.NextFloat();

  if (token_u.IsNull() || token_v.IsNull()) return kCodeInvalidFile;

  file_data.textures_.push_back(token_u.GetFloat());
  file_data.textures_.push_back(token_v.GetFloat());

  return kCodeOk;
}

ViewObjectDataParserOBJ::ReturnCode ViewObjectDataParserOBJ::ParseFace(
    ParserObjFileData& file_data) {
  if (!file_data.face_type_defined_) DefineFaceType(file_data);

  switch (file_data.face_type_) {
    case FaceType::kVerteces:
      ParseFaceVerteces(file_data);
      break;
    case FaceType::kVertecesNormale:
      ParseFaceVertecesNormale(file_data);
      break;

    case FaceType::kVertecesTexture:
      ParseFaceVertecesTexture(file_data);
      break;

    default:
      ParseFaceAll(file_data);
      break;
  }

  return ReturnCode::kCodeOk;
}

void ViewObjectDataParserOBJ::DefineFaceType(ParserObjFileData& file_data) {
  TokenParser::IndexType i = token_parser_.GetI();

  token_parser_.NextInt();
  TokenParser::Token token2 = NextTokenIntOrSlash();
  TokenParser::Token token3 = NextTokenIntOrSlash();
  TokenParser::Token token4 = NextTokenIntOrSlash();

  FaceType type = FaceType::kVerteces;
  if (token2.IsIdToken()) {
    if (token3.IsInt() && !token4.IsIdToken()) {
      type = FaceType::kVertecesTexture;
    } else if (token3.IsInt() && token4.IsIdToken()) {
      type = FaceType::kAll;
    } else if (token3.IsIdToken()) {
      type = FaceType::kVertecesNormale;
    }
  }

  token_parser_.SetI(i);

  file_data.face_type_defined_ = true;
  file_data.face_type_ = type;
}

void ViewObjectDataParserOBJ::ParseFaceVerteces(ParserObjFileData& file_data) {
  std::vector<int> verteces;
  TokenParser::Token token = token_parser_.NextInt();
  while (token.IsInt()) {
    int vertex_value = token.GetInt() - 1;
    if (vertex_value < 0) vertex_value += file_data.verteces_.size() / 3 + 1;

    if (vertex_value >= int(file_data.verteces_.size() / 3)) break;

    verteces.push_back(vertex_value);

    token = token_parser_.NextInt();
  }

  switch (verteces.size()) {
    case 0:
      break;
    case 1:
      file_data.faces_point_.push_back(verteces[0]);
      break;

    case 2:
      file_data.faces_line_.push_back(verteces[0]);
      file_data.faces_line_.push_back(verteces[1]);
      break;

    case 3:
      file_data.faces_triangle_.push_back(verteces[0]);
      file_data.faces_triangle_.push_back(verteces[1]);
      file_data.faces_triangle_.push_back(verteces[2]);
      break;

    default:
      for (int i = 1; i < int(verteces.size()) - 1; ++i) {
        file_data.faces_triangle_.push_back(verteces[i - 1]);
        file_data.faces_triangle_.push_back(verteces[i]);
        file_data.faces_triangle_.push_back(verteces[i + 1]);
      }
      break;
  }
}

void ViewObjectDataParserOBJ::ParseFaceVertecesNormale(
    ParserObjFileData& file_data) {
  std::vector<int> verteces;
  TokenParser::Token token_v = token_parser_.NextInt();
  TokenParser::Token token_slash = token_parser_.NextTokenId(kTokenSlash);
  TokenParser::Token token_slash_2 = token_parser_.NextTokenId(kTokenSlash);
  TokenParser::Token token_vn = token_parser_.NextInt();
  while (token_v.IsInt() && token_slash.IsIdToken() &&
         token_slash_2.IsIdToken() && token_vn.IsInt()) {
    int vertex_value = token_v.GetInt() - 1;
    if (vertex_value < 0) vertex_value += file_data.verteces_.size() / 3 + 1;
    int normale_value = token_vn.GetInt() - 1;
    if (normale_value < 0) normale_value += file_data.normales_.size() / 3 + 1;

    if (vertex_value >= int(file_data.verteces_.size() / 3)) break;
    if (normale_value >= int(file_data.normales_.size() / 3)) break;

    verteces.push_back(vertex_value);
    verteces.push_back(normale_value);

    token_v = token_parser_.NextInt();
    token_slash = token_parser_.NextTokenId(kTokenSlash);
    token_slash_2 = token_parser_.NextTokenId(kTokenSlash);
    token_vn = token_parser_.NextInt();
  }

  switch (verteces.size() / 2) {
    case 0:
      break;
    case 1:
      for (int j = 0; j < 3; ++j)
        file_data.array_verteces_.push_back(
            file_data.verteces_[verteces[2 * 0 + 0] * 3 + j]);
      for (int j = 0; j < 3; ++j)
        file_data.array_verteces_.push_back(
            file_data.normales_[verteces[2 * 0 + 1] * 3 + j]);

      file_data.faces_point_.push_back(file_data.array_verteces_.size() / 6 -
                                       1);
      break;

    case 2:
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j)
          file_data.array_verteces_.push_back(
              file_data.verteces_[verteces[2 * i + 0] * 3 + j]);
        for (int j = 0; j < 3; ++j)
          file_data.array_verteces_.push_back(
              file_data.normales_[verteces[2 * i + 1] * 3 + j]);
      }

      file_data.faces_line_.push_back(file_data.array_verteces_.size() / 6 - 2);
      file_data.faces_line_.push_back(file_data.array_verteces_.size() / 6 - 1);
      break;

    default:
      for (int k = 1; k < int(verteces.size()) / 2 - 1; ++k) {
        for (int i = k - 1; i < k + 2; ++i) {
          for (int j = 0; j < 3; ++j)
            file_data.array_verteces_.push_back(
                file_data.verteces_[verteces[2 * i + 0] * 3 + j]);
          for (int j = 0; j < 3; ++j)
            file_data.array_verteces_.push_back(
                file_data.normales_[verteces[2 * i + 1] * 3 + j]);
        }

        file_data.faces_triangle_.push_back(
            file_data.array_verteces_.size() / 6 - 3);
        file_data.faces_triangle_.push_back(
            file_data.array_verteces_.size() / 6 - 2);
        file_data.faces_triangle_.push_back(
            file_data.array_verteces_.size() / 6 - 1);
      }
      break;
  }
}

void ViewObjectDataParserOBJ::ParseFaceVertecesTexture(
    ParserObjFileData& file_data) {
  std::vector<int> verteces;
  TokenParser::Token token_v = token_parser_.NextInt();
  TokenParser::Token token_slash = token_parser_.NextTokenId(kTokenSlash);
  TokenParser::Token token_vt = token_parser_.NextInt();
  while (token_v.IsInt() && token_vt.IsInt()) {
    int vertex_value = token_v.GetInt() - 1;
    if (vertex_value < 0) vertex_value += file_data.verteces_.size() / 3 + 1;
    int texture_value = token_vt.GetInt() - 1;
    if (texture_value < 0) texture_value += file_data.textures_.size() / 2 + 1;

    if (vertex_value >= int(file_data.verteces_.size() / 3)) break;
    if (texture_value >= int(file_data.textures_.size() / 2)) break;

    verteces.push_back(vertex_value);
    verteces.push_back(texture_value);

    token_v = token_parser_.NextInt();
    token_slash = token_parser_.NextTokenId(kTokenSlash);
    token_vt = token_parser_.NextInt();
  }

  switch (verteces.size() / 2) {
    case 0:
      break;
    case 1:
      for (int j = 0; j < 3; ++j)
        file_data.array_verteces_.push_back(
            file_data.verteces_[verteces[2 * 0 + 0] * 3 + j]);
      for (int j = 0; j < 2; ++j)
        file_data.array_verteces_.push_back(
            file_data.textures_[verteces[2 * 0 + 1] * 2 + j]);

      file_data.faces_point_.push_back(file_data.array_verteces_.size() / 5 -
                                       1);
      break;

    case 2:
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j)
          file_data.array_verteces_.push_back(
              file_data.verteces_[verteces[2 * i + 0] * 3 + j]);
        for (int j = 0; j < 2; ++j)
          file_data.array_verteces_.push_back(
              file_data.textures_[verteces[2 * i + 1] * 2 + j]);
      }

      file_data.faces_line_.push_back(file_data.array_verteces_.size() / 5 - 2);
      file_data.faces_line_.push_back(file_data.array_verteces_.size() / 5 - 1);
      break;

    default:
      for (int k = 1; k < int(verteces.size()) / 2 - 1; ++k) {
        for (int i = k - 1; i < k + 2; ++i) {
          for (int j = 0; j < 3; ++j)
            file_data.array_verteces_.push_back(
                file_data.verteces_[verteces[2 * i + 0] * 3 + j]);
          for (int j = 0; j < 2; ++j)
            file_data.array_verteces_.push_back(
                file_data.textures_[verteces[2 * i + 1] * 2 + j]);
        }

        for (int d = 3; d != 0; --d)
          file_data.faces_triangle_.push_back(
              file_data.array_verteces_.size() / 5 - d);
      }
      break;
  }
}

void ViewObjectDataParserOBJ::ParseFaceAll(ParserObjFileData& file_data) {
  std::vector<int> verteces;
  TokenParser::Token token_v = token_parser_.NextInt();
  TokenParser::Token token_slash = token_parser_.NextTokenId(kTokenSlash);
  TokenParser::Token token_vt = token_parser_.NextInt();
  TokenParser::Token token_slash_2 = token_parser_.NextTokenId(kTokenSlash);
  TokenParser::Token token_vn = token_parser_.NextInt();
  while (token_v.IsInt() && token_slash.IsIdToken() && token_vt.IsInt() &&
         token_slash_2.IsIdToken() && token_vn.IsInt()) {
    int vertex_value = token_v.GetInt() - 1;
    if (vertex_value < 0) vertex_value += file_data.verteces_.size() / 3 + 1;
    int texture_value = token_vt.GetInt() - 1;
    if (texture_value < 0) texture_value += file_data.textures_.size() / 2 + 1;
    int normale_value = token_vn.GetInt() - 1;
    if (normale_value < 0) normale_value += file_data.normales_.size() / 3 + 1;

    if (vertex_value >= int(file_data.verteces_.size() / 3)) break;
    if (texture_value >= int(file_data.textures_.size() / 2)) break;
    if (normale_value >= int(file_data.normales_.size() / 3)) break;

    verteces.push_back(vertex_value);
    verteces.push_back(texture_value);
    verteces.push_back(normale_value);

    token_v = token_parser_.NextInt();
    token_slash = token_parser_.NextTokenId(kTokenSlash);
    token_vt = token_parser_.NextInt();
    token_slash_2 = token_parser_.NextTokenId(kTokenSlash);
    token_vn = token_parser_.NextInt();
  }

  switch (verteces.size() / 3) {
    case 0:
      break;
    case 1:
      for (int j = 0; j < 3; ++j)
        file_data.array_verteces_.push_back(
            file_data.verteces_[verteces[3 * 0 + 0] * 3 + j]);
      for (int j = 0; j < 2; ++j)
        file_data.array_verteces_.push_back(
            file_data.textures_[verteces[3 * 0 + 1] * 2 + j]);
      for (int j = 0; j < 3; ++j)
        file_data.array_verteces_.push_back(
            file_data.normales_[verteces[3 * 0 + 2] * 3 + j]);

      file_data.faces_point_.push_back(file_data.array_verteces_.size() / 8 -
                                       1);
      break;

    case 2:
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j)
          file_data.array_verteces_.push_back(
              file_data.verteces_[verteces[3 * i + 0] * 3 + j]);
        for (int j = 0; j < 2; ++j)
          file_data.array_verteces_.push_back(
              file_data.textures_[verteces[3 * i + 1] * 2 + j]);
        for (int j = 0; j < 3; ++j)
          file_data.array_verteces_.push_back(
              file_data.normales_[verteces[3 * i + 2] * 3 + j]);
      }

      file_data.faces_line_.push_back(file_data.array_verteces_.size() / 8 - 2);
      file_data.faces_line_.push_back(file_data.array_verteces_.size() / 8 - 1);
      break;

    default:
      for (int k = 1; k < int(verteces.size()) / 3 - 1; ++k) {
        for (int i = k - 1; i < k + 2; ++i) {
          for (int j = 0; j < 3; ++j)
            file_data.array_verteces_.push_back(
                file_data.verteces_[verteces[3 * i + 0] * 3 + j]);
          for (int j = 0; j < 2; ++j)
            file_data.array_verteces_.push_back(
                file_data.textures_[verteces[3 * i + 1] * 2 + j]);
          for (int j = 0; j < 3; ++j)
            file_data.array_verteces_.push_back(
                file_data.normales_[verteces[3 * i + 2] * 3 + j]);
        }

        file_data.faces_triangle_.push_back(
            file_data.array_verteces_.size() / 8 - 3);
        file_data.faces_triangle_.push_back(
            file_data.array_verteces_.size() / 8 - 2);
        file_data.faces_triangle_.push_back(
            file_data.array_verteces_.size() / 8 - 1);
      }
      break;
  }
}

TokenParser::Token ViewObjectDataParserOBJ::NextTokenIntOrSlash() {
  TokenParser::Token token = token_parser_.NextTokenId(kTokenSlash);
  if (token.IsNull()) token = token_parser_.NextInt();
  return token;
}

std::string ViewObjectDataParserOBJ::NameFromFilename(
    const std::string& fileway) {
  size_t i = fileway.rfind('/');
  if (i == fileway.npos) return fileway;
  return fileway.substr(i + 1);
}

const std::string ViewObjectDataParserOBJ::kStrTokenSlash = "/";
const std::string ViewObjectDataParserOBJ::kStrTokenName = "o";
const std::string ViewObjectDataParserOBJ::kStrTokenVerteces = "v";
const std::string ViewObjectDataParserOBJ::kStrTokenFace = "f";
const std::string ViewObjectDataParserOBJ::kStrTokenNormal = "vn";
const std::string ViewObjectDataParserOBJ::kStrTokenTexture = "vt";
const std::string ViewObjectDataParserOBJ::kStrTokenHashTag = "#";

const std::vector<TokenParser::TokenId> ViewObjectDataParserOBJ::kTokens_{
    {kStrTokenSlash, kTokenSlash},     {kStrTokenVerteces, kTokenVerteces},
    {kStrTokenTexture, kTokenTexture}, {kStrTokenNormal, kTokenNormal},
    {kStrTokenFace, kTokenFace},       {kStrTokenName, kTokenName},
    {kStrTokenHashTag, kTokenHashTag}

};

const TokenParser::Settings ViewObjectDataParserOBJ::kSettings_{
    .tokens_ = kTokens_,
};

}  // namespace s21
