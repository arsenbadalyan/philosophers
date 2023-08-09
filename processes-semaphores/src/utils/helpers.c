/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:08:41 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/27 23:30:14 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_msg(t_philos *philos, t_philo *philo, char *msg, int flag)
{
	unsigned int	time;

	sem_wait(philos->end);
	time = get_cur_time();
	if (flag == FLG_EAT)
	{
		philo->last_meal = time;
		philo->eat_lim++;
	}
	if (!philos->die_flag)
	{
		sem_wait(philos->msg);
		printf("%u %i %s\n", time, (philo->id + 1), msg);
		sem_post(philos->msg);
	}
	if (philos->limits->eat_lim != -1
		&& philos->limits->eat_lim == philo->eat_lim)
	{
		sem_post(philos->forks);
		sem_post(philos->forks);
		sem_post(philos->end);
		return (EXIT_FAILURE);
	}
	sem_post(philos->end);
	return (EXIT_SUCCESS);
}

void	print_death_msg(t_philos *philos, t_philo *philo, unsigned int time)
{
	sem_wait(philos->msg);
	philos->die_flag = 1;
	printf("%u %i %s\n", time, (philo->id + 1), MSG_DIE);
	sem_post(philos->finish);
}
