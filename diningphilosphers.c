#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_cond_t cond[NUM_PHILOSOPHERS];
int state[NUM_PHILOSOPHERS] = {0};

void *philosopher(void *num) {
    int id = *(int *)num;
    while (1) {
        pthread_mutex_lock(&forks[id]);
        state[id] = 1;
        if (state[(id + 4) % NUM_PHILOSOPHERS] != 2 && state[(id + 1) % NUM_PHILOSOPHERS] != 2) {
            state[id] = 2;
            printf("Philosopher %d is eating.\n", id);
            sleep(1);
            state[id] = 0;
            pthread_cond_signal(&cond[(id + 4) % NUM_PHILOSOPHERS]);
            pthread_cond_signal(&cond[(id + 1) % NUM_PHILOSOPHERS]);
        }
        pthread_mutex_unlock(&forks[id]);
        sleep(1);
    }
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int ids[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
        pthread_cond_init(&cond[i], NULL);
        ids[i] = i;
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
        pthread_cond_destroy(&cond[i]);
    }

    return 0;
}
