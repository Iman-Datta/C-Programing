
#include <stdio.h>

int main(void) {
    int n, bt[20], p[20], wt[20], tat[20];
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) return 1;

    for (int i = 0; i < n; i++) {
        printf("Burst time P%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    // Sort processes by Burst Time (Ascending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (bt[j] > bt[j + 1]) {
                int temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculate Waiting Time
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    // Calculate Turnaround Time
    printf("\nProcess\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];

        printf("P%d\t%d\t%d\t%d\n",
               p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage WT = %.2f\n", avgWT / n);
    printf("Average TAT = %.2f\n", avgTAT / n);

    return 0;
}
