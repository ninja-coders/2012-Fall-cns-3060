#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char buffer[25];
  memset(buffer, 0, sizeof(buffer));
  while (!ferror(stdin) && !feof(stdin)) {
 
    int i = 0;
    do
    {
      buffer[i] = fgetc(stdin);
    } while (i++ < 25 && !(ferror(stdin) || feof(stdin)));
    for (i = 0; i < 25; ++i) {
      fputc(buffer[i], stdout);
    }
  }  

  return 0;
}

