/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:08:46 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/13 17:39:12 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_death(philos_t *philos, philo_t *philo)
{
	unsigned int time;

	time = 0;
	pthread_mutex_lock(&philos->death);
	time = get_cur_time();
	if((time - philo->last_meal) > (unsigned int)philos->limits->time_to_die + 10)
	{
		die_add(philos);
		print_death_msg(philos, philo, time);
	}
	pthread_mutex_unlock(&philos->death);
	return (0);
}

void philo_sleep(philos_t *philos, philo_t *philo)
{
	print_msg(philos, philo, MSG_SLEEP, FLG_SLEEP);
	ms_sleep(philos->limits->time_to_sleep);
	print_msg(philos, philo, MSG_THINK, FLG_THINK);
}

void philo_eat(philos_t *philos, philo_t *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	print_msg(philos, philo, MSG_FORK, FLG_FORK);
	check_death(philos, philo);
	philo->last_meal = print_msg(philos, philo, MSG_EAT, FLG_EAT);
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
		print_msg(philos, philo, MSG_FORK, FLG_FORK);
		ms_sleep(philos->limits->time_to_eat);
		die_add(philos);
		print_death_msg(philos, philo, get_cur_time());
		return (NULL);
	}
	if(philo->id % 2)
		ms_sleep(philos->limits->time_to_eat);
	while(1)
	{
		philo_eat(philos, philo);
		pthread_mutex_lock(&philos->death_flag);
		if(philos->die_flag)
		{
			pthread_mutex_unlock(&philos->death_flag);	
			return (NULL);
		}
		pthread_mutex_unlock(&philos->death_flag);
	}
	return (NULL);
}

// -g3 -fsanitize=thread