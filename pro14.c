#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
  
int main() { 
    pid_t pid = fork(); 
    if (pid == 0) { 
        printf("Child process\n"); 
        exit(0); 
    } 
    pid > 0 ? (sleep(10), printf("Parent process\n")) 
            : perror("Fork failed"); 
    return 0; 
}