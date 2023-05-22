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
	print_msg(philos, philo, MSG_EAT, FLG_EAT);
	ms_sleep(philos->limits->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	one_philo_action(t_philos *philos, t_philo *philo)
{
	pthread_mutex_lock(&philos->msg);
	print_msg(philos, philo, MSG_FORK, FLG_FORK);
	ms_sleep(philos->limits->time_to_die);
	pthread_mutex_unlock(&philos->msg);
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
		ms_sleep(10);
	while (1)
	{
		if (check_eat_lim(philos, philo))
			return (NULL);
		if (is_dead(philos))
			return (NULL);
	}
	return (NULL);
}
