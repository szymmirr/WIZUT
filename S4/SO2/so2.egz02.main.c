#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <syscall.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

int f=1; 
void test(int a) {printf("%d\n", getpid()); f=0;}; 
 
int main(int ac, char **av) { 
  int p1, p2; 
  struct sigaction a; 
  a.sa_handler = test; 
  sigaction(SIGINT, &a, NULL); 
   
  if(ac == 1) { 
    p1=fork(); 
    if((p2=fork()) > 0) 
      execl(av[0], av[0], "1", NULL); 
  } 
  while(f); 
  return 0; 
} 
