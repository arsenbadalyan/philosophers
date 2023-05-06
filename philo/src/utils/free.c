#include "philo.h"

void *free_single(void **addr)
{
    if (*addr)
    {
        free(*addr);
        *addr = 0;
    }
    return (0);
}

void *free_double(void ***addr)
{
    int i;

    i = 0;
    if (*addr)
    {
        while ((*addr)[i])
        {
            free_single(&(*addr)[i]);
            i++;
        }
        free_single((void *)&(*addr));
    }
    return (0);
}

void *free_all_mem(philos_t *philos)
{
    return (NULL);
}