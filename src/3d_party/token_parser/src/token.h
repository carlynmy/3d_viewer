//

//

#ifndef TOKEN_PARSER_TOKEN_PARSER_TOKEN_H_
#define TOKEN_PARSER_TOKEN_PARSER_TOKEN_H_

#include "token_parser.h"

namespace s21 {

class TokenParser::Token {
 public:
  enum Type {
    kTypeNull,
    kTypeInt,
    kTypeFloat,
    kTypeId,
  };

  Token(Type type = kTypeNull);
  virtual ~Token();

  Type GetType();
  float GetFloat();
  int GetInt();
  int GetId();

  void SetType(Type type);
  void SetFloat(float num);
  void SetInt(int num);
  void SetId(int id);

  bool IsNull();
  bool IsIdToken();
  bool IsFloat();
  bool IsInt();

 private:
  Type type_;
  union {
    int id_;
    float num_float_;
    int num_int_;
  };
};

}  // namespace s21

#endif  // TOKEN_PARSER_TOKEN_PARSER_TOKEN_H_
