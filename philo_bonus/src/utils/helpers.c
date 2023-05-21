/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:08:41 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/20 20:48:14 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	print_msg(t_philos *philos, t_philo *philo, char *msg, int flag)
{
	unsigned int	time;

	time = get_cur_time();
	if (flag == FLG_EAT)
		philo->eat_lim++;
	sem_wait(philos->msg);
	if (!philos->die_flag)
		printf("%u %i %s\n", time, (philo->id + 1), msg);
	sem_post(philos->msg);
	if (philos->limits->eat_lim != -1
		&& philos->limits->eat_lim == philo->eat_lim)
	{
		sem_post(philos->forks);
		sem_post(philos->forks);
		exit(0);
	}
	return (time);
}

void	print_death_msg(t_philos *philos, t_philo *philo, unsigned int time)
{
	sem_wait(philos->msg);
	if (philos->die_flag)
	{
		printf("%u %i %s\n", time, (philo->id + 1), MSG_DIE);
		sem_post(philos->finish);
	}
}

void	ft_usleep(unsigned int ms)
{
	struct timeval	now;
	struct timeval	start;

	gettimeofday(&now, NULL);
	gettimeofday(&start, NULL);
	while ((now.tv_sec - start.tv_sec) * 1000
		+ (now.tv_usec - start.tv_usec) / 1000 <= ms)
	{
		usleep(10);
		gettimeofday(&now, NULL);
	}
}
