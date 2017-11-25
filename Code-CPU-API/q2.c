#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int
main() {
  int filedesc = open("q2.txt", O_WRONLY);
  int rc = fork();
  if(filedesc < 0) {
    return 1;
  }

  if (rc < 0) {
      // fork failed; exit
      fprintf(stderr, "fork failed\n");
      exit(1);
  } else if (rc == 0) {
      // child (new process)
      // why do we need the asterisk here?
      const char * child_msg = "This will be output to q2.txt from a child process\n";
      printf("hello, I am child (pid:%d)\n", (int) getpid());
      write(filedesc, child_msg, strlen(child_msg));
  } else {
      // parent goes down this path (original process)
      const char * parent_msg = "This will be output to q2.txt from a parent process\n";
      printf("hello, I am parent of %d (pid:%d)\n",
       rc, (int) getpid());
      write(filedesc, parent_msg, strlen(parent_msg));
  }
  close(filedesc);
  printf("filedesc: %d\n", filedesc);
  return 0;
}
