#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/stat.h> 
#include <unistd.h> 
int main() { 
    char buf[10]; 
    struct stat st; 
  
    creat("newfile.txt", 0644); 
    int fd = open("inputfile.txt", O_RDONLY); 
  
    lseek(fd, -6, SEEK_END); 
    write(1, buf, read(fd, buf, 5)); 
    printf("\n"); 
  
    if (stat("inputfile.txt", &st) == 0) { 
        printf("Size of inputfile.txt: %ld bytes\n", st.st_size); 
        fstat(fd, &st); 
        printf("Inode number of text file: %ld\n", st.st_ino); 
    } 
    close(fd); 
    return 0; 
} 