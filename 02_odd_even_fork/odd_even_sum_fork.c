#include <stdio.h>
#include <unistd.h>

int main()
{
    int n, i;
    int odd_sum = 0, even_sum = 0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        for (i = 1; i <= n; i++)
        {
            if (i % 2 != 0)
                odd_sum += i;
        }

        printf("Child process\n");
        printf("Sum of odd numbers = %d\n", odd_sum);
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
                even_sum += i;
        }

        printf("Parent process\n");
        printf("Sum of even numbers = %d\n", even_sum);
    }

    return 0;
}