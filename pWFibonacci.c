#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUMBER 50
long fibonacci(int n) {
    if(n==0) return 0;
    else if(n==1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        long fib = fibonacci(NUMBER);
        printf("Fibonacci of %d is %ld\n", NUMBER, fib);
    } else {
        int wc = wait(NULL);
        printf("Parent says bye\n");
    }
    return 0;
}