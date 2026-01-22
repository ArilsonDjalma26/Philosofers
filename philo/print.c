/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:46:02 by aalbano           #+#    #+#             */
/*   Updated: 2026/01/12 09:47:38 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *msg)
{
	long	timestamp;
	int		finished;

	pthread_mutex_lock(&philo->rules->finish_mutex);
	finished = philo->rules->finished;
	pthread_mutex_unlock(&philo->rules->finish_mutex);
	if (!finished)
	{
		pthread_mutex_lock(&philo->rules->print);
		timestamp = get_time_in_ms() - philo->rules->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, msg);
		pthread_mutex_unlock(&philo->rules->print);
	}
}
