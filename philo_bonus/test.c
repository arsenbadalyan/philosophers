#include <fcntl.h>    /* For O_* constants */
#include <sys/stat.h> /* For mode constants */
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int aa = 10;
void *sem_start(void *arg)
{
	int philo_num = 5;
	sem_t	*semaphores;
	pid_t	pid;
	semaphores = sem_open("/philo_sem", O_CREAT, S_IRUSR | S_IWUSR, 10);
	while(philo_num)
	{
		pid = fork();
		if(!pid)
			break;
		philo_num--;
	}
	if(pid)
	{
		waitpid(pid, NULL, 0);
	}
	else
	{
		sleep(--aa);
		printf("Child Process\n");
		exit(0);
	}
	printf("Main process\n");
	return ((void *)NULL);
}

int main()
{
	pthread_t thread;
	pid_t pid;
	int status;

	status = 0;
	pthread_create(&thread, NULL, &sem_start, NULL);
	pthread_join(thread, NULL);		
	return (0);
}