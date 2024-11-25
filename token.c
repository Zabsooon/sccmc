#include "token.h"

Token make_token(TokenType type, Scanner *scanner) {
  Token token;
  token.type = type;
  token.start = scanner->start;
  token.line = scanner->line;
  token.length = (int)(scanner->current - scanner->start);
  return token;
}
