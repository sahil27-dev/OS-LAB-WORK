#include <stdio.h>

int main()
{
    int n, f, i, j, k = 0, flag;
    int pages[50], frames[10];
    int faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++)
    {
        flag = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            frames[k] = pages[i];
            k = (k + 1) % f;
            faults++;
        }

        printf("\n%d\t", pages[i]);

        for(j = 0; j < f; j++)
        {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }

        if(flag == 0)
            printf("\tPage Fault");
        else
            printf("\tHit");
    }

    printf("\n\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", n - faults);

    return 0;
}