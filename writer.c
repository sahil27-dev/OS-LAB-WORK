#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char message[100];

    mkfifo("myfifo", 0666);

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    fd = open("myfifo", O_WRONLY);

    write(fd, message, strlen(message) + 1);

    printf("Message sent successfully!\n");

    close(fd);

    return 0;
}