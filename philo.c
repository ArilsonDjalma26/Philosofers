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

static int     is_number(char **arg)
{
    int         i;
    int         j;

    i = 0;
    while(arg[i])
    {
        j = 0;
        while(arg[i][j])
        {
            if(arg[i][j] < 0 || arg[i][j] > 9)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
int main(int ac, char **av)
{
    if(ac == 5)
    {

    }
    return 0;
}
