#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  // Argument validation
  if(argc != 1){
    fprintf(2, "Usage: pingpong\n");
    exit(1);
  }

  // Variable declarations
  // char x = 'x';
  // int fds[2];
  int pid;

  /******** IMPLEMENTATION **********/
  pid = fork();
  if (pid < 0) {
    printf("fork() failed\n");
    exit(1);
  } else if (pid == 0) {
    printf("Parent process: %d\n", getpid());
  } else {
    printf("Child process: %d\n", getpid());
  }

  exit(0);
}
