#include <stdio.h>

int main()
{
    int pages[100], frames[20];
    int n, f;
    int i, j;
    int pointer = 0;
    int faults = 0;
    int found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    for (i = 0; i < n; i++)
    {
        found = 0;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            frames[pointer] = pages[i];
            pointer = (pointer + 1) % f;
            faults++;
        }

        printf("\n%d: ", pages[i]);

        for (j = 0; j < f; j++)
            printf("%d ", frames[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}