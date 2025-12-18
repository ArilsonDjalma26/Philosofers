/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:24:11 by aalbano           #+#    #+#             */
/*   Updated: 2025/12/11 17:24:12 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_rules
{
    int         n_philo;
    long    time_eat;
    long    time_sleep;
    long    time_died;
    int         must_eat;
    long    start_time;
    int     someone_died;
    pthread_mutex_t *forks;
    pthread_mutex_t print;
}   t_rules;

typedef struct s_philo
{
    int         id;
    int         meal_eaten;
    long    last_meal;
    pthread_t   thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *rigth_fork;
    t_rules *rules;

}   t_philo;

//Funcoes do parse
int     is_positive_number(char *s);
long    ft_atol(char *s);
int parse_args(int ac, char **av, t_rules *rules);

int     init_forks(t_rules *rules);
int     init_philos(t_rules *rules, t_philo **philos);
void     init_start_time(t_rules *rules, t_philo **philo);
#endif