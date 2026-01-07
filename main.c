/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:25:05 by aalbano           #+#    #+#             */
/*   Updated: 2025/12/17 19:25:17 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main(int ac, char **av)
{
    t_rules rules;
    t_philo *philos;

    if (parse_args(ac, av, &rules))
        return (error("Invalid arguments"));
    if (init_forks(&rules))
        return (error("Fork init failed"));
    if (init_philos(&rules, &philos))
        return (error("Philo init failed"));
    init_start_time(&rules, philos);
    start_simulation(&rules, philos);
    cleanup(&rules, philos);
    return 0;
}
