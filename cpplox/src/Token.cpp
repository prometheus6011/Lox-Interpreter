#include "Token.hpp"

Token::Token(TokenType type, const std::string& lexeme, std::any literal, int line) :
  type(type), lexeme(lexeme), literal(literal), line(line) { }

std::string Token::toString() const
{
  std::ostringstream out;
  out << this->line << " " << this->lexeme << " ";

  if (this->literal.has_value()) {
    if (this->literal.type() == typeid(std::string))
      out << std::any_cast<std::string>(this->literal);
    else if (this->literal.type() == typeid(double))
      out << std::any_cast<double>(this->literal);
    else if (this->literal.type() == typeid(bool))
      out << std::boolalpha << std::any_cast<bool>(this->literal);
    else
      out << "[unknown literal]";
  } else {
    out << "nil";
  }

  return out.str();
}