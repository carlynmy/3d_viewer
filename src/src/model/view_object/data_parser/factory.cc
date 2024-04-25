// factory view object data parser

#include "factory.h"

#include "parser.h"
#include "parser_obj.h"

namespace s21 {

ViewObjectDataParserFactory::ViewObjectDataParserFactory() {}

ViewObjectDataParserFactory::~ViewObjectDataParserFactory() {}

ViewObjectDataParser* ViewObjectDataParserFactory::Create(ParserType type) {
  switch (type) {
    case kTypeObj:
      return new ViewObjectDataParserOBJ();
      break;

    default:
      break;
  }

  return nullptr;
}

}  // namespace s21
