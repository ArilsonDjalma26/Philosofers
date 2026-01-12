/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:57:32 by aalbano           #+#    #+#             */
/*   Updated: 2026/01/12 09:37:23 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     is_positive_number(char *s)
{
	int		i;

	i = 0;
	if(!s || s[0] == '\0')
		return (0);
	while(s[i])
	{
		if(s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

long	ft_atol(char *s)
{
	int		i;
	long	res;
	
	i = 0;
	res = 0;
	while(s[i])
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res);
}

int	parse_args(int ac, char **av, t_rules *rules)
{
	int		i;
	
	i = 1;
	if(ac != 5 && ac != 6)
		return (1);
	while(i < ac)
	{
		if(is_positive_number(av[i]))
			return (1);
		i++;
	}
	rules->n_philo = ft_atol(av[1]);
	rules->time_died = ft_atol(av[2]);
	rules->time_eat = ft_atol(av[3]);
	rules->time_sleep = ft_atol(av[4]);

	if(ac == 6)
		rules->must_eat = ft_atol(av[i]);
	else
		rules->must_eat = -1;
	if((rules->n_philo == 0
	|| rules->time_died == 0
	|| rules->time_eat == 0
	|| rules->time_sleep == 0
	|| ac == 6) && (rules->must_eat == 0))
		return (1);
	return (0);
}
