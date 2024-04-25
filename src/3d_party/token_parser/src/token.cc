//

//

#include "token.h"

#include "token_parser.h"

namespace s21 {

TokenParser::Token::Token(Type type) { type_ = type; }

TokenParser::Token::~Token() {}

TokenParser::Token::Type TokenParser::Token::GetType() { return type_; }

float TokenParser::Token::GetFloat() { return num_float_; }

int TokenParser::Token::GetInt() { return num_int_; }

int TokenParser::Token::GetId() { return id_; }

void TokenParser::Token::SetType(Type type) { type_ = type; }

void TokenParser::Token::SetFloat(float num) { num_float_ = num; }

void TokenParser::Token::SetInt(int num) { num_int_ = num; }

void TokenParser::Token::SetId(int id) { id_ = id; }

bool TokenParser::Token::IsNull() { return type_ == kTypeNull; }

bool TokenParser::Token::IsIdToken() { return type_ == kTypeId; }

bool TokenParser::Token::IsFloat() { return type_ == kTypeFloat; }

bool TokenParser::Token::IsInt() { return type_ == kTypeInt; }

}  // namespace s21
