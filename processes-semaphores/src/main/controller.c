/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:10 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/27 20:41:52 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct threadArgs_s {
	int		ph_limit;
	int		*pid_list;
	sem_t	*f_sem;
}	t_threadArgs;

t_threadArgs	*copy_thread_args(t_philos *philos)
{
	size_t			i;
	t_threadArgs	*thread_args;

	i = 0;
	thread_args = (t_threadArgs *)malloc(sizeof(t_threadArgs));
	if (!thread_args)
		mem_issue(philos);
	thread_args->ph_limit = philos->limits->ph_num;
	thread_args->pid_list = (int *)malloc(thread_args->ph_limit * sizeof(int));
	if (!thread_args->pid_list)
		mem_issue(philos);
	while (i < (size_t)thread_args->ph_limit)
	{
		thread_args->pid_list[i] = philos->philo_list[i].pid;
		++i;
	}
	thread_args->f_sem = philos->finish;
	return (thread_args);
}

void	*wait_eat(void *args)
{
	int				i;
	t_threadArgs	*philos;

	i = 0;
	philos = (t_threadArgs *)args;
	while (i < philos->ph_limit)
	{
		waitpid(philos->pid_list[i], NULL, 0);
		i++;
	}
	sem_post(philos->f_sem);
	free(philos->pid_list);
	free(philos);
	return (NULL);
}

void	wait_any_action(t_philos *philos)
{
	pthread_t		*thread;
	int				i;
	void			*args;

	args = (void *)copy_thread_args(philos);
	thread = (pthread_t *)malloc(sizeof(pthread_t));
	sem_wait(philos->finish);
	if (pthread_create(thread, NULL, &wait_eat, args))
		force_quit(E_THREAD, philos);
	sem_wait(philos->finish);
	if (pthread_detach(*thread))
		force_quit(E_THREAD, philos);
	free_single((void *)&thread);
	i = 0;
	while (i < (int)philos->limits->ph_num)
	{
		kill(philos->philo_list[i].pid, SIGTERM);
		i++;
	}
}

void	make_processes(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->limits->ph_num)
	{
		philos->philo_list[i].pid = fork();
		if (philos->philo_list[i].pid < 0)
			force_quit(E_PROCESS, philos);
		if (philos->philo_list[i].pid == 0)
		{
			if (i % 2)
				ms_sleep(philos->limits->time_to_eat);
			start_simulation(philos, &philos->philo_list[i]);
			exit(0);
		}
		i++;
	}
	wait_any_action(philos);
}

int	philos_controller(t_philos *philos)
{
	philos->philo_list = init_philo_list(philos, philos->limits->ph_num);
	if (!philos->philo_list)
		mem_issue(philos);
	sem_unlink(SEMAPHORE_NAME);
	sem_unlink(MSG_SEMAPHORE);
	sem_unlink(FINISH_SEMAPHORE);
	sem_unlink(LAST_MEAL_SEMAPHORE);
	philos->forks = sem_open(SEMAPHORE_NAME, O_CREAT, 0755,
			philos->limits->ph_num);
	philos->msg = sem_open(MSG_SEMAPHORE, O_CREAT, 0755, 1);
	philos->finish = sem_open(FINISH_SEMAPHORE, O_CREAT, 0755, 1);
	philos->end = sem_open(LAST_MEAL_SEMAPHORE, O_CREAT, 0755, 1);
	get_cur_time();
	make_processes(philos);
	free_all_mem(philos);
	return (EXIT_SUCCESS);
}
