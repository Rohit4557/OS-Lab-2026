#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child process exiting\n");
    }
    else
    {
        printf("Parent process sleeping\n");
        sleep(20);
        printf("Parent process exiting\n");
    }

    return 0;
}