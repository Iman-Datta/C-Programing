#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pid = fork();

    if (pid < 0) {
        printf("Fork failed: Memory error.\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("I am the child. My PID: %d\n", getpid());
        printf("My parent's PID: %d\n", getppid());
    }
    else {
        // Parent process
        printf("I am the parent. My PID: %d\n", getpid());
        printf("My child's PID is: %d\n", pid);
    }

    return 0;
}
