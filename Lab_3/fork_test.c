#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid1, pid2, pid3;

    //*************fork1***************************
    pid1 = fork();
    if (pid1 < 0) {
        fprintf(stderr, "First fork failed\n");
        return 1; 
    }

    //*************fork2***************************
    pid2 = fork();
    if (pid2 < 0) {
        fprintf(stderr, "Second fork failed\n");
        return 1;
    }

    //*************fork3***************************
    pid3 = fork();
    if (pid3 < 0) {
        fprintf(stderr, "Third fork failed\n");
        return 1;
    }

    if (pid1 > 0) {
        fprintf(stderr, "galdim\n");
    }

    return 0;
}
