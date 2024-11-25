#ifndef sccmc_scanner
#define sccmc_scanner

typedef struct {
} Token;

typedef struct {
  const char *start;
  const char *current;
  int line;
} Scanner;

void init_scanner(Scanner *scanner, const char *source);
int is_scanner_at_end(Scanner *scanner);
char advance_scannner(Scanner *scanner);
int match_to_current(char expected, Scanner *scanner);
int is_digit(Scanner *scanner);
int is_alpha(Scanner *scanner);
Token tokenize(Scanner *scanner);

#endif
