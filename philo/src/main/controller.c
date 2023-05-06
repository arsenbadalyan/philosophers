#include "philo.h"

int philos_controller(philos_t *philos)
{
	int i;

	if(!init_pthread_mutex(philos))
		return (EXIT_FAILURE);
	i = -1;
	while(++i < philos->limits->ph_num)
		if(pthread_mutex_init(&philos->forks[i], NULL))
			return (force_quit(E_MUTEX, philos));
	i = -1;
	while (++i < philos->limits->ph_num)
		if (pthread_create(&philos->philos[i], NULL, &start_simulation, (void *)&philos->philo_list[i]))
			return (force_quit(E_THREAD, philos));
	i = -1;
	while (++i < philos->limits->ph_num)
		if (pthread_join(philos->philos[i], NULL))
			return (force_quit(E_JOINTHREAD, philos));
	return (EXIT_SUCCESS);
}
