#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "rand/maxrand.h"
#define NUMBER 255

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        return maxrand(NUMBER);
    } else {
        int status;
        int wc = wait(&status);
        printf("Exit validation: %d\n", WIFEXITED(status));
        printf("Output: %d\n", WEXITSTATUS(status));
    }
    return 0;
}