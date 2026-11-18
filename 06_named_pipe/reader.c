#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char *fifo = "myfifo";
    char buffer[100];

    mkfifo(fifo, 0666);

    int fd = open(fifo, O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Message received: %s\n", buffer);

    close(fd);

    return 0;
}