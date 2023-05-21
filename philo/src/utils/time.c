/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:33 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/21 03:11:56 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_cur_time(void)
{
	struct timeval		tv;
	static int			count;
	static unsigned int	start;

	if (count == 0)
	{
		gettimeofday(&tv, NULL);
		start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		count++;
	}
	else
		gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - start);
}

void	ft_usleep(unsigned int ms)
{
	struct timeval	now;
	struct timeval	start;

	gettimeofday(&now, NULL);
	gettimeofday(&start, NULL);
	while ((now.tv_sec - start.tv_sec) * 1000
		+ (now.tv_usec - start.tv_usec) / 1000 <= ms)
	{
		usleep(10);
		gettimeofday(&now, NULL);
	}
}

void	ms_sleep(unsigned int time)
{
	ft_usleep(time);
}
