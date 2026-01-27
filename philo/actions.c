/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:11:53 by aalbano           #+#    #+#             */
/*   Updated: 2026/01/21 17:13:30 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
}

static void	drop_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	eat(t_philo *philo)
{
	if (simulation_finished(philo->rules))
		return ;
	take_forks(philo);
	if (simulation_finished(philo->rules))
	{
		drop_forks(philo);
		return ;
	}
	pthread_mutex_lock(&philo->rules->meal_lock);
	philo->last_meal = get_time_in_ms();
	philo->meal_eaten++;
	pthread_mutex_unlock(&philo->rules->meal_lock);
	print_status(philo, "is eating");
	ft_usleep(philo->rules->time_eat, philo->rules);
	drop_forks(philo);
}

void	think(t_philo *philo)
{
	long	time_to_think;

	if (simulation_finished(philo->rules))
		return ;
	print_status(philo, "is thinking");
	time_to_think = philo->rules->time_died
		- philo->rules->time_sleep - philo->rules->time_eat;
	if (time_to_think < 0)
		time_to_think = 0;
	ft_usleep(time_to_think, philo->rules);
}

void	sleep_philo(t_philo *philo)
{
	if (simulation_finished(philo->rules))
		return ;
	print_status (philo, "is sleeping");
	ft_usleep(philo->rules->time_sleep, philo->rules);
}
