#include <fcntl.h> 
#include <semaphore.h> 
#include <stdio.h> 
#include <unistd.h> 
int main() { 
    sem_t sem; 
    sem_init(&sem, 1, 1); 
    int fd = open("myfile.txt", O_CREAT | O_RDWR, 0644); 
  
    sem_wait(&sem); 
    printf("File is locked and data updated"); 
    write(fd, "Good morning", 12); 
    sem_post(&sem); 
    printf("\nFile unlocked\n"); 
  
    close(fd); 
    sem_destroy(&sem); 
    return 0; 
} 