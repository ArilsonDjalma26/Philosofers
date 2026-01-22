/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:38:21 by aalbano           #+#    #+#             */
/*   Updated: 2026/01/12 09:41:01 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (1);
}

void	cleanup(t_rules *rules, t_philo *philos)
{
	int		i;

	i = 0;
	if (rules->forks)
	{
		while (i < rules->n_philo)
		{
			pthread_mutex_destroy(&rules->forks[i]);
			i++;
		}
		free(rules->forks);
		rules->forks = NULL;
		rules->n_philo = 0;
	}
	pthread_mutex_destroy(&rules->print);
	pthread_mutex_destroy(&rules->finish_mutex);
	pthread_mutex_destroy(&rules->meal_lock);
	if (philos)
		free(philos);
}
