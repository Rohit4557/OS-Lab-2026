#include <stdio.h>

int main()
{
    int n, i, j;
    int bt[100], priority[100], wt[100], tat[100];
    int temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Enter priority for P%d: ", i + 1);
        scanf("%d", &priority[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (priority[j] < priority[i])
            {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], priority[i], wt[i], tat[i]);
    }

    return 0;
}