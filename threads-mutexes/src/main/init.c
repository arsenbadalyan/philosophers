/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:13 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/21 02:51:42 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philos	*init_t_philos(void)
{
	t_philos	*philos;

	philos = (t_philos *)malloc(sizeof(t_philos));
	if (!philos)
		return (mem_issue(philos));
	philos->philos = NULL;
	philos->forks = NULL;
	philos->philo_list = NULL;
	philos->already_eaten = 0;
	philos->limits = (t_philos_lim *)malloc(sizeof(t_philos_lim));
	if (!philos->limits)
		return (mem_issue(philos));
	philos->is_dead = 0;
	return (philos);
}

t_philo	*init_philo_list(t_philos *philos, int ph_num)
{
	int		i;
	t_philo	*philo_list;

	i = -1;
	philo_list = (t_philo *)malloc(sizeof(t_philo) * ph_num);
	if (!philo_list)
		return (NULL);
	while (++i < ph_num)
	{
		philo_list[i].id = i;
		philo_list[i].already_eaten = 0;
		philo_list[i].philos = philos;
		philo_list[i].philo = &philos->philos[i];
		philo_list[i].left_fork = &philos->forks[(i + 1) % ph_num];
		philo_list[i].right_fork = &philos->forks[i];
		philo_list[i].last_meal = 0;
	}
	return (philo_list);
}

void	*init_pthread_mutex(t_philos *philos)
{
	int	ph_num;

	ph_num = philos->limits->ph_num;
	philos->philos = (pthread_t *)malloc(sizeof(pthread_t) * ph_num);
	if (!philos->philos)
		return (mem_issue(philos));
	philos->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * ph_num);
	if (!philos->forks)
		return (mem_issue(philos));
	philos->philo_list = init_philo_list(philos, ph_num);
	if (!philos->philo_list)
		return (mem_issue(philos));
	return (philos);
}

int	init_all_mutexes(t_philos *philos)
{
	int	i;

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
	if (pthread_mutex_init(&philos->finish, NULL))
		return (force_quit(E_MUTEX, philos));
	return (EXIT_SUCCESS);
}
