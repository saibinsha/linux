#include<stdio.h> 
#include<stdlib.h> 
#include<fcntl.h> 
#include<unistd.h> 
#include<sys/stat.h>
int main() {
    int fd = creat("newfile.txt", 0644); 
    close(fd);
    fd = open("inputfile.txt", O_RDONLY); lseek(fd, -6, SEEK_END);
    char buf[5]; 
    read(fd, buf, 5); 
    write(1, buf, 5); 
    printf("\n");
    struct stat info; stat("inputfile.txt", &info);
    printf("Size: %ld bytes\n", info.st_size);
    fstat(fd, &info); 
    printf("Inode: %ld\n", info.st_ino);
    close(fd);
}
