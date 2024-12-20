#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
int main() { 
    int src_fd = open("source.txt", O_RDONLY); 
    int dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); 
  
    if (src_fd == -1 || dest_fd == -1) { 
        perror("File operation failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    char buf[1024]; 
    ssize_t n; 
    while ((n = read(src_fd, buf, sizeof(buf))) > 0) 
        write(dest_fd, buf, n); 
  
    close(src_fd); 
    close(dest_fd); 
    printf("Copied.\n"); 
    return 0; 
} 