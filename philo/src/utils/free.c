#include "philo.h"

void *free_single(void **addr)
{
	if (*addr)
	{
		free(*addr);
		*addr = 0;
	}
	return (0);
}

void *free_double(void ***addr)
{
	int i;

	i = 0;
	if (*addr)
	{
		while ((*addr)[i])
		{
			free_single(&(*addr)[i]);
			i++;
		}
		free_single((void *)&(*addr));
	}
	return (0);
}

void *free_all_mem(philos_t *philos)
{
	int	i;

	i = -1;
	while(++i < philos->limits->ph_num)
		pthread_mutex_destroy(&philos->forks[i]);
	free_single((void *)&(philos->limits));
	free_single((void *)&(philos->philo_list));
	free_single((void *)&(philos->philos));
	free_single((void *)&(philos->forks));
	free_single((void *)&(philos));
	return (NULL);
}