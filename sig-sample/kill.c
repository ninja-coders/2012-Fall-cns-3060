#include <stdio.h>
#include <signal.h>

void handleKill(int);

int main ( )
{
   signal(SIGKILL, handleKill);

   while (1) {
     printf("hello\n");
     sleep(1);
   }

   printf("I'm done\n");

   return 0;
}

void handleKill(int value)
{
  printf("Start of kill\n");
  int i = 0;
  for (i = 0; i < 10; ++i) 
  {
    printf("In Kill\n");
    sleep(1);
  }
}
