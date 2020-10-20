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

int main() {
  int a=0, b=1, c=2, i, r[5];

  for(i=0; i<5; i++) {
    if(!(r[i] = fork())) {
      a = getpid();
      srandom(a);
      b = random()%10;
      sleep(b);
      exit(a);
    }
  }
  i = 0;
  while(-1 != waitpid(r[i], &c, 0)) {
    printf("%d %d %d %d %d\n", a, b, r[i], WEXITSTATUS(c), c);
    i++;
  }
  return 0;
}


