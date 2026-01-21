/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:52:23 by aalbano           #+#    #+#             */
/*   Updated: 2026/01/12 09:56:22 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation_finished(t_rules *rules)
{
	int		finished;

	pthread_mutex_lock(&rules->finish_mutex);
	finished = rules->finished;
	pthread_mutex_unlock(&rules->finish_mutex);
	return (finished);
}
