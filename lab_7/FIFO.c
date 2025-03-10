#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define SIZE 4 // number of pages
#define QUEUE_SIZE 3 // max. size of the queue
int front = -1; // points to the front of the queue
int rear = -1; // points to the back of the queue
int pageFrames[SIZE];
int pageFaults = 0;

bool isEmpty()
{
return rear == -1;
}
bool isFull()
{
return rear == QUEUE_SIZE - 1;
}
//insert
void enqueue(int item) {
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear++;
    }
    pageFrames[rear] = item;
    printf("Inserted into the queue: %d\n", item);
}

// delete 
int dequeue() {
    int removed = pageFrames[0];
    // Shift all remaining elements one position to the left and remove the last one then return it
    for (int i = 0; i < rear; i++) {
        pageFrames[i] = pageFrames[i + 1];
    }
    rear--;
    if (rear < 0) {
        front = -1;
    }
    return removed;
}

// check if the number is already in the memory
bool isPageHit(int pageNumber) {
    for (int i = 0; i <= rear; i++) {
        if (pageFrames[i] == pageNumber) {
            return true;
        }
    }
    return false;
}

// if memory isnt full add the numbers 
// if it is full remove the oldest element and add the new one
void managePageFrames(int pageNumber) {
    if (!isFull()) {
        enqueue(pageNumber);
    } else {
        int removed = dequeue();
        printf("Removed from the quque: %d\n", removed);
        enqueue(pageNumber);
    }
}

int main() {
    int pages[SIZE] = {1, 2, 3, 4}; // case 1
    //int pages[SIZE] = {1, 1, 2, 3}; // case 2
    //int pages[SIZE] = {1, 2, 2, 3}; // case 3
    //int pages[SIZE] = {1, 1, 1, 1}; // case 4
    //int pages[SIZE] = {1, 3, 0, 3}; //custom case
    memset(pageFrames, -1, sizeof(pageFrames));
    
    // check if the number is in the queue if it is not in the queue add it to the queue
    for (int i = 0; i < SIZE; i++) {
        if (!isPageHit(pages[i])) {
            pageFaults++;
            managePageFrames(pages[i]);
        }
    }
    
    printf("\nTotal number of page faults: %d\n", pageFaults);
    return 0;
}


/*
Case 1:
Input:{1, 2, 3, 4};
Output:
Inserted into the queue: 1
Inserted into the queue: 2
Inserted into the queue: 3
Removed from the queue: 1
Inserted into the queue: 4

Total number of page faults: 4

------------------------------------------------

Case 2:
Input:{1, 1, 2, 3};
Output:
Inserted into the queue: 1
Inserted into the queue: 2
Inserted into the queue: 3

Total number of page faults: 3

------------------------------------------------

Case 3:
Input:{1, 2, 2, 3};
Output:
Inserted into the queue: 1
Inserted into the queue: 2
Inserted into the queue: 3

Total number of page faults: 3

------------------------------------------------

Case 4:
Input: {1, 1, 1, 1};
Output:
Inserted into the queue: 1

Total number of page faults: 1

*/