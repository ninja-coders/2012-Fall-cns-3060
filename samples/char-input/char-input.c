#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  while (!feof(stdin) && !ferror(stdin)) {
    int c = fgetc(stdin);

    if (c != EOF) {
      fputc(c, stdout);
    }
  }

  if (ferror(stdin)) {
    perror("Error while reading from stdin");
    clearerr(stdin);
  }
  
  return 0;
}

