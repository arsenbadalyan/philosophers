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

// Custom error codes
enum {
	E_NOMEM,
	E_NEGNUM,
	E_ARGSUM,
	E_MUTEX,
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
	int ph_num;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int eat_lim;
}   philos_lim_t;

typedef struct {
	int					id;
	struct philos_s		*philos;
	pthread_t			*philo;
	pthread_mutex_t 	*left_fork;
	pthread_mutex_t 	*right_fork;
	unsigned int		last_meal;
}	philo_t;

typedef struct philos_s {
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	pthread_mutex_t	death;
	pthread_mutex_t	death_flag;
	philos_lim_t	*limits;
	philo_t			*philo_list;
	unsigned int	eat_lim;
	int				die_flag;
}   philos_t;

// Philosophers states
# define MSG_FORK  "has taken a fork"
# define MSG_EAT   "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_DIE   "died"

#endif