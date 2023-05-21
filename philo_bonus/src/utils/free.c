/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:26 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/20 20:59:28 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*free_single(void **addr)
{
	if (*addr)
	{
		free(*addr);
		*addr = 0;
	}
	return (0);
}

void	*free_double(void ***addr)
{
	int	i;

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

void	*free_all_mem(t_philos *philos)
{
	sem_close(philos->forks);
	sem_close(philos->msg);
	sem_close(philos->finish);
	free_single((void *)&(philos->limits));
	free_single((void *)&(philos->philo_list));
	free_single((void *)&(philos));
	return (NULL);
}
