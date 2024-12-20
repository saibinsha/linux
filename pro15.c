#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
  
int main() { 
    int fd[2]; 
    char buf[100]; 
    pipe(fd); 
    pid_t p = fork(); 
    if (p > 0) { 
        printf("Parent passing value to child\n"); 
        write(fd[1], "hello\n", 6); 
    } else { 
        printf("Child printing received value\n"); 
        write(1, buf, read(fd[0], buf, 100)); 
    } 
    return 0; 
} 