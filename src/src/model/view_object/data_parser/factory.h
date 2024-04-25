// factory view object data parser

#ifndef _3D_VIEWER_MODEL_VIEW_OBJECT_VIEW_OBJECT_DATA_PARSER_FACTORY_H_
#define _3D_VIEWER_MODEL_VIEW_OBJECT_VIEW_OBJECT_DATA_PARSER_FACTORY_H_

#include "parser.h"

namespace s21 {

class ViewObjectDataParserFactory {
 public:
  enum ParserType {
    kTypeObj,
  };

  ViewObjectDataParserFactory();
  virtual ~ViewObjectDataParserFactory();

  /// @brief Create ViewObjectDataParser
  /// @param type type
  /// @warning ownership on memory on new ViewObjectDataParser on you
  /// @return new ViewObjectDataParser
  virtual ViewObjectDataParser* Create(ParserType type);
};

}  // namespace s21

#endif  // _3D_VIEWER_MODEL_VIEW_OBJECT_VIEW_OBJECT_DATA_PARSER_FACTORY_H_
