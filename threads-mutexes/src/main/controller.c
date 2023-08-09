/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:10 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/27 14:26:16 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philos *philos, t_philo *philo)
{
	int				status;
	unsigned int	time;

	status = EXIT_SUCCESS;
	if (is_eaten_or_dead(philos))
		status = EXIT_FAILURE;
	pthread_mutex_lock(&philos->last_meal);
	time = get_cur_time();
	if (!status && (time - philo->last_meal)
		> (unsigned int)philos->limits->time_to_die)
	{
		print_death_msg(philos, philo, time);
		status = EXIT_FAILURE;
	}
	pthread_mutex_unlock(&philos->last_meal);
	return (status);
}

int	check_finish(t_philos *philos, int *philo_index)
{
	int	i;

	i = -1;
	while (++i < philos->limits->ph_num)
	{
		pthread_mutex_lock(&philos->finish);
		if (philos->philo_list[i].already_eaten == -1
			&& ++(*philo_index))
		{
			pthread_mutex_unlock(&philos->finish);
			continue ;
		}
		pthread_mutex_unlock(&philos->finish);
		if (check_death(philos, &philos->philo_list[i]))
			return (1);
	}
	return (0);
}

int	global_check_death(t_philos *philos, int philo_index)
{
	int	i;

	i = -1;
	get_cur_time();
	while (++i < philos->limits->ph_num)
		if (pthread_create(&philos->philos[i], NULL,
				&start_simulation, (void *)&philos->philo_list[i]))
			return (1);
	if (philos->limits->ph_num == 1)
		return (0);
	while (1 && philo_index < philos->limits->ph_num)
	{
		if (check_finish(philos, &philo_index))
			return (0);
	}
	return (0);
}

int	philos_controller(t_philos *philos)
{
	int	i;

	i = -1;
	if (!init_pthread_mutex(philos))
		return (EXIT_FAILURE);
	if (init_all_mutexes(philos))
		return (EXIT_FAILURE);
	if (global_check_death(philos, 0))
		return (force_quit(E_THREAD, philos));
	while (++i < philos->limits->ph_num)
		if (pthread_join(philos->philos[i], NULL))
			return (force_quit(E_JOINTHREAD, philos));
	free_all_mem(philos);
	return (EXIT_SUCCESS);
}
