#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key;
    int shmid;
    char *str;

    key = ftok("shmfile", 65);

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    str = (char *)shmat(shmid, NULL, 0);

    printf("Message received: %s\n", str);

    shmdt(str);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}