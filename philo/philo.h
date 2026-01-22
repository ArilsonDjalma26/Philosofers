/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:24:11 by aalbano           #+#    #+#             */
/*   Updated: 2026/01/12 09:45:06 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_rules
{
	int				n_philo;
	long			time_eat;
	long			time_sleep;
	long			time_died;
	int				must_eat;
	int				someone_died;
	long			start_time;
	int				finished;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	meal_lock;
	pthread_t		monitor;
}	t_rules;

typedef struct s_philo
{
	int				id;
	int				meal_eaten;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_rules			*rules;
}	t_philo;

//Parsing functions
int		is_positive_number(char *s);
long	ft_atol(char *s);
int		parse_args(int ac, char **av, t_rules *rules);

int		error(char *msg);
void	cleanup(t_rules *rules, t_philo *philos);

int		init_forks(t_rules *rules);
int		init_philos(t_rules *rules, t_philo **philos);
void	init_start_time(t_rules *rules, t_philo *philos);
int		create_threads(t_rules *rules, t_philo *philos);
void	start_simulation(t_rules *rules, t_philo *philos);
int		simulation_finished(t_rules *rules);
void	print_status(t_philo *philo, char *msg);
void	print_death(t_philo *philo, char *msg);
void	*routine(void *arg);
void	*monitor(void *arg);
void	ft_usleep(long time, t_rules *rules);
long	get_time_in_ms(void);
void	eat(t_philo *philo);
void	think(t_philo *philo);
void	sleep_philo(t_philo *philo);
size_t	ft_strlen(const char *s);

#endif
