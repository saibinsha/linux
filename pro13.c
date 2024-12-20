#include <stdio.h> 
#include <unistd.h> 
int main() { 
    pid_t pid = fork(); 
    printf(pid == 0 ? "Child\n" : pid > 0 ? "Parent\n" 
                                          : "Fork failed\n"); 
    return 0; 
} 