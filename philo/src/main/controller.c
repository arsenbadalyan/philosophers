/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:10 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/13 16:40:05 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philos_controller(philos_t *philos)
{
	int i;

	if(!init_pthread_mutex(philos))
		return (EXIT_FAILURE);
	i = -1;
	while(++i < philos->limits->ph_num)
		if(pthread_mutex_init(&philos->forks[i], NULL))
			return (force_quit(E_MUTEX, philos));
	if (pthread_mutex_init(&philos->msg, NULL))
		return (force_quit(E_MUTEX, philos));
	if (pthread_mutex_init(&philos->death, NULL))
		return (force_quit(E_MUTEX, philos));
	if (pthread_mutex_init(&philos->death_flag, NULL))
		return (force_quit(E_MUTEX, philos));
	i = -1;
	while (++i < philos->limits->ph_num)
		if (pthread_create(&philos->philos[i], NULL, &start_simulation, (void *)&philos->philo_list[i]))
			return (force_quit(E_THREAD, philos));
	i = -1;
	while (++i < philos->limits->ph_num)
		if (pthread_join(philos->philos[i], NULL))
			return (force_quit(E_JOINTHREAD, philos));
	free_all_mem(philos);
	return (EXIT_SUCCESS);
}
