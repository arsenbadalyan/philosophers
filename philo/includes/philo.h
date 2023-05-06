#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/types.h>
#include "program_definitions.h"
#include "utils.h"

// Controller
int parse_controller(int argc, char **argv, philos_t *philos);
int philos_controller(philos_t *philos);

// Simulation
void *start_simulation(void *arg);

// Initialize
philos_t *init_philos_t();
void *init_pthread_mutex(philos_t *philos);
philo_t *init_philo_list(philos_t *philos, int ph_num);

#endif