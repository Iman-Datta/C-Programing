
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid;

    // 1. Parent waits for child
    printf("\n--- Parent Waiting for Child ---\n");

    pid = fork();

    if (pid == 0) {
        printf("Child Process: PID = %d\n", getpid());
        sleep(2);
        printf("Child Process Finished\n");
        exit(0);
    }
    else if (pid > 0) {
        wait(NULL);
        printf("Parent Process: Child completed\n");
    }

    // 2. Zombie Process
    printf("\n--- Zombie Process ---\n");

    pid = fork();

    if (pid == 0) {
        printf("Child Process Finished\n");
        exit(0);
    }
    else if (pid > 0) {
        sleep(5);
        printf("Parent now collects child status\n");
        wait(NULL);
    }

    // 3. Orphan Process
    printf("\n--- Orphan Process ---\n");

    pid = fork();

    if (pid == 0) {
        sleep(3);
        printf("Child PID = %d\n", getpid());
        printf("New Parent PID = %d\n", getppid());
    }
    else if (pid > 0) {
        printf("Parent exiting before child\n");
        exit(0);
    }

    return 0;
}
