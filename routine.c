/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:49:36 by aalbano           #+#    #+#             */
/*   Updated: 2026/01/12 09:52:05 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->rules->time_eat/2, philo->rules);
	while (!simulation_finished(philo->rules))
	{
		eat(philo);
		if(simulation_finished(philo->rules))
			break;
		sleep_philo(philo);
		if(simulation_finished(philo->rules))
			break;        
		think(philo);
	}
	return (NULL);
}
