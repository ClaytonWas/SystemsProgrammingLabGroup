#include <stdio.h>
#include <stdlib.h>

// the struct in the introduction
struct Process {
    int pid;        
    int burstTime;  
    int priority;   
};


int compare(const void *a, const void *b) {

    struct Process *p1 = (struct Process *)a;
    struct Process *p2 = (struct Process *)b;
    return p1->priority - p2->priority;

}

// calculate and print w8 times
void calculateTimes(struct Process processes[], int n) {

    int waitTime[n]; 
    int turnAroundTime[n];
    int totalWaitTime = 0;
    float averageWaitTime = 0;

    // first process has no waiting time
    waitTime[0] = 0;
    turnAroundTime[0] = processes[0].burstTime;

    // calculating wait time and turnaround time for each process
    for (int i = 1; i < n; i++) {
        waitTime[i] = waitTime[i - 1] + processes[i - 1].burstTime;
        turnAroundTime[i] = waitTime[i] + processes[i].burstTime;
    }

    //  print the calculations
    printf("\nPID\tBurst Time\tPriority\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        totalWaitTime += waitTime[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].pid, processes[i].burstTime, processes[i].priority,
               waitTime[i], turnAroundTime[i]);
    }


    averageWaitTime = (float)totalWaitTime / n;
    printf("\nAverage Wait Time: %.2f\n", averageWaitTime);
}


int main() {
    struct Process processes[5] = {
        {1, 10, 3}, {2, 1, 1}, {3, 2, 4}, {4, 1, 5}, {5, 5, 2}
    };

    printf("Before Sorting:\n");
    for (int i = 0; i < 5; i++) {
        printf("PID: %d, Burst Time: %d, Priority: %d\n",
               processes[i].pid, processes[i].burstTime, processes[i].priority);
    }

 
    qsort(processes, 5, sizeof(struct Process), compare);


    printf("\nAfter Sorting:\n");
    for (int i = 0; i < 5; i++) {
        printf("PID: %d, Burst Time: %d, Priority: %d\n",
               processes[i].pid, processes[i].burstTime, processes[i].priority);
    }


    calculateTimes(processes, 5);

    return 0;
}
