#include <stdio.h>
#define P 5 // Number of processes
#define R 4 // Number of resource types


void findSafeSequence(int alloc[P][R], int max[P][R], int available[R]) {
    int need [ P ][ R ]; // Need Matrix
    int finish [ P ] = {0}; // Tracks finished processes
    int safeSeq [ P ]; // Stores the safe sequence
    int work [ R ]; // Available resources
    int count = 0; // Counter for safe sequence

    // TODO : Calculate Need Matrix : Need [ i ][ j ] = Max [ i ][ j ] - Allocation [ i ][ j ]
    // max minus what is allocated gives us the need matrix
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // copying avalable resources into work
    for (int i = 0; i < R; i++) {
        work[i] = available[i];
    }

    // TODO : Finding the safe sequence
    int found;
    do {
        // we need to find a way to stop the loop if we dont find any processes found the is the flag for that.
        found = 0;
        for (int i = 0; i < P; i++) {
            // if the process is not completed check if that process is safe or not
            if (!finish[i]) {
                int j;
                for (j = 0; j < R; j++)
                    // if our need is more than our available resources(work) we need to break the loop early.
                    if (need[i][j] > work[j])
                        break;
                //if the loop didnt break it means our resources are enough so that means the process is safe
                if (j == R) { 
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[i][k];
                    
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        // as long as there is at least one safe process continue. (because it means now we have more resources to allocate and what was previously unsafe is now safe.)
    } while (found);

    // if the number of safe processes are less than all the proccesses then there is no safe sequence.
    if (count < P) {
        printf("System is in an UNSAFE state!\n");
        return;
    }

    
    printf("System is in a SAFE state.\nSafe sequence: ");
    for (int i = 0; i < P; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int alloc[P][R] = {
        {0, 1, 0, 2},
        {2, 0, 0, 1},
        {3, 0, 2, 1},
        {2, 1, 1, 0},
        {0, 0, 2, 2}
    };
    int max[P][R] = {
        {6, 4, 3, 4},
        {3, 2, 2, 2},
        {9, 1, 2, 4},
        {2, 2, 2, 1},
        {4, 3, 3, 4}
    };
    int available[R] = {3, 3, 2, 2};

    // Call function to find the safe sequence
    findSafeSequence(alloc, max, available);
    return 0;
}
