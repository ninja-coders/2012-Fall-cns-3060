#include <stdio.h>
#include <signal.h>

void f(int);
void other(int);

int run;


int main ( )
{
  run = 1;
  sigset_t responsiveSignals;
  sigemptyset(&responsiveSignals);
  sigaddset(&responsiveSignals, SIGINT);
  sigaddset(&responsiveSignals, SIGALRM);

  sigprocmask(SIG_BLOCK, &responsiveSignals, NULL);
  printf("Blocked all signals\n");
   alarm(3);
   signal ( SIGINT, f);
   signal (SIGALRM, f);
   sleep(5);
   alarm(3);
   sleep(5);
   printf("Finished the sleep, unblocking.\n");
  sigprocmask(SIG_UNBLOCK, &responsiveSignals, NULL);
  printf("Unblocked\n");

   while (run == 1) {
     printf("hello\n");
     //sleep(1);
   }

   printf("I'm done\n");

   return 0;
}

void f(int value) {
  run = 0;
  printf("In the f function.\n");

  //printf("In call: %d\n", value);
  if (SIGINT == value) 
  {
    printf("Recieved a sig INT\n");
  }
  else if (SIGALRM == value)
  {
    printf("Alarm received\n");
  }
}

void other(int value) {
  run = 0;
  printf("In the other function.\n");
}
