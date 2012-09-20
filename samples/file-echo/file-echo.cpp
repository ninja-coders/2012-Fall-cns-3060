#include <stdio.h>

int main(int argc, char* argv[])
{
  while (!ferror(stdin) && !feof(stdin)) {
    char buffer[25];
    int read = fread(&buffer, sizeof(char), 25, stdin);
    int write = fwrite(buffer, sizeof(char), 25, stdout);
  }

  return 0;
}
