/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:07 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/13 15:09:08 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

// 42 functions
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

// Helpers
unsigned int    print_msg(philos_t *philos, philo_t *philo, char *msg);
void            print_death_msg(philos_t *philos, philo_t *philo, unsigned int time);

// Error handling
int		force_quit(int errno, philos_t *philos);
void	*mem_issue(philos_t *philos);

// Time functions
unsigned int get_cur_time();
void ms_sleep(unsigned int time);

// Free memory
void *free_single(void **addr);
void *free_double(void ***addr);
void *free_all_mem(philos_t *philos);

#endif