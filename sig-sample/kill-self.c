#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


void handleKill(int);

int main ( )
{
  kill(getpid(), SIGKILL);

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
