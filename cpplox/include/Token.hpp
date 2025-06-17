#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <any>
#include "TokenType.hpp"
#include <sstream>

class Token {
private:
  const TokenType type;
  const std::string lexeme;
  const std::any literal;
  const int line;

public:
  Token(TokenType, const std::string&, std::any, int);

  std::string toString() const;
};

#endif  // TOKEN_H