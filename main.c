#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>

char *get_source_buffer(FILE *source_file, long long *source_buffer_size);
long long get_source_size(FILE *source_file);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr,
            "Unexpected use of sccmc! (Expected: ./sccmc <sourcefile>)");
    return 1;
  }

  FILE *source_file = fopen(argv[1], "r");

  if (source_file == NULL) {
    fprintf(stderr, "Could not open a file: %s", argv[1]);
    return 1;
  }

  long long source_file_size;
  char *source_file_buffer;

  source_file_buffer = get_source_buffer(source_file, &source_file_size);

  /* Lexer */
  Scanner scanner;
  init_scanner(&scanner, source_file_buffer);
  while(*scanner.current != '\0') {
    printf("%i", tokenize(&scanner).type);
    break;
  }
  return 0;
}

char *
get_source_buffer(FILE *source_file,
                  /* return */ long long
                      *source_buffer_size) { // there should be an easier way
                                             // for finding the size of source;
  fpos_t spos;
  (*source_buffer_size) = get_source_size(source_file);

  char *source_buffer;
  source_buffer = malloc((*source_buffer_size) * sizeof(char));
  fseek(source_file, 0, SEEK_SET);
  fread(source_buffer, sizeof(char), (*source_buffer_size), source_file);

  return source_buffer;
}

long long get_source_size(FILE *source_file) {
  fseek(source_file, 0, SEEK_END);
  long long size = ftell(source_file);
  fseek(source_file, 0, SEEK_SET);
  return size;
}
