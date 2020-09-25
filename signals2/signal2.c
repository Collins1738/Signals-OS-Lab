/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int i, time = 0;

void handler(int signum)
{ //signal handler
  printf("Total time to execute program: %d \n", time);
  exit(1);
}

void alarmHandler(int signum){
  time++;
  i=1;
}

int main(int argc, char * argv[])
{
  signal(SIGINT,handler); //register handler to handle SIGINT
  signal(SIGALRM, alarmHandler);
  while(1)
  {
    alarm(1); //Schedule a SIGALRM for 1 second
    while(i == 0); //busy wait for signal to be delivered
    i = 0;
  }
}
  
//   return 0; //never reached