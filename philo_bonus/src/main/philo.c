/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:08:44 by arsbadal          #+#    #+#             */
/*   Updated: 2023/05/13 15:08:44 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	philos_t	*philos;

	if (argc < 5 || argc > 6)
		return (force_quit(E_ARGSUM, NULL));
	philos = init_philos_t();
	if (!philos)
		return (EXIT_FAILURE);
	if (parse_controller(argv, philos))
		return (EXIT_FAILURE);
	if (philos_controller(philos))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
