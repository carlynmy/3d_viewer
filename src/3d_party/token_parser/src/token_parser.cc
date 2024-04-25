// Implementation class TokenParser

#include "token_parser.h"

#include <cstring>
#include <string>
#include <utility>

namespace s21 {

TokenParser::TokenParser() { i_ = 0; }

TokenParser::~TokenParser() {}

void TokenParser::SetSettings(const Settings& settings) {
  settings_ = settings;
}

void TokenParser::SetStr(const std::string& str) {
  str_ = &str;
  i_ = 0;
}

void TokenParser::SetI(IndexType i) { i_ = i; }

const TokenParser::Settings& TokenParser::GetSettings() const {
  return settings_;
}

const std::string& TokenParser::GetStr() const { return *str_; }

TokenParser::IndexType TokenParser::GetI() const { return i_; }

TokenParser::Token TokenParser::NextTokenIdAny() {
  WordIdx word_idx = NextWordIdx();

  const char* this_start = str_->c_str() + word_idx.first;
  size_t count = word_idx.second - word_idx.first;

  auto tokens_iter = settings_.tokens_.begin();
  for (; tokens_iter != settings_.tokens_.end(); ++tokens_iter) {
    const char* other_start = tokens_iter->str_.c_str();
    size_t other_len = tokens_iter->str_.length();

    if (count != other_len) continue;
    if (std::memcmp(this_start, other_start, count) != 0) continue;

    i_ = i_ + word_idx.first + static_cast<IndexType>(other_len);
    Token token(Token::kTypeId);
    token.SetId(tokens_iter->id_);
    return token;
  }

  return Token(Token::kTypeNull);
}

TokenParser::WordIdx TokenParser::NextWordIdx() const {
  WordIdx word_idx;
  IndexType i = NextParsingStart();

  int len = 0;
  while ((i + len) < str_->length() && !std::isspace((*str_)[i + len])) ++len;

  word_idx.first = i;
  word_idx.second = i + len;
  return word_idx;
}

TokenParser::Token TokenParser::NextTokenId(int id) {
  auto tokens_iter = settings_.tokens_.begin();
  for (; tokens_iter != settings_.tokens_.end(); ++tokens_iter) {
    if (tokens_iter->id_ == id) break;
  }
  const std::string& str = tokens_iter->str_;

  IndexType i = NextParsingStart();
  size_t this_len = str_->length() - i;
  const char* this_start = str_->c_str() + i;
  size_t other_len = str.length();
  const char* other_start = str.c_str();

  if (this_len < other_len) return Token(Token::kTypeNull);
  if (std::memcmp(this_start, other_start, other_len) != 0)
    return Token(Token::kTypeNull);

  i_ = i + other_len;

  Token token(Token::kTypeId);
  token.SetId(id);
  return token;
}

bool TokenParser::IsNextString(const std::string& str) {
  IndexType i = NextParsingStart();
  size_t this_len = str_->length() - i;
  const char* this_start = str_->c_str() + i;
  size_t other_len = str.length();
  const char* other_start = str.c_str();

  if (this_len < other_len) return false;
  if (std::memcmp(this_start, other_start, other_len) != 0) return false;

  i_ = i + other_len;
  return true;
}

TokenParser::Token TokenParser::NextFloat() {
  IndexType i = NextParsingStart();

  const char* start = str_->c_str() + i;
  char* end;
  float answer;
  answer = std::strtof(start, &end);
  if (start == end) return Token(Token::kTypeNull);

  Token token(Token::kTypeFloat);
  token.SetFloat(answer);

  i_ = i + (end - start);
  return token;
}

TokenParser::Token TokenParser::NextInt() {
  IndexType i = NextParsingStart();

  const char* start = str_->c_str() + i;
  char* end;
  int answer;
  answer = std::strtol(start, &end, 10);
  if (start == end) return Token(Token::kTypeNull);

  Token token(Token::kTypeInt);
  token.SetInt(answer);

  i_ = i + (end - start);
  return token;
}

std::string TokenParser::NextWord() {
  IndexType i = NextParsingStart();
  int len = 0;
  while ((i + len) < str_->length() && !std::isspace((*str_)[i + len])) ++len;

  std::string str = str_->substr(i, len);

  i_ = i + len;
  return str;
}

bool TokenParser::IsEnd() const {
  IndexType i = NextParsingStart();
  if (static_cast<size_t>(i) == str_->length()) return true;
  return false;
}

TokenParser::IndexType TokenParser::NextParsingStart() const {
  IndexType i = i_;
  while (i < str_->length() && std::isspace((*str_)[i])) ++i;
  return i;
}

bool TokenParser::IsTokenId(IndexType i, const std::string& token_id) const {
  size_t size = token_id.size();
  for (size_t token_i = 0; token_i < size; ++token_i) {
    if ((*str_)[i + token_i] != token_id[token_i]) return false;
  }

  return true;
}

}  // namespace s21
