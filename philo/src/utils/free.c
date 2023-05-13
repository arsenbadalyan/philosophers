/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:26 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/13 15:09:27 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *free_single(void **addr)
{
	if (*addr)
	{
		free(*addr);
		*addr = 0;
	}
	return (0);
}

void *free_double(void ***addr)
{
	int i;

	i = 0;
	if (*addr)
	{
		while ((*addr)[i])
		{
			free_single(&(*addr)[i]);
			i++;
		}
		free_single((void *)&(*addr));
	}
	return (0);
}

void *free_all_mem(philos_t *philos)
{
	int	i;

	i = -1;
	while(++i < philos->limits->ph_num)
		pthread_mutex_destroy(&philos->forks[i]);
	pthread_mutex_destroy(&philos->death_flag);
	pthread_mutex_destroy(&philos->death);
	pthread_mutex_destroy(&philos->msg);
	free_single((void *)&(philos->limits));
	free_single((void *)&(philos->philo_list));
	free_single((void *)&(philos->philos));
	free_single((void *)&(philos->forks));
	free_single((void *)&(philos));
	return (NULL);
}