/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:08:46 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/20 21:02:56 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philos *philos, t_philo *philo)
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

void	philo_sleep(t_philos *philos, t_philo *philo)
{
	print_msg(philos, philo, MSG_SLEEP, FLG_SLEEP);
	ms_sleep(philos->limits->time_to_sleep);
	print_msg(philos, philo, MSG_THINK, FLG_THINK);
}

void	philo_eat(t_philos *philos, t_philo *philo)
{
	sem_wait(philos->forks);
	if (check_death(philos, philo))
		return ;
	sem_wait(philos->forks);
	print_msg(philos, philo, MSG_FORK, FLG_FORK);
	if (check_death(philos, philo))
		return ;
	philo->last_meal = print_msg(philos, philo, MSG_EAT, FLG_EAT);
	ms_sleep(philos->limits->time_to_eat);
	if (check_death(philos, philo))
		return ;
	sem_post(philos->forks);
	if (check_death(philos, philo))
		return ;
	sem_post(philos->forks);
	philo_sleep(philos, philo);
	if (check_death(philos, philo))
		return ;
}

void	*start_simulation(t_philos *philos, t_philo *philo)
{
	if (philos->limits->ph_num == 1)
	{
		print_msg(philos, philo, MSG_FORK, FLG_FORK);
		ms_sleep(philos->limits->time_to_die);
		philos->die_flag = 1;
		print_death_msg(philos, philo, get_cur_time());
		return (NULL);
	}
	while (!philos->die_flag)
		philo_eat(philos, philo);
	return (NULL);
}
