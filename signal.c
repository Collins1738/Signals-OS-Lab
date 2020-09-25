/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int i = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  i = 1;
//   exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  while(1){
    alarm(1); //Schedule a SIGALRM for 1 second
    while(i == 0); //busy wait for signal to be delivered
    printf("Turing was right!\n");
    i = 0;
}
  
  return 0; //never reached
}