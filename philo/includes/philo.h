#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/types.h>
#include "libft.h"

// Philo Defining
typedef struct {
    pthread_t *philos;
    pthread_mutex_t *forks;
} philo_t;

#endif