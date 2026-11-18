#include <stdio.h>

int main()
{
    int pages[100], frames[20], recent[20];
    int n, f;
    int i, j;
    int faults = 0;
    int found, pos, least;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
    {
        frames[i] = -1;
        recent[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        found = 0;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                recent[j] = i;
                break;
            }
        }

        if (!found)
        {
            pos = -1;

            for (j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
            {
                least = 0;

                for (j = 1; j < f; j++)
                {
                    if (recent[j] < recent[least])
                        least = j;
                }

                pos = least;
            }

            frames[pos] = pages[i];
            recent[pos] = i;
            faults++;
        }

        printf("\n%d: ", pages[i]);

        for (j = 0; j < f; j++)
            printf("%d ", frames[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}