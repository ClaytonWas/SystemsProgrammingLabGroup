#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

//https://www.geeksforgeeks.org/fork-system-call/

int main() {

    //process idenifier type
    //whenever a system call is made the system will return a 
    //unique identifier which is this type
    pid_t pid;

    //every system call return a pid we are just recieving it 
    //every time a fork is done pid will change
    //from here we have 2*number of forks loops including this line
    pid = fork(); // first child process

    // fork should never be negetive
    if (pid < 0) {
        
        fprintf(stderr, "Fork failed");
        return 1; 


    // fork id of a child is always 0 and parent is never 0


    } else if (pid == 0) {
        printf("************************child***************************");
        printf("Child Process: PID = %d\n", getpid()); // Print child's PID

    } else {
        printf("***************************parent***********************");
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid); // Print both parent's and child's PID
    }


    return 0; 
}

// bruh after runnning this i could run the child or parent from vscode seperatley
