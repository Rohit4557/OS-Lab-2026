#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child process is running\n");
        sleep(2);
        printf("Child process completed\n");
    }
    else
    {
        wait(NULL);
        printf("Parent process continues after child completion\n");
    }

    return 0;
}