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

int	check_death(philos_t *philos, philo_t *philo)
{
	unsigned int	time;

	time = get_cur_time();
	if ((time - philo->last_meal) > (unsigned int)philos->limits->time_to_die)
	{
		philos->die_flag = 1;
		print_death_msg(philos, philo, time);
	}
	return (philos->die_flag);
}

void	philo_sleep(philos_t *philos, philo_t *philo)
{
	print_msg(philos, philo, MSG_SLEEP, FLG_SLEEP);
	ms_sleep(philos->limits->time_to_sleep);
	print_msg(philos, philo, MSG_THINK, FLG_THINK);
}

void	philo_eat(philos_t *philos, philo_t *philo)
{
	sem_wait(philos->forks);
	sem_wait(philos->forks);
	print_msg(philos, philo, MSG_FORK, FLG_FORK);
	if (check_death(philos, philo))
		return ;
	philo->last_meal = print_msg(philos, philo, MSG_EAT, FLG_EAT);
	ms_sleep(philos->limits->time_to_eat);
	sem_post(philos->forks);
	sem_post(philos->forks);
	philo_sleep(philos, philo);
}

void	*start_simulation(philos_t *philos, philo_t *philo)
{
	while (!philos->die_flag)
		philo_eat(philos, philo);
	return (NULL);
}
