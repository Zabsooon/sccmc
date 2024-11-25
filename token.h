#ifndef sccmc_token
#define sccmc_token
#include "scanner.h"

typedef enum {
  // Single character tokens
  TOKEN_HASH,
  TOKEN_LEFT_PAREN,
  TOKEN_RIGHT_PAREN,
  TOKEN_LEFT_BRACE,
  TOKEN_RIGHT_BRACE,
  TOKEN_COMA,
  TOKEN_DOT,
  TOKEN_SEMICOLON,
  TOKEN_SLASH,
  TOKEN_STAR,
  TOKEN_MINUS,
  TOKEN_PLUS,
  // One or two character tokens
  TOKEN_BANG,
  TOKEN_BANG_EQUAL,
  TOKEN_EQUAL,
  TOKEN_EQUAL_EQUAL,
  TOKEN_GREATER,
  TOKEN_GREATER_EQUAL,
  TOKEN_LESS,
  TOKEN_LESS_EQUAL,
  TOKEN_AND,       // later
  TOKEN_AND_EQUAL, // later
  TOKEN_OR,        // later
  TOKEN_OR_EQUAL,  // later
  TOKEN_BINARY_AND,
  TOKEN_BINARY_AND_EQUAL,
  TOKEN_BINARY_OR,
  TOKEN_BINARY_OR_EQUAL,
  TOKEN_XOR,
  TOKEN_XOR_EQUAL,
  TOKEN_NOT,
  TOKEN_LEFT_SHIFT,
  TOKEN_LEFT_SHIFT_EQUAL,
  TOKEN_RIGHT_SHIFT,
  TOKEN_RIGHT_SHIFT_EQUAL,
  // Types
  TOKEN_UINT8,
  TOKEN_UINT16,
  TOKEN_UINT32,
  TOKEN_UINT64,
  TOKEN_INT8,
  TOKEN_INT16,
  TOKEN_INT32,
  TOKEN_INT64,
  TOKEN_UFLOAT8,
  TOKEN_UFLOAT16,
  TOKEN_UFLOAT32,
  TOKEN_UFLOAT64,
  TOKEN_FLOAT8,
  TOKEN_FLOAT16,
  TOKEN_FLOAT32,
  TOKEN_FLOAT64,
  TOKEN_CHAR,
  TOKEN_BOOL,
  TOKEN_VOID,
  // Literals
  TOKEN_IDENTIFIER,
  TOKEN_STRING,
  TOKEN_PREPROCESSOR_LINE,
  TOKEN_NUMBER_BINARY,
  TOKEN_NUMBER_DECIMAL,
  TOKEN_NUMBER_OCTAL,
  TOKEN_NUMBER_HEX,
  // Keywords
  TOKEN_CLASS,
  TOKEN_STRUCT,
  TOKEN_TRUE,
  TOKEN_FALSE,
  TOKEN_IF,
  TOKEN_ELSE,
  TOKEN_FOR,
  TOKEN_DO,
  TOKEN_WHILE,

  TOKEN_EOF,
  TOKEN_ERROR,
} TokenType;

typedef struct {
  TokenType type;
  const char *start;
  int length;
  int line;

  union {
    int intValue;
    double floatValue;
    char *stringValue; // for getting strings with values such as '\n'.
  } value;
} Token;

Token make_token(TokenType type, Scanner *scanner);

#endif
