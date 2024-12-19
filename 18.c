#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t full, empty, mutex;
void *producer(void *arg) {
int item = 0;
int i = 0;
while (i < 10) {
sem_wait(&empty);
sem_wait(&mutex);
buffer[in] = item;
printf("Produced item: %d\n", item++);
in = (in + 1) % BUFFER_SIZE;
sem_post(&mutex);
sem_post(&full);
sleep(1);
i++;
}
return NULL;
}
void *consumer(void *arg) {
int item;
int j = 0;
while (j < 10) {
sem_wait(&full);
sem_wait(&mutex);
item = buffer[out];
printf("Consumed item: %d\n", item);
out = (out + 1) % BUFFER_SIZE;
sem_post(&mutex);
sem_post(&empty);
sleep(2);
j++;
}
return NULL;
}
int main() {
pthread_t prod_thread, cons_thread;
sem_init(&full, 0, 0); // first 0 says it is a thread, next 0 is initial value
sem_init(&empty, 0, BUFFER_SIZE);
sem_init(&mutex, 0, 1);
pthread_create(&prod_thread, NULL, producer, NULL);
pthread_create(&cons_thread, NULL, consumer, NULL);
pthread_join(prod_thread, NULL);
pthread_join(cons_thread, NULL);
sem_destroy(&full);
sem_destroy(&empty);
sem_destroy(&mutex);
return 0;
}
