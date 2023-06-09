/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:20 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/20 13:13:00 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*mem_issue(t_philos *philos)
{
	ft_putstr_fd("Sorry you have memory issue, \
		please fix it and come back :)\n", 2);
	free_all_mem(philos);
	return (NULL);
}

int	force_quit(int errno, t_philos *philos)
{
	if (errno == E_NEGNUM)
		ft_putstr_fd("Please write correct arguments, \
			they cannot be negative nor invalid\n", 2);
	else if (errno == E_ARGSUM)
		ft_putstr_fd("! Please enter 4 or 5 options \
			for program !\n", 2);
	else if (errno == E_MUTEX)
		ft_putstr_fd("We have mutex init issue please \
			restart program!\n", 2);
	else if (errno == E_THREAD)
		ft_putstr_fd("We have thread create issue please \
			restart program!\n", 2);
	else if (errno == E_JOINTHREAD)
		ft_putstr_fd("One of threads terminated unexpectedly \
			please restart program!\n", 2);
	if (philos)
		free_all_mem(philos);
	return (EXIT_FAILURE);
}
