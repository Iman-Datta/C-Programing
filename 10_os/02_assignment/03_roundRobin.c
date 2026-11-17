
#include <stdio.h>

int main(void) {
    int n, bt[20], rem[20], wt[20] = {0}, tat[20];
    int tq, time = 0, done;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) return 1;

    for (int i = 0; i < n; i++) {
        printf("Burst time P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    if (tq <= 0) return 1;

    // Round Robin Scheduling
    do {
        done = 1;

        for (int i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = 0;

                if (rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                }
                else {
                    time += rem[i];
                    rem[i] = 0;

                    tat[i] = time;
                    wt[i] = tat[i] - bt[i];
                }
            }
        }
    } while (!done);

    // Display results
    printf("\nProcess\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];

        printf("P%d\t%d\t%d\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage WT = %.2f\n", avgWT / n);
    printf("Average TAT = %.2f\n", avgTAT / n);

    return 0;
}
