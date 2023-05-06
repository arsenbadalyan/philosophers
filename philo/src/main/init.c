#include "philo.h"

philos_t *init_philos_t()
{
	philos_t *philos;

	philos = (philos_t *)malloc(sizeof(philos_t));
	if(!philos)
		return (mem_issue(philos));
	philos->philos = NULL;
	philos->forks = NULL;
	philos->limits = (philos_lim_t *)malloc(sizeof(philos_lim_t));
	if(!philos->limits)
		return (mem_issue(philos));
	return (philos);
}

philo_t	*init_philo_list(philos_t *philos, int ph_num)
{
	philo_t	*philo_list;
	int i;

	i = -1;
	philo_list = (philo_t *)malloc(sizeof(philo_t) * ph_num);
	if(!philo_list)
		return (NULL);
	while(++i < ph_num)
	{
		philo_list[i].id = i;
		philo_list[i].philos = philos;
		philo_list[i].philo = &philos->philos[i];
		philo_list[i].left_fork = &philos->forks[(i + 1) % ph_num];
		philo_list[i].right_fork = &philos->forks[i];
		philo_list[i].last_meal = 0;
		philo_list[i].last_sleep = 0;
	}
	return (philo_list);
}

void *init_pthread_mutex(philos_t *philos)
{
	int ph_num;
	int	i;

	ph_num = philos->limits->ph_num;
	philos->philos = (pthread_t *)malloc(sizeof(pthread_t) * ph_num);
	if(!philos->philos)
		return (mem_issue(philos));
	philos->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * ph_num);
	if (!philos->forks)
		return (mem_issue(philos));
	philos->philo_list = init_philo_list(philos, ph_num);
	if(!philos->philo_list)
		return (mem_issue(philos));
	return (philos);
}
