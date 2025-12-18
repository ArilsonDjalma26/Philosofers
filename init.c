/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:09:15 by aalbano           #+#    #+#             */
/*   Updated: 2025/12/18 11:09:18 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     init_forks(t_rules *rules)
{
    int         i;

    i = 0;
    rules->forks = malloc(sizeof(pthread_mutex_t) * rules->n_philo);
        if(!rules->forks)
            return (1);
    while(i < rules->n_philo)
    {
        pthread_mutex_init(&rules->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&rules->print, NULL);
    return (0);
}
int     init_philos(t_rules *rules, t_philo **philos)
{
    int         i;

    i = 0;
    *philos = malloc(sizeof(t_philo) * rules->n_philo);
    if(!*philos)
        return (1);
    while(i < rules->n_philo)
    {
        (*philos)[i].id = i + 1;
        (*philos)[i].meal_eaten = 0;
        (*philos)[i].last_meal = 0;
        (*philos)[i].left_fork = &rules->forks[i];
        (*philos)[i].rigth_fork = &rules->forks[(i + 1) % rules->n_philo];
        (*philos)[i].rules = rules;
        i++;
    }
    return (0);
}