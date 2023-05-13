#include "philo.h"

int check_death(philos_t *philos, philo_t *philo)
{
	unsigned int time;

	time = 0;
	pthread_mutex_lock(&philos->death);
	time = get_cur_time();
	if((time - philo->last_meal) > (unsigned int)philos->limits->time_to_die + 10)
	{
		philos->die_flag++;
		print_death_msg(philos, philo, time);
	}
	pthread_mutex_unlock(&philos->death);
	return (0);
}

void philo_sleep(philos_t *philos, philo_t *philo)
{
	print_msg(philos, philo, MSG_SLEEP);
	ms_sleep(philos->limits->time_to_sleep);
	print_msg(philos, philo, MSG_THINK);
}

void philo_eat(philos_t *philos, philo_t *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	print_msg(philos, philo, MSG_FORK);
	check_death(philos, philo);
	philos->eat_lim++;
	philo->last_meal = print_msg(philos, philo, MSG_EAT);
	ms_sleep(philos->limits->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo_sleep(philos, philo);
}

void *start_simulation(void *arg)
{
	philo_t		*philo;
	philos_t	*philos;

	philo = (philo_t *)arg;
	philos = philo->philos;
	if(philos->limits->ph_num == 1)
	{
		print_msg(philos, philo, MSG_FORK);
		ms_sleep(philos->limits->time_to_eat);
		philos->die_flag++;
		print_death_msg(philos, philo, get_cur_time());
		return (NULL);
	}
	if(philo->id % 2)
		ms_sleep(philos->limits->time_to_eat);
	while(!philos->die_flag)
	{
		philo_eat(philos, philo);
	}
	return (NULL);
}

// -g3 -fsanitize=thread