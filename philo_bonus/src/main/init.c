/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:13 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/13 15:09:14 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

philos_t	*init_philos_t(void)
{
	philos_t	*philos;

	philos = (philos_t *)malloc(sizeof(philos_t));
	if (!philos)
		return (mem_issue(philos));
	philos->forks = NULL;
	philos->msg = NULL;
	philos->finish = NULL;
	philos->philo_list = NULL;
	philos->limits = (philos_lim_t *)malloc(sizeof(philos_lim_t));
	if (!philos->limits)
		return (mem_issue(philos));
	philos->die_flag = 0;
	return (philos);
}

philo_t	*init_philo_list(philos_t *philos, int ph_num)
{
	philo_t	*philo_list;
	int		i;

	i = 0;
	(void)philos;
	philo_list = (philo_t *)malloc(sizeof(philo_t) * ph_num);
	if (!philo_list)
		return (NULL);
	while (i < ph_num)
	{
		philo_list[i].id = i;
		philo_list[i].pid = 0;
		philo_list[i].last_meal = 0;
		philo_list[i].eat_lim = 0;
		i++;
	}
	return (philo_list);
}
