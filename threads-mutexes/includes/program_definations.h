/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_definations.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:04 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/21 02:51:29 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_DEFINATIONS_H
# define PROGRAM_DEFINATIONS_H

// Philosophers states
# define MSG_FORK  "has taken a fork"
# define MSG_EAT   "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_DIE   "died"

// Custom error codes
enum e_errors {
	E_NOMEM,
	E_NEGNUM,
	E_ARGSUM,
	E_MUTEX,
	E_THREAD,
	E_JOINTHREAD
};

// Philo actions
enum e_flags {
	FLG_EAT,
	FLG_FORK,
	FLG_SLEEP,
	FLG_DIE,
	FLG_THINK	
};

// Philo Structures Defining
typedef struct philos_lim_s {
	int	ph_num;
	int	ph_num_die;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_lim;
}	t_philos_lim;

typedef struct philo_s {
	int					id;
	int					already_eaten;
	struct philos_s		*philos;
	pthread_t			*philo;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	unsigned int		last_meal;
}	t_philo;

typedef struct philos_s {
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	pthread_mutex_t	death;
	pthread_mutex_t	death_flag;
	pthread_mutex_t	death_flag_change;
	pthread_mutex_t	last_meal;
	pthread_mutex_t	finish;
	t_philos_lim	*limits;
	t_philo			*philo_list;
	int				is_dead;
	int				already_eaten;
}	t_philos;

#endif