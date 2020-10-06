#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Got %d arguments\n", argc);
    for(int i=0; i<=argc; ++i) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    execvp(argv[1], &argv[1]);
    printf("An error ocurred\n");
    
    return 0;
}