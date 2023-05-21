/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:08:46 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/21 03:16:06 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philos *philos, t_philo *philo)
{
	unsigned int	time;

	time = 0;
	pthread_mutex_lock(&philos->death);
	pthread_mutex_lock(&philos->last_meal);
	time = get_cur_time();
	if (philos->eat == philos->limits->eat_lim)
	{
		die_add(philos);
		die_add(philos);
		return (1);
	}
	if ((time - philo->last_meal) > (unsigned int)philos->limits->time_to_die)
	{
		die_add(philos);
		print_death_msg(philos, philo, time);
		pthread_mutex_unlock(&philos->last_meal);
		pthread_mutex_unlock(&philos->death);
		return (1);
	}
	pthread_mutex_unlock(&philos->last_meal);
	pthread_mutex_unlock(&philos->death);
	return (0);
}

void	philo_sleep(t_philos *philos, t_philo *philo)
{
	print_msg(philos, philo, MSG_SLEEP, FLG_SLEEP);
	ms_sleep(philos->limits->time_to_sleep);
	print_msg(philos, philo, MSG_THINK, FLG_THINK);
}

void	philo_eat(t_philos *philos, t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_msg(philos, philo, MSG_FORK, FLG_FORK);
	pthread_mutex_lock(philo->right_fork);
	print_msg(philos, philo, MSG_FORK, FLG_FORK);
	pthread_mutex_lock(&philos->last_meal);
	philo->last_meal = print_msg(philos, philo, MSG_EAT, FLG_EAT);
	pthread_mutex_unlock(&philos->last_meal);
	ms_sleep(philos->limits->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo_sleep(philos, philo);
}

void	one_philo_action(t_philos *philos, t_philo *philo)
{
	pthread_mutex_lock(&philos->death);
	print_msg(philos, philo, MSG_FORK, FLG_FORK);
	ms_sleep(philos->limits->time_to_die);
	die_add(philos);
	print_death_msg(philos, philo, get_cur_time());
	pthread_mutex_unlock(&philos->death);
}

void	*start_simulation(void *arg)
{
	t_philo		*philo;
	t_philos	*philos;

	philo = (t_philo *)arg;
	philos = philo->philos;
	if (philos->limits->ph_num == 1)
	{
		one_philo_action(philos, philo);
		return (NULL);
	}
	if (philo->id % 2)
		ms_sleep(philos->limits->time_to_eat);
	while (1)
	{
		if (check_eat_lim(philos, philo))
			return (NULL);
		pthread_mutex_lock(&philos->death_flag);
		if (philos->die_flag)
		{
			pthread_mutex_unlock(&philos->death_flag);
			return (NULL);
		}
		pthread_mutex_unlock(&philos->death_flag);
	}
	return (NULL);
}
