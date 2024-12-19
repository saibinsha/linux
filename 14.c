#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
int main() {
    if(fork() == 0) { printf("Child process\n"); exit(0); }
    else { sleep(10); printf("Parent process\n"); }
}
