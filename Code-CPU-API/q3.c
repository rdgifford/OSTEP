#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("(1) hello, I am child (pid:%d)\n", (int) getpid());
    } else {
        // how would I have known this?
        usleep(10 * 1000);
        // parent goes down this path (original process)
        printf("(2) and I am the parent of %d (pid:%d)\n",
	       rc,(int) getpid());
    }
    return 0;
}
