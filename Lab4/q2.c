#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void* childFunction(void *arg) {
  pthread_detach(pthread_self());
  printf("Child thread with ID: %d \n", pthread_self());
  long loarg = strtol(arg, NULL, 10);
  int *numbers = malloc(loarg * sizeof(int));
  for (int i = 0; i<loarg; ++i) {
    numbers[i] = i;
    printf("Inserted %d into the array using child thread \n", numbers[i]);
  }
  return (void *)numbers;

}

int main(int argc, char *argv[]) {
  pthread_t id;
  pthread_create(&id, NULL, &childFunction, (void *)argv[1]);

  int pid = pthread_self();
  printf("I am main thread with ID: %d \n", pid);

  void *result;
  pthread_join(id, &result);
  long loarg = strtol(argv[1], NULL, 10);

  int *numbers = (int *)result;

  sleep(1);

  printf("Displaying contents of array in parent thread: \n");

  for (int i = 0; i<loarg; ++i) {
    printf("Element at index %d: ", numbers[i]);
    printf("%d \n", numbers[i]);
  }

  result = NULL;
  free(result);
  free(numbers);
  //result = NULL;
  pthread_exit(NULL);

  return 0;
}