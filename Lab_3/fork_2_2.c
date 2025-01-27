#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid1, pid2;

    //*************fork1***************************
    // fork 1 shouldnt be negetive
    pid1 = fork();

    if (pid1 < 0) {
        fprintf(stderr, "First fork failed\n");
        return 1; 
    }

    //*************fork2***************************
    // fork 2 shouldnt be negetive
    pid2 = fork();

    if (pid2 < 0) {
        fprintf(stderr, "Second fork failed\n");
        return 1;
    }

    //*************process identifications***************************
    // if pid 1 is 0 we are in the first child otherwise we are in parent
    // if pid 2 is 0 we are in the second child
    if (pid1 == 0 && pid2 == 0) {
        // pid 1 is 0 so we are in the first child and because pid2 is zero we are in the child of the first child process which is child of the child
        printf("Child of First Child: PID = %d\n", getpid());
    } else if (pid1 == 0 && pid2 > 0) {
        // pid 1 is 0 so we are in the first child and because pid2 is greater than zero its the parent and parent of what is under first child is first child
        printf("First Child: PID = %d\n", getpid());
    } else if (pid1 > 0 && pid2 == 0) {
        // because pid 1 is not zero we are in parent and because pid 2 is zero we are in the second child of the parent
        printf("Second Child (by Parent): PID = %d\n", getpid());
    } else if (pid1 > 0 && pid2 > 0) {
        // we are in parent because poth pids are not 0
        printf("Parent: PID = %d\n", getpid());
    }

    return 0; 
}
