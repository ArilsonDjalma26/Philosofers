/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:01:04 by aalbano           #+#    #+#             */
/*   Updated: 2026/01/12 10:01:52 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_rules *rules, t_philo *philos)
{
	int		i;
	
	i = 0;
	while (i < rules->n_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]) != 0)
		{
			int j = 0;
			while (j < i)
				pthread_join(philos[j++].thread, NULL);
			return (1);
		}
		i++;
	}
	return (0);
}
