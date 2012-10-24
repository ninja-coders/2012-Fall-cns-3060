#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#define READ  1
#define WRITE 2
#define EXECUTE 4

void printBits(long value);

int main() {

  struct termios terminalFlags;
  int result = tcgetattr(0, &terminalFlags);
  printf("tcgetattr result: %d\n", result);
  printBits(terminalFlags.c_iflag);
  terminalFlags.c_iflag |= IGNBRK;
  printBits(terminalFlags.c_iflag);
  tcsetattr(0, TCSANOW, &terminalFlags);

  char c = getchar();
  printf("%c \n", c);

  return 0;
}

void printBits(long value) {
  int number = sizeof(value)*8;
  long i = 0;
  for (i = 1; i <= number; ++i) 
  {
    printf("%ld ", (value >> (number - i)) & 1);
  }
  printf("\n");
}
