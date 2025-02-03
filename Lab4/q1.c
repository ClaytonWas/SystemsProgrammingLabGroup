#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 3 && argc != 1) {
        fprintf(stderr, "Error: %s expects 2 additional arguments. You passed %d \n.", argv[0], argc-1);
        return 1;
    }
    //process idenifier type for system calls return ids
    pid_t pid;
    //every time a fork is done pid will change
    pid = fork();

    char *cmd1[] = {"ls", NULL};
    char *cmd2[] = {"ls", NULL};
    if (argc == 3) {
        cmd1[0] = argv[1];
        cmd2[0] = argv[2];
    }

    // fork should never be negetive
    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1; 
    } else if (pid == 0) {
    // fork id of parent is never 0
        printf("I am a child process with id: %d \n", getpid());
        printf("I'll execute: %s \n", cmd1[0]);
        printf("Below are the results for: %s \n \n", cmd1[0]);

        execvp(cmd1[0], cmd1);
        perror("execvp");
    } else {
        wait(NULL);

        printf("\nI am a parent process with id: %d \n", getpid());
        printf("I'll execute: %s \n", cmd2[0]);
        printf("Below are the results for: %s \n \n", cmd2[0]);

        execvp(cmd2[0], cmd2);
        perror("execvp");
    }


    return 0; 
}
