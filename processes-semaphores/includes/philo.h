/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:02 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/27 20:58:57 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/types.h>
# include <limits.h>
# include "program_definations.h"
# include "utils.h"

// Main Controller
int			philos_controller(t_philos *philos);

// Parser
int			parse_controller(char **argv, t_philos *philos);
char		*check_zeros(char *number);
int			check(char *str);

// Simulation
void		*start_simulation(t_philos *philos, t_philo *philo);
int			die_add(t_philos *philos);

// Initialize
t_philos	*init_t_philos(void);
void		*init_pthread_mutex(t_philos *philos);
t_philo		*init_philo_list(t_philos *philos, int ph_num);

#endif