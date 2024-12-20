#include <stdio.h> 
#include <string.h> 
#include <sys/msg.h> 
#define MAX 512 
int main() { 
    char data[MAX], buf[50]; 
    int msgid = msgget((key_t)14534, 0666 | IPC_CREAT); 
    for (int i = 0; i < 3; i++) { 
        printf("Enter text: "); 
        fgets(buf, 50, stdin); 
        strcpy(data, buf); 
        msgsnd(msgid, &data, MAX, 0); 
    } 
    for (int i = 0; i < 3; i++) { 
        msgrcv(msgid, &data, MAX, 0, 0); 
        printf("Received: %s", data); 
    } 
    msgctl(msgid, IPC_RMID, 0); 
    return 0; 
}