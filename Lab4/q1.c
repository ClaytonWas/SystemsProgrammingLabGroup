#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc) {
    //process idenifier type for system calls return ids
    pid_t pid;

    //every time a fork is done pid will change
    pid = fork();

    printf(argc);
    
    // fork should never be negetive
    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1; 
    } else if (pid == 0) {
    // fork id of parent is never 0
        printf("I am a child process with id: %d \n", getpid());
        printf("I'll execute: command1 \n");
        printf("Below are the results for: command1 \n");
    } else {
        printf("I am a parent process with id: %d \n", getpid());
        printf("I'll execute: command2 \n");
        printf("Below are the results for: command2 \n \n");
    }


    return 0; 
}
