/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:07 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/20 13:13:00 by arsbadal         ###   ########.fr       */
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
unsigned int	print_msg(t_philos *philos, t_philo *philo,
					char *msg, int flag);
void			print_death_msg(t_philos *philos,
					t_philo *philo, unsigned int time);

// Error handling
int				force_quit(int errno, t_philos *philos);
void			*mem_issue(t_philos *philos);

// Time functions
unsigned int	get_cur_time(void);
void			ms_sleep(unsigned int time);
void			ft_usleep(unsigned int ms);

// Free memory
void			*free_single(void **addr);
void			*free_double(void ***addr);
void			*free_all_mem(t_philos *philos);

#endif