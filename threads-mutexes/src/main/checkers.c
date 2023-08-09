/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:08:27 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/27 14:08:28 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_eaten_or_dead(t_philos *philos)
{
	int	status;

	status = EXIT_SUCCESS;
	pthread_mutex_lock(&philos->finish);
	if ((philos->limits->eat_lim != -1
			&& philos->already_eaten == philos->limits->eat_lim)
		|| philos->is_dead)
		status = EXIT_FAILURE;
	pthread_mutex_unlock(&philos->finish);
	return (status);
}

int	is_dead(t_philos *philos)
{
	int	status;

	status = EXIT_SUCCESS;
	pthread_mutex_lock(&philos->finish);
	if (philos->is_dead)
		status = EXIT_FAILURE;
	pthread_mutex_unlock(&philos->finish);
	return (status);
}

int	is_global_eaten(t_philos *philos, t_philo *philo)
{
	int	status;

	status = EXIT_SUCCESS;
	pthread_mutex_lock(&philos->finish);
	if (philos->limits->eat_lim != -1
		&& philos->limits->eat_lim == philo->already_eaten)
	{
		philos->already_eaten++;
		philo->already_eaten = -1;
		status = EXIT_FAILURE;
	}
	pthread_mutex_unlock(&philos->finish);
	return (status);
}

void	iterate_philo_eaten(t_philos *philos, t_philo *philo)
{
	pthread_mutex_lock(&philos->finish);
	philo->already_eaten++;
	pthread_mutex_unlock(&philos->finish);
}

void	iterate_dead(t_philos *philos)
{
	pthread_mutex_lock(&philos->finish);
	philos->is_dead = 1;
	pthread_mutex_unlock(&philos->finish);
}
