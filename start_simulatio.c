#include "philo.h"

void    start_simulation(t_rules *rules, t_philo *philos)
{
    int i;

    i = 0;
    if(create_threads(rules, philos))
        return ;
    if(pthread_create(&rules->monitor, NULL, monitor, philos) != 0)
        return ;
    while(i < rules->n_philo)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
    pthread_join(rules->monitor, NULL);
}