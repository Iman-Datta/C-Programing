
#include <stdio.h>

#define N 3
#define M 3

int request[M] = {1, 0, 2};

int need[N][M] = {
    {2, 1, 1},
    {1, 2, 2},
    {3, 1, 2}
};

int available[M] = {3, 3, 2};

int verify_request(int pid, int m)
{
    for (int j = 0; j < m; j++)
    {
        // Check 1: Request <= Need
        if (request[j] > need[pid][j])
        {
            printf("Request exceeds Need\n");
            return 0;
        }

        // Check 2: Request <= Available
        if (request[j] > available[j])
        {
            printf("Resources not available\n");
            return 0;
        }
    }

    return 1;
}

int main()
{
    int pid = 1;

    if (verify_request(pid, M))
        printf("Request is valid\n");
    else
        printf("Request is invalid\n");

    printf("Available: ");
    for (int j = 0; j < M; j++)
        printf("%d ", available[j]);

    printf("\n");

    return 0;
}
