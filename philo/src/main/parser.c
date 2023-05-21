/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:15 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/20 22:14:28 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include "philo.h"

char	*check_zeros(char *number)
{
	if (*number == '0' && *(number + 1))
	{
		while (*number == '0' && *(number + 1))
			number++;
		return (number);
	}
	return (number);
}

int	check(char *str)
{
	long long	atoi_check;
	size_t		len;
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = str;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		str++;
	str = check_zeros(str);
	len = length(str);
	if (!len || len >= 12)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	atoi_check = ft_atoi(tmp);
	if (atoi_check <= 0 || atoi_check > INT_MAX)
		return (-1);
	return (atoi_check);
}

int	parse_controller(char **argv, t_philos *philos)
{
	size_t	i;

	i = 1;
	philos->limits->ph_num = check(argv[i++]);
	philos->limits->ph_num_die = philos->limits->ph_num;
	philos->limits->time_to_die = check(argv[i++]);
	philos->limits->time_to_eat = check(argv[i++]);
	philos->limits->time_to_sleep = check(argv[i++]);
	philos->limits->eat_lim = -1;
	if (argv[i])
	{
		philos->limits->eat_lim = check(argv[i++]);
		if (philos->limits->eat_lim < 0)
			return (force_quit(E_NEGNUM, philos));
	}
	if (philos->limits->ph_num < 0 || philos->limits->time_to_die < 0
		|| philos->limits->time_to_eat < 0 || philos->limits->time_to_sleep < 0)
		return (force_quit(E_NEGNUM, philos));
	return (EXIT_SUCCESS);
}
