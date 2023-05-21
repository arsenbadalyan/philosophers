/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:10 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/21 03:08:34 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	global_check_death(t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < philos->limits->ph_num)
		if (pthread_create(&philos->philos[i], NULL,
				&start_simulation, (void *)&philos->philo_list[i]))
			return (1);
	if (philos->limits->ph_num == 1)
		return (0);
	while (1)
	{
		i = 0;
		while (i < philos->limits->ph_num)
		{
			if (check_death(philos, &philos->philo_list[i]))
				return (0);
			i++;
		}
	}
	return (0);
}

int	philos_controller(t_philos *philos)
{
	int	i;

	if (!init_pthread_mutex(philos))
		return (EXIT_FAILURE);
	i = -1;
	while (++i < philos->limits->ph_num)
		if (pthread_mutex_init(&philos->forks[i], NULL))
			return (force_quit(E_MUTEX, philos));
	if (pthread_mutex_init(&philos->msg, NULL))
		return (force_quit(E_MUTEX, philos));
	if (pthread_mutex_init(&philos->death, NULL))
		return (force_quit(E_MUTEX, philos));
	if (pthread_mutex_init(&philos->death_flag, NULL))
		return (force_quit(E_MUTEX, philos));
	if (pthread_mutex_init(&philos->last_meal, NULL))
		return (force_quit(E_MUTEX, philos));
	if (global_check_death(philos))
		return (force_quit(E_THREAD, philos));
	i = -1;
	while (++i < philos->limits->ph_num)
		if (pthread_join(philos->philos[i], NULL))
			return (force_quit(E_JOINTHREAD, philos));
	free_all_mem(philos);
	return (EXIT_SUCCESS);
}
