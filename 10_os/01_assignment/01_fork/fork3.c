# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>

int main(){
	pid_t pid = fork();

	if (pid < 0) {
		printf("\nFork failed");
	}

	else if (pid == 0){
		printf("\nChild: My PID=> %d: , and my parent's PID=> %d: ", getpid(), getppid());
		sleep(20);

		printf("\nChild woke up after 20s. My parent's PID is now = %d\n",getppid());
	}

	else{
		printf("\nParent: My PID = %d, My child's PID = %d\n", getpid(), pid);
        printf("\nParent terminating now...\n");
	}

	return 0;
}
