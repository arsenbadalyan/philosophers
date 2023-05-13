/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:08:41 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/13 15:08:42 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int print_msg(philos_t *philos, philo_t *philo, char *msg)
{
    unsigned int time;

    time = 0;
    pthread_mutex_lock(&philos->msg);
    time = get_cur_time();
    if(philos->limits->eat_lim != -1 && !philos->eat_lim && philos->limits->eat_lim == (int)philos->eat_lim)
            philos->die_flag = 1;
    if(!philos->die_flag)
        printf("%u %i %s\n", time, (philo->id + 1), msg);
    pthread_mutex_unlock(&philos->msg);
    return (time);
}

void print_death_msg(philos_t *philos, philo_t *philo, unsigned int time)
{
    pthread_mutex_lock(&philos->msg);
    if(philos->die_flag == 1)
        printf("%u %i %s\n", time, (philo->id + 1), MSG_DIE);
    pthread_mutex_unlock(&philos->msg);
}