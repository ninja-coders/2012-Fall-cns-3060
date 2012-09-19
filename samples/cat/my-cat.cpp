#include <stdio.h>

int main(int argc, char* argv[])
{
  if (argc <= 1) {
    char buffer[25];
    int read = fread(&buffer, sizeof(char), 25, stdin);
    if (read != 25) {
      perror("Oops");
      return -1;
    }

  }

  return 0;
}
