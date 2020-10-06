#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int contador = 1;
    printf("Contador is %d (pid:%d)\n", contador, (int) getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        contador += 5;
    } else {
        contador += 2;
    }
    printf("Contador is %d (pid:%d)\n", contador, (int) getpid());
    /* 
     * Contador is 1 (pid:682)
     * Contador is 3 (pid:682)
     * Contador is 6 (pid:683)
     */
    
    return 0;
}