#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char *fifo = "myfifo";
    char message[] = "Hello from writer";

    mkfifo(fifo, 0666);

    int fd = open(fifo, O_WRONLY);

    write(fd, message, strlen(message) + 1);

    close(fd);

    return 0;
}