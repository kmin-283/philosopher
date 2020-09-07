#include <stdio.h> 
#include <pthread.h> 
#include <fcntl.h>
#include <semaphore.h> 
#include <unistd.h> 
  
sem_t mutex; 
sem_t *t;

void* thread(void* arg) 
{ 
    //wait 
    // sem_wait(&mutex);
    sem_wait(t);
    printf("\nEntered..\n"); 
  
    //critical section 
    //signal 
    printf("\nJust Exiting...\n"); 
    // sem_post(&mutex);
    sem_post(t);
} 
  
  
int main() 
{
    t = sem_open("/mutex", O_CREAT, 0644, 1); 
	// sem_init(&mutex, 0, 1);
    pthread_t t1,t2; 
    pthread_create(&t1,NULL,thread,NULL); 
    pthread_create(&t2,NULL,thread,NULL); 
    pthread_join(t1,NULL); 
    pthread_join(t2,NULL); 
    sem_destroy(&mutex); 
    return 0; 
} 