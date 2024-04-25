// interface view object data parser

#ifndef _3D_VIEWER_VIEW_OBJECT_DATA_PARSER_PARSER_H_
#define _3D_VIEWER_VIEW_OBJECT_DATA_PARSER_PARSER_H_

#include <string>

#include "model/view_object/view_object_data.h"

namespace s21 {

class ViewObjectDataParser {
 public:
  enum ReturnCode { kCodeOk, kCodeFileDontOpen, kCodeInvalidFile };

  ViewObjectDataParser() {}
  virtual ~ViewObjectDataParser() {}

  virtual ReturnCode Parse(const std::string& filename,
                           ViewObjectData& object_data) = 0;
};

}  // namespace s21

#endif  // _3D_VIEWER_VIEW_OBJECT_DATA_PARSER_PARSER_H_
