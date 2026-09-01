#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int sec;
  // Input validation
  if(argc != 2){
    fprintf(2, "Usage: sleep <# ticks>\n");
    exit(1);
  }

  // Convert the string to int first
  sec = atoi(argv[1]);
  // Sleep time
  sleep(sec);
  // Graceful return
  exit(0);
}
