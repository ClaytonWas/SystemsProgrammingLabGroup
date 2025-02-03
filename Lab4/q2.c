#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void* childFunction(void *arg) {
  pthread_detach(pthread_self());
  printf("Inside thread \n");
  printf("id: %d \n", pthread_self());
  long loarg = strtol(arg, NULL, 10);
  printf("arg: %d \n", loarg);
  int *numbers = malloc(loarg * sizeof(int));
  printf("%d \n", numbers[0]);
  for (int i = 0; i<loarg; ++i) {
    numbers[i] = i;
    printf("Inserted %d into the array using child thread \n", i);
  }
  //free(numbers);
  return numbers;

}

int main(int argc, char *argv[]) {
  printf("testing: %s \n", argv[1]);

  pthread_t id;
  pthread_create(&id, NULL, &childFunction, (void *)argv[1]);
  printf("%d \n", id);


  void *result;
  pthread_join(id, &result);
  long loarg = strtol(argv[1], NULL, 10);
  printf("arg: %d \n", loarg);
  for (int i = 0; i<loarg; ++i) {
    printf("Element at index: %d \n", &result[i]);
  }
  
  free(result);

  pthread_exit(NULL);
}