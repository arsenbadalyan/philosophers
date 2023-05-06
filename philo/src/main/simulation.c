#include "philo.h"

void *start_simulation(void *arg)
{
    philo_t    *philo;

    philo = (philo_t *)arg;
    printf("Philisopher: %d\n", philo->id);
    return (NULL);
}