#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long msg_type;
    char msg_text[100];
};

int main()
{
    key_t key;
    int msgid;
    struct message msg;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);

    msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);

    printf("Message received: %s\n", msg.msg_text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}