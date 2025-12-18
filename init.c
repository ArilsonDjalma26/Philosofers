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