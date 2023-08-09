/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:13 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/27 16:38:58 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philos	*init_t_philos(void)
{
	t_philos	*philos;

	philos = (t_philos *)malloc(sizeof(t_philos));
	if (!philos)
		return (mem_issue(philos));
	philos->forks = NULL;
	philos->msg = NULL;
	philos->finish = NULL;
	philos->philo_list = NULL;
	philos->limits = (t_philos_lim *)malloc(sizeof(t_philos_lim));
	if (!philos->limits)
		return (mem_issue(philos));
	philos->die_flag = 0;
	return (philos);
}

t_philo	*init_philo_list(t_philos *philos, int ph_num)
{
	t_philo	*philo_list;
	int		i;

	i = 0;
	philo_list = (t_philo *)malloc(sizeof(t_philo) * ph_num);
	if (!philo_list)
		return (NULL);
	while (i < ph_num)
	{
		philo_list[i].id = i;
		philo_list[i].pid = 0;
		philo_list[i].last_meal = 0;
		philo_list[i].eat_lim = 0;
		philo_list[i].philos = philos;
		i++;
	}
	return (philo_list);
}
