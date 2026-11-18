#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    key_t key;
    int shmid;
    char *str;

    key = ftok("shmfile", 65);

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    str = (char *)shmat(shmid, NULL, 0);

    printf("Enter a message: ");
    fgets(str, 1024, stdin);

    printf("Message written successfully!\n");

    shmdt(str);

    return 0;
}