#include "philo.h"

int create_threads(t_rules *rules, t_philo *philos)
{
    int         i;

    i = 0;
    while (i < rules->n_philo)
    {
        if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]) != 0)
            return (1);
        i++;
    }
    return (0);
}