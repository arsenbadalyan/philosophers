/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:07 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/13 15:28:58 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// 42 functions
size_t			length(char *str);
long long		ft_atoi(char *number);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);

// Helpers
unsigned int	print_msg(philos_t *philos, philo_t *philo,
					char *msg, int flag);
void			print_death_msg(philos_t *philos,
					philo_t *philo, unsigned int time);

// Error handling
int				force_quit(int errno, philos_t *philos);
void			*mem_issue(philos_t *philos);

// Time functions
unsigned int	get_cur_time(void);
void			ms_sleep(unsigned int time);
void			ft_usleep(unsigned int ms);

// Free memory
void			*free_single(void **addr);
void			*free_double(void ***addr);
void			*free_all_mem(philos_t *philos);

#endif