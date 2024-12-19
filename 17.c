#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <semaphore.h>
int main() {
sem_t semaphore;
sem_init(&semaphore, 1, 1);
int fd = open("myfile.txt", O_CREAT | O_RDWR, 0644);
if (fd == -1) {
perror("Failed to open file");
exit(EXIT_FAILURE);
}
sem_wait(&semaphore); // Lock the file
printf("File is locked and data updated");
write(fd, "Good morning", 13);
sem_post(&semaphore); // Unlock the file
printf("\nFile unlocked\n");
close(fd);
sem_destroy(&semaphore);
return 0;
}
