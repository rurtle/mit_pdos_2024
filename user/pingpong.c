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
  char x;
  char y;
  int fds[2];
  int pid;

  /******** IMPLEMENTATION **********/
  // printf("Current pid: %d\n", getpid());

  if (pipe(fds) < 0) {
    printf("pingpong: pipe failed\n");
    exit(1);
  }

  // We're in parent. Let's write 1 byte to pipe for child to read
  if (write(fds[1], "p", 1) != 1) {
    printf("pingpong (parent - before): pipe  write failed\n");
  }

  pid = fork();
  if (pid < 0) {
    printf("fork() failed\n");
    exit(1);
  } else if (pid == 0) {  // child process
    // Let's read the char sent by parent first
    if (read(fds[0], &x, 1) != 1) {
      printf("pingpong (child): pipe  read failed\n");
    } else {
      if (write(fds[1], &x, 1) != 1) {
        printf("pingpong (child): pipe write failed\n");
      } else {
        printf("%d: received ping\n", getpid());
      }
    }
  } else {  // Parent process
    wait(0);
    // Read the char sent by the child
    if (read(fds[0], &y, 1) != 1) {
      printf("pingpong (parent): pipe read failed\n");
    } else {
      printf("%d: received pong\n", getpid());
    }
  }

  // Close file handles
  close(fds[0]);
  close(fds[1]);

  exit(0);
}
