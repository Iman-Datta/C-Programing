
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t chopstick[N];

// Function executed by each philosopher thread
void *philosopher(void *arg)
{
    int id = *(int *)arg;

    int left = id;
    int right = (id + 1) % N;

    printf("Philosopher %d is thinking\n", id + 1);

    // Odd/even order breaks circular wait
    if (id % 2 == 0)
    {
        // Even philosopher: Pick left first
        pthread_mutex_lock(&chopstick[left]);
        pthread_mutex_lock(&chopstick[right]);
    }
    else
    {
        // Odd philosopher: Pick right first
        pthread_mutex_lock(&chopstick[right]);
        pthread_mutex_lock(&chopstick[left]);
    }

    printf("Philosopher %d is eating\n", id + 1);

    sleep(1);

    // Release both chopsticks
    pthread_mutex_unlock(&chopstick[left]);
    pthread_mutex_unlock(&chopstick[right]);

    printf("Philosopher %d finished eating\n", id + 1);

    return NULL;
}

int main(void)
{
    pthread_t threads[N];
    int ids[N];

    // Initialize mutex locks
    for (int i = 0; i < N; i++)
    {
        pthread_mutex_init(&chopstick[i], NULL);
    }

    // Create philosopher threads
    for (int i = 0; i < N; i++)
    {
        ids[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < N; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex locks
    for (int i = 0; i < N; i++)
    {
        pthread_mutex_destroy(&chopstick[i]);
    }

    return 0;
}
