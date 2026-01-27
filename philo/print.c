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

	pthread_mutex_lock(&philo->rules->print);
	if (!philo->rules->finished)
	{
		timestamp = get_time_in_ms() - philo->rules->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->rules->print);
}
