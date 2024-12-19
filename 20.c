#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 100

struct message {
    long msg_type;
    char msg_text[MSG_SIZE];
};

int main() {
    key_t key = ftok("msgqueue", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    struct message msg;
    msg.msg_type = 1;
    printf("Enter message: ");
    fgets(msg.msg_text, MSG_SIZE, stdin);

    if (msgsnd(msgid, &msg, sizeof(msg), 0) == -1) {
        perror("msgsnd failed");
        exit(1);
    }

    if (msgrcv(msgid, &msg, sizeof(msg), 1, 0) == -1) {
        perror("msgrcv failed");
        exit(1);
    }

    printf("Received message: %s\n", msg.msg_text);

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}

