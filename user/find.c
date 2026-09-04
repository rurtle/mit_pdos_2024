#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  // Input validation
  if(argc != 3){
    fprintf(2, "Usage: find <path> <filename>\n");
    exit(1);
  }

  // Graceful return
  exit(0);
}
