/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:08:41 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/27 23:54:19 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	print_msg(t_philos *philos, t_philo *philo,
							char *msg, int flag)
{
	unsigned int	time;

	time = get_cur_time();
	if (flag == FLG_EAT)
	{
		pthread_mutex_lock(&philos->last_meal);
		philo->last_meal = time;
		pthread_mutex_unlock(&philos->last_meal);
		iterate_philo_eaten(philos, philo);
	}
	pthread_mutex_lock(&philos->msg);
	if (!is_dead(philos))
		printf("%u %i %s\n", (time + 1), (philo->id + 1), msg);
	pthread_mutex_unlock(&philos->msg);
	return (time);
}

void	print_death_msg(t_philos *philos, t_philo *philo, unsigned int time)
{
	pthread_mutex_lock(&philos->msg);
	if (!is_dead(philos))
	{
		printf("%u %i %s\n", (time + 1), (philo->id + 1), MSG_DIE);
		iterate_dead(philos);
	}
	pthread_mutex_unlock(&philos->msg);
}

int	check_eat_lim(t_philos *philos, t_philo *philo)
{
	philo_eat(philos, philo);
	if (is_global_eaten(philos, philo))
		return (EXIT_FAILURE);
	philo_sleep(philos, philo);
	return (EXIT_SUCCESS);
}
