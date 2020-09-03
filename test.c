#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

pthread_mutex_t mutex_lock;

int g_count;

void	*t_function(void *data)
{
	void	*ptr = NULL;
	int		i;
	char	*thread_name = (char *)data;

	pthread_mutex_lock(&mutex_lock);
	for (i = 0; i < 3; i++)
	{
		printf("%s Count %d\n",thread_name, g_count);
		g_count++;
		sleep(1);
	}
	pthread_mutex_unlock(&mutex_lock);
	return (ptr);
}

void	*t_function2(void *data)
{
	void	*ptr = NULL;
	int		i;
	char	*thread_name = (char *)data;

	// pthread_mutex_lock(&mutex_lock);
	for (i = 0; i < 3; i++)
	{
		printf("%s Count %d\n",thread_name, g_count);
		g_count++;
		sleep(1);
	}
	// pthread_mutex_unlock(&mutex_lock);
	return (ptr);
}

int		main(void)
{
	pthread_t	p_thread1, p_thread2;
	struct timeval mytime;
	int			status;

	pthread_mutex_init(&mutex_lock, NULL);

	pthread_create(&p_thread1, NULL, t_function, (void *)"thread 1");
	pthread_create(&p_thread2, NULL, t_function2, (void *)"thread 2");
	
	pthread_join(p_thread1, (void *)&status);
	pthread_join(p_thread2, (void *)&status);

	return (0);
}