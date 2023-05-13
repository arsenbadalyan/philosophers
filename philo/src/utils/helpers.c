/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:08:41 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/13 17:38:57 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int print_msg(philos_t *philos, philo_t *philo, char *msg, int flag)
{
	unsigned int time;

	pthread_mutex_lock(&philos->msg);
	time = get_cur_time();
	if(flag == FLG_EAT)
		philos->eat_lim++;
	// pthread_mutex_lock(&philos->death_flag);
	if(!philos->die_flag)
		printf("%u %i %s\n", time, (philo->id + 1), msg);
	if (philos->limits->eat_lim != -1 && philos->eat_lim && philos->limits->eat_lim == (int)philos->eat_lim)
		die_add(philos);
	// pthread_mutex_unlock(&philos->death_flag);
	pthread_mutex_unlock(&philos->msg);
	return (time);
}

void print_death_msg(philos_t *philos, philo_t *philo, unsigned int time)
{
	pthread_mutex_lock(&philos->msg);
	if(philos->die_flag == 1)
		printf("%u %i %s\n", time, (philo->id + 1), MSG_DIE);
	pthread_mutex_unlock(&philos->msg);
}

int die_add(philos_t *philos)
{
	pthread_mutex_lock(&philos->death_flag);
	philos->die_flag++;
	pthread_mutex_unlock(&philos->death_flag);
	return (philos->die_flag);
}

void ft_usleep(unsigned int ms)
{
	struct timeval now;
	struct timeval start;

	gettimeofday(&now, NULL);
	gettimeofday(&start, NULL);
	while ((now.tv_sec - start.tv_sec) * 1000 +
			(now.tv_usec - start.tv_usec) / 1000 < ms)
	{
		usleep(10);
		gettimeofday(&now, NULL);
	}
}
