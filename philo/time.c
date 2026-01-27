/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:03:07 by aalbano           #+#    #+#             */
/*   Updated: 2026/01/12 10:04:05 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long time, t_rules *rules)
{
	long	start;
	long	sleep_unit;

	start = get_time_in_ms();
	sleep_unit = 100;
	if (time < 100)
		sleep_unit = 10;
	while (!simulation_finished(rules))
	{
		if (get_time_in_ms() - start >= time)
			break ;
		usleep(sleep_unit);
	}
}

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
