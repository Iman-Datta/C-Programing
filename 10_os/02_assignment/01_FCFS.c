#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <bt1> <bt2>...\n", argv[0]);
        return 1;
    }

    int n = argc - 1;
    int bt[20], wt[20], tat[20];
    float wtrang = 0, tatrang = 0;

    for (int i = 0; i < n; i++) {
        bt[i] = atoi(argv[i + 1]);
        wt[0] = 0;
        tat[0] = bt[0];

        for (int i = 1; i < n; i++) {
            wt[i] = wt[i - 1] + bt[i - 1];
            tat[i] = tat[i - 1] + bt[i];
        }
    }

    printf("PID\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        wtrang += wt[i];
        tatrang += tat[i];

        printf("P%d\t%d\t%d\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time: %.2f\n", wtrang / n);
    printf("Average turnaround time: %.2f\n", tatrang / n);

    return 0;
}