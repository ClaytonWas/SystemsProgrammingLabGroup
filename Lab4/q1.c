#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
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
        char *args[] = {"ls", NULL};

        printf("I am a child process with id: %d \n", getpid());
        printf("I'll execute: ls \n");
        printf("Below are the results for: command1 \n \n");

        execvp(args[0], args);
        perror("execvp");
    } else {
        char *args[] = {"cal", NULL};

        printf("I am a parent process with id: %d \n", getpid());
        printf("I'll execute: whoami \n");
        printf("Below are the results for: command2 \n \n");

        execvp(args[0], args);
        perror("execvp");
    }


    return 0; 
}
