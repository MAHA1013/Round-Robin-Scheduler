#include <stdio.h>

int main()
{
    int n, bt[20], rem[20], tq;
    int i, time = 0, count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    printf("\nExecution Sequence:\n");

    while(count < n)
    {
        for(i = 0; i < n; i++)
        {
            if(rem[i] > 0)
            {
                int t = (rem[i] > tq) ? tq : rem[i];

                time += t;
                rem[i] -= t;

                printf("P%d Remaining Time = %d\n", i+1, rem[i]);

                if(rem[i] == 0)
                {
                    count++;
                    printf("P%d Completed\n", i+1);
                }
            }
        }
    }

    printf("\nAll Processes Completed\n");

    return 0;
}
