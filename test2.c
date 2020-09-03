#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void logger(const char *msg) {
    pthread_mutex_lock(&lock);
    printf("%s", msg);
    fflush(stdout);
    pthread_mutex_unlock(&lock);
}

void *A(void *arg) {
    fprintf(stderr, "AAA");
    logger("Inside thread A");
    return NULL;
}

void *B(void *arg) {
    fprintf(stderr, "BBB");
    logger("Inside thread A");
    return NULL;
}

pthread_t t_id[2];

int main() {
    int s1 = pthread_create(&(t_id[0]), NULL, &A, NULL);
    int s2 = pthread_create(&(t_id[1]), NULL, &B, NULL);

    if (s1 || s2) {
        perror("ERROR: Create thread");
        exit(2);
    }

    // EDIT; THIS WAS MISSING
    pthread_join(t_id[0], NULL);
    pthread_join(t_id[1], NULL);

    return 0;
}