#include<stdio.h> 
#include<unistd.h>
int main() {
    if(fork() == 0)
    printf("Child\n");
    else 
    printf("Parent\n");
}
