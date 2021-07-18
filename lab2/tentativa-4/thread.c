// criar 2 threads onde cada uma delas irá preencher um vetor com determinados valores;

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 10
int v[SIZE];

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void *task_1(void *arg) {
  int *value = (int *)arg;
  int i = 0;

  printf("Trabalhando");
  while (1) {
    printf(".");    
    if(i == 2) {
      printf("\r.");
      i = 0;
    }
    i += 1;
    delay(1);
  }
}

void *task_2(void *arg) {
  int *value = (int *)arg;
  int i = 0;

  printf("\nSincronizando");
  while (1) {
    printf(".");    
    if(i == 2) {
      printf("\r.");
      i = 0;
    }
    i += 1;
    delay(1);
  }
}



int main() {
  pthread_t t1, t2;
  int a1 = 1;
  int a2 = 2;

  pthread_create(
    &t1, 
    NULL,
    task_1,
    (void *)(&a1)
  );

    pthread_create(
    &t2, 
    NULL,
    task_2,
    (void *)(&a2)
  );

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return 0;
}

