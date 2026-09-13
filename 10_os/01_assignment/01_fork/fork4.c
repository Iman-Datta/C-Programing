#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed! Memory error.\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process terminates immediately
        printf("Child: My PID = %d, terminating immediately.\n", getpid());
    }
    else {
        // Parent process sleeps and does NOT call wait()
        printf("Parent: My PID = %d, Child's PID = %d, sleeping for 20s...\n",getpid(), pid);               

        sleep(20);
        printf("Parent woke up!\n");
    }

    return 0;
}