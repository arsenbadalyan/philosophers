/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_definitions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:04 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/13 16:07:27 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_DEFINATIONS_H
#define PROGRAM_DEFINATIONS_H

# define SEMAPHORE_NAME "/philo_semaphore"
# define MSG_SEMAPHORE "/philo_semaphore_msg"
# define FINISH_SEMAPHORE "/philo_semaphore_finish"

// Custom error codes
enum {
	E_NOMEM,
	E_NEGNUM,
	E_ARGSUM,
	E_PROCESS,
	E_THREAD,
	E_JOINTHREAD
};

// Philo actions
enum {
	FLG_EAT,
	FLG_FORK,
	FLG_SLEEP,
	FLG_DIE,
	FLG_THINK	
};

// Philo Structures Defining
typedef struct {
	int	ph_num;
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int eat_lim;
}   philos_lim_t;

typedef struct {
	int				id;
	int				eat_lim;
	pid_t			pid;
	unsigned int	last_meal;
}	philo_t;

typedef struct philos_s {
	sem_t			*forks;
	sem_t			*msg;
	sem_t			*finish;
	philos_lim_t	*limits;
	philo_t			*philo_list;
	int				die_flag;
}   philos_t;

// Philosophers states
# define MSG_FORK  "has taken a fork"
# define MSG_EAT   "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_DIE   "died"

#endif