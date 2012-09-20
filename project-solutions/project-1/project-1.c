#include <stdio.h>

int main(int argc, char* argv[], char* env[]) 
{
  printf("Michael Wright\nCNS 3060\n\n");

  if (argc == 1) {
    printf("No arguments supplied to %s", argv[0]);
  } else {
    int i = 1;
    do 
    {
      printf("%s\n", argv[i]);
    } while (++i < argc);
  }

  return 0;
}
