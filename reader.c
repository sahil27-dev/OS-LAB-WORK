#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int fd;
    char message[100];

    fd = open("myfifo", O_RDONLY);

    read(fd, message, sizeof(message));

    printf("Message received: %s\n", message);

    close(fd);

    return 0;
}