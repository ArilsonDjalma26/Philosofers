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

#include "philo.h"

void    precise_sleep(long time)
{
    long start;

    start = get_time_in_ms();
    while (get_time_in_ms() - start < time)
        usleep(100);
}
long    get_time_in_ms(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
