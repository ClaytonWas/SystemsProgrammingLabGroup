#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: %s expects 2 additional arguments. You passed %d \n.", argv[0], argc-1);
        return 1;
    }
    //process idenifier type for system calls return ids
    pid_t pid;
    //every time a fork is done pid will change
    pid = fork();


    // fork should never be negetive
    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1; 
    } else if (pid == 0) {
    // fork id of parent is never 0
        char *cmd[] = {argv[1], NULL};

        printf("I am a child process with id: %d \n", getpid());
        printf("I'll execute: %s \n", argv[1]);
        printf("Below are the results for: %s \n \n", argv[1]);

        execvp(cmd[0], cmd);
        perror("execvp");
    } else {
        char *cmd[] = {argv[2], NULL};
        wait(NULL);

        printf("\nI am a parent process with id: %d \n", getpid());
        printf("I'll execute: %s \n", argv[2]);
        printf("Below are the results for: %s \n \n", argv[2]);

        execvp(cmd[0], cmd);
        perror("execvp");
    }


    return 0; 
}
