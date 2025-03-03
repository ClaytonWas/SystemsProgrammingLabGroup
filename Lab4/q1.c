#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])  {
    //process idenifier type for system calls return ids
    pid_t pid;
    // let the argument list be what is in the command promt
    char* argument_list1[] = {argv[1], NULL};
    // let the argument list be what is in the command promt
    char* argument_list2[] = {argv[2], NULL};

    //every time a fork is done pid will change
    pid = fork();

    
    // fork should never be negetive
    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1; 
    } else if (pid == 0) {
    // fork id of parent is never 0

        printf("****************************************************\n");
        printf("im running %s\n",argv[1]);
        printf("I am a child process with id: %d \n also exe should run here\n", getpid());
        execvp(argv[1], argument_list1);
        printf("I'll execute: command1 \n");
        printf("Below are the results for: command1 \n");
    } else {

        wait(NULL);
        printf("****************************************************\n");
        printf("im running %s\n",argv[2]);
        printf("I am a parent process with id: %d \n\n", getpid());
        execvp(argv[2], argument_list2);
        printf("I'll execute: command2 \n");
        printf("Below are the results for: command2 \n \n");
    }


    return 0; 
}