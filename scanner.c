#include "scanner.h"
#include "token.h"
#include <csignal>
#include <stdio.h>
void init_scanner(Scanner *scanner, const char *source) {
  scanner->start = source;
  scanner->current = source;
  scanner->line = 1;
}

int is_scanner_at_end(Scanner *scanner) { return *scanner->current != '\0'; }

char advance_scanner(Scanner *scanner) {
  scanner->current++;
  return scanner->current[-1];
}

/*
 * match_to_current() - checks the next character in scanner and if it is the
 * same as the expected it returns 1 and increments the scanner.
 * */
int match_to_current(char expected, Scanner *scanner) {
  if (is_scanner_at_end(scanner))
    return 0;
  if (*scanner->current != expected) {
    return 0;
  }
  scanner->current++;
  return 1;
}

int is_digit(Scanner *scanner) {
  return (*scanner->current >= '1' && *scanner->current <= '9');
}

int is_alpha(Scanner *scanner) {
  return (*scanner->current >= 'a' && *scanner->current <= 'z') ||
         (*scanner->current >= 'A' && *scanner->current <= 'Z') ||
         *scanner->current == '_';
}

Token tokenize(Scanner *scanner) {

  if (is_scanner_at_end(scanner))
    return make_token(TOKEN_EOF, scanner);

  switch (advance_scanner(scanner)) {
  case '#':
    return make_token(TOKEN_HASH, scanner);
  case '(':
    return make_token(TOKEN_LEFT_PAREN, scanner);
  case ')':
    return make_token(TOKEN_RIGHT_PAREN, scanner);
  case '{':
    return make_token(TOKEN_LEFT_BRACE, scanner);
  case '}':
    return make_token(TOKEN_RIGHT_BRACE, scanner);
  case ',':
    return make_token(TOKEN_COMA, scanner);
  case '.':
    return make_token(TOKEN_DOT, scanner);
  case ';':
    return make_token(TOKEN_SEMICOLON, scanner);
  case '/':
    return make_token(TOKEN_SLASH, scanner);
  case '*':
    return make_token(TOKEN_STAR, scanner);
  case '+':
    return make_token(TOKEN_PLUS, scanner);
  case '-':
    return make_token(TOKEN_MINUS, scanner);
  case '!':
    return match_to_current('=', scanner)
               ? make_token(TOKEN_BANG_EQUAL, scanner)
               : make_token(TOKEN_BANG, scanner);
  case '=':
    return match_to_current('=', scanner)
               ? make_token(TOKEN_EQUAL_EQUAL, scanner)
               : make_token(TOKEN_EQUAL, scanner);
    return make_token(TOKEN_BANG, scanner);
  case '>':
    return match_to_current('=', scanner)
               ? make_token(TOKEN_GREATER_EQUAL, scanner)
               : (match_to_current('>', scanner)
                      ? make_token(TOKEN_RIGHT_SHIFT, scanner)
                      : make_token(TOKEN_GREATER, scanner));
  case '<':
    return match_to_current('=', scanner)
               ? make_token(TOKEN_LESS_EQUAL, scanner)
               : (match_to_current('<', scanner)
                      ? make_token(TOKEN_LEFT_SHIFT, scanner)
                      : make_token(TOKEN_LESS, scanner));
  case '&':
    return match_to_current('=', scanner)
               ? make_token(TOKEN_BINARY_AND_EQUAL, scanner)
               : make_token(TOKEN_BINARY_AND, scanner);
  case '|':
    return match_to_current('=', scanner)
               ? make_token(TOKEN_BINARY_OR_EQUAL, scanner)
               : make_token(TOKEN_BINARY_OR, scanner);
  case '^':
    return match_to_current('=', scanner) ? make_token(TOKEN_XOR_EQUAL, scanner)
                                          : make_token(TOKEN_XOR, scanner);
  case '~':
    return make_token(TOKEN_NOT, scanner);
  default:
    return make_token(TOKEN_ERROR, scanner);
  }

  printf("%s", scanner->current);
  return make_token(TOKEN_ERROR, scanner);
}
