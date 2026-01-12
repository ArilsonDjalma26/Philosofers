/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:26:57 by aalbano           #+#    #+#             */
/*   Updated: 2026/01/12 09:31:04 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death(t_philo *philo)
{
	long	now;
	
	now = get_time_in_ms();
	if (now - philo->last_meal > philo->rules->time_died)
	{
		print_status(philo, "died");
		pthread_mutex_lock(&philo->rules->finish_mutex);
		philo->rules->finished = 1;
		pthread_mutex_unlock(&philo->rules->finish_mutex);
		return(1);
	}
	return(0);
}

static int	check_meals(t_philo *philos)
{
	int		i;
	int		finished;

	i = 0;
	finished = 1;
	if (philos[0].rules->must_eat == -1)
		return(0);
	while(i < philos[0].rules->n_philo)
	{
		if (philos[i].meal_eaten < philos[0].rules->must_eat)
		{
			finished = 0;
			break;
		}
		i++;
	}
	if(finished)
	{
		pthread_mutex_lock(&philos[0].rules->finish_mutex);
		philos[0].rules->finished = 1;
		pthread_mutex_unlock(&philos[0].rules->finish_mutex);
		return(1);
	}
	return(0);
}

void	*monitor(void *arg)
{
	t_philo *philos;
	int		i;

	philos = (t_philo *)arg;
	while(!simulation_finished(philos[0].rules))
	{
		i = 0;
		while(i < philos[0].rules->n_philo)
		{
			if (check_death(&philos[i]))
				return(NULL);
			i++;
		}
		if (check_meals(philos))
			return(NULL);
		usleep(1000);
	}
	return(NULL);
}
