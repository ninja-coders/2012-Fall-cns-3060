#include <stdio.h>

int main(int argc, char* argv[]) {
  const char* testString = "This is a test of string using printf";
  const char initial = 'M';
  const int size = 1010101;
  const long longer = 101010101010101;
  const short shorter = 10101;

  printf("This is a string '%s'\n", testString);
  printf("This is my initial '%c'\n", initial);
  printf("This is an int '%d'\n", size);
  printf("This is a long '%ld'\n", longer);
  printf("This is a short '%dh'\n", shorter);

  return 0;
}
