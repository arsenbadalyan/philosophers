/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:08:41 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/21 02:55:07 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	print_msg(t_philos *philos, t_philo *philo,
							char *msg, int flag)
{
	unsigned int	time;

	pthread_mutex_lock(&philos->msg);
	pthread_mutex_lock(&philos->death_flag);
	time = get_cur_time();
	if (flag == FLG_EAT)
		philo->already_eat++;
	if (!philos->die_flag)
		printf("%u %i %s\n", time, (philo->id + 1), msg);
	pthread_mutex_unlock(&philos->death_flag);
	pthread_mutex_unlock(&philos->msg);
	return (time);
}

void	print_death_msg(t_philos *philos, t_philo *philo, unsigned int time)
{
	pthread_mutex_lock(&philos->msg);
	pthread_mutex_lock(&philos->death_flag);
	if (philos->die_flag == 1)
		printf("%u %i %s\n", time, (philo->id + 1), MSG_DIE);
	pthread_mutex_unlock(&philos->death_flag);
	pthread_mutex_unlock(&philos->msg);
}

int	die_add(t_philos *philos)
{
	pthread_mutex_lock(&philos->death_flag);
	philos->die_flag++;
	pthread_mutex_unlock(&philos->death_flag);
	return (philos->die_flag);
}

int	check_eat_lim(t_philos *philos, t_philo *philo)
{
	philo_eat(philos, philo);
	pthread_mutex_lock(&philos->death_flag);
	if (philos->limits->eat_lim != -1
		&& philos->limits->eat_lim == philo->already_eat)
	{
		pthread_mutex_lock(&philos->death);
		philos->eat++;
		pthread_mutex_unlock(&philos->death);
		pthread_mutex_unlock(&philos->death_flag);
		return (1);
	}
	pthread_mutex_unlock(&philos->death_flag);
	philo_sleep(philos, philo);
	return (0);
}
