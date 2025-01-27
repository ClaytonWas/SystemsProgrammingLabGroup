#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid1, pid2;

    //*************fork1***************************
    // First fork to create the first child process
    pid1 = fork();

    // fork should never be negative
    if (pid1 < 0) {
        fprintf(stderr, "First fork failed\n");
        return 1; // Exit with an error code


    } else if (pid1 == 0) {

      
        // Inside the first child process

        // if we are inside the child of the first fork create another fork
        //*************fork2 if child***************************
        pid2 = fork();

        // fork should never be negative (this is for second fork)
        if (pid2 < 0) {
            fprintf(stderr, "Second fork failed\n");
            return 1;
        } 
        //if pid2 is 0 then we are inside the child of the pid1 child 
        // else it would be the parent which is child 1 
        else if (pid2 == 0) {
            
            printf("*************************Child of First Child*************************\n");
            printf("Child of First Child: PID = %d\n", getpid());
        } 
        else {
            
            printf("*************************First Child*************************\n");
            printf("First Child Process: PID = %d, My Child PID = %d\n", getpid(), pid2);
        }
    //**************************end of child 1 */


    } else {
       
        // Inside the parent process

        //*************fork2 if parent***************************
        pid2 = fork();

        // fork should never be negative
        if (pid2 < 0) {
            fprintf(stderr, "Second fork failed\n");
            return 1;

        } 
        //since pid2 is not 0 we are in parent
        //if pid 2 is 0 another child for parent will be created
        // else it would be parent 
        else if (pid2 == 0) {
            printf("*************************Second Child (by Parent)*************************\n");
            printf("Second Child Process (by Parent): PID = %d\n", getpid());
        }
         else {
            printf("*************************Parent*************************\n");
            printf("Parent Process: PID = %d, First Child PID = %d, Second Child PID = %d\n", getpid(), pid1, pid2);
        }
    }

    return 0; 
}
