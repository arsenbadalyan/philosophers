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
	int					last_meal;
	int					last_sleep;
}	philo_t;

typedef struct philos_s {
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	philos_lim_t	*limits;
	philo_t			*philo_list;
}   philos_t;

#endif