//

//

#ifndef TOKEN_PARSER_TOKEN_PARSER_TOKEN_PARSER_H_
#define TOKEN_PARSER_TOKEN_PARSER_TOKEN_PARSER_H_

#include <cstddef>
#include <string>
#include <vector>

namespace s21 {

/// @brief Token parser. Parse string to tokens, token is float number, int
/// number or substring is compared by id.
class TokenParser {
 public:
  using IndexType = size_t;
  using WordIdx = std::pair<IndexType, IndexType>;

  class Token;

  struct TokenId {
    std::string str_ = "";
    int id_ = 0;
  };

  /// @brief Parser settings.
  /// @param tokens_ vector of pairs - string and id is compared
  struct Settings {
    std::vector<TokenParser::TokenId> tokens_{};
  };

  TokenParser();
  ~TokenParser();

  /// @brief Set parser settings
  void SetSettings(const Settings& settings);

  /// @brief Set string witch will be parsed
  /// @warning Index seted to 0
  void SetStr(const std::string& str);

  /// @brief Set index of string where next parsing will start
  /// @warning Undefined behavior if index is invalid
  void SetI(IndexType i);

  /// @brief Get current parser settings
  const Settings& GetSettings() const;

  /// @brief Get current parsed string
  const std::string& GetStr() const;

  /// @brief Get index of string where next parsing will start
  IndexType GetI() const;

  /// @brief Get next id-token
  /// @return Id-token, or null-token if no id-token next
  Token NextTokenIdAny();

  /// @brief Get next id-token
  /// @return Id-token, or null-token if no id-token next
  Token NextTokenId(int id);

  /// @brief Check if next is string str, change index like is token takken
  bool IsNextString(const std::string& str);

  /// @brief Get next float token
  /// @return Float token, or null-token if no float token next
  Token NextFloat();

  /// @brief Get next integer token
  /// @return Integer token, or null-token if no integer token next
  Token NextInt();

  /// @brief Get next word. Word is substring up to space char or end string
  /// @return next word, or empty string if no word nex
  std::string NextWord();

  /// @brief Check if parsing str is end or contain only space char
  bool IsEnd() const;

 private:
  WordIdx NextWordIdx() const;

  IndexType NextParsingStart() const;
  bool IsTokenId(IndexType i, const std::string& token_id) const;

  Settings settings_;
  const std::string* str_;
  IndexType i_;
};

}  // namespace s21

#include "../src/token.h"

#endif  // TOKEN_PARSER_TOKEN_PARSER_TOKEN_PARSER_H_
