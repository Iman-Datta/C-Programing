
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void run_exec_demo()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        char *args[] = {"ls", "-l", "testdir", NULL};

        execvp(args[0], args);

        perror("execvp failed");
        exit(1);
    }
    else if (pid > 0)
    {
        int status;

        wait(NULL)

        printf("Child execution complete.\n");
    }
    else
    {
        perror("Fork failed");
    }
}

int main()
{
    run_exec_demo();
    return 0;
}
