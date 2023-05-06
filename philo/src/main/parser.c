#include "philo.h"

int parse_controller(int argc, char **argv, philos_t *philos)
{
    size_t i;

    i = 1;
    philos->limits->ph_num = ft_atoi(argv[i++]);
    philos->limits->time_to_die = ft_atoi(argv[i++]);
    philos->limits->time_to_eat = ft_atoi(argv[i++]);
    philos->limits->time_to_sleep = ft_atoi(argv[i++]);
    if(argv[i])
    {
        philos->limits->eat_lim = ft_atoi(argv[i++]);
        if (philos->limits->eat_lim < 0)
            return (force_quit(E_NEGNUM, philos));
    }
    if (philos->limits->ph_num < 0 || philos->limits->time_to_die < 0
        || philos->limits->time_to_eat < 0 || philos->limits->time_to_sleep < 0)
        return (force_quit(E_NEGNUM, philos));
    return (EXIT_SUCCESS);
}