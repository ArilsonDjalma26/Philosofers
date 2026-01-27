/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:59:06 by aalbano           #+#    #+#             */
/*   Updated: 2026/01/12 10:00:05 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_rules *rules, t_philo *philos)
{
	int		i;

	if (rules->n_philo == 1)
	{
		pthread_mutex_lock(philos->left_fork);
		print_status(&philos[0], "has taken a fork");
		ft_usleep(rules->time_died, rules);
		pthread_mutex_lock(&rules->finish_mutex);
		rules->finished = 1;
		pthread_mutex_unlock(&rules->finish_mutex);
		printf("%ld %d died\n",
			get_time_in_ms() - rules->start_time, philos[0].id);
		pthread_mutex_unlock(philos->left_fork);
		return ;
	}
	if (create_threads(rules, philos))
		return ;
	if (pthread_create(&rules->monitor, NULL, monitor, philos) != 0)
	{
		i = 0;
		while (i < rules->n_philo)
			pthread_join(philos[i++].thread, NULL);
		return ;
	}
	i = 0;
	while (i < rules->n_philo)
		pthread_join(philos[i++].thread, NULL);
	pthread_join(rules->monitor, NULL);
}
