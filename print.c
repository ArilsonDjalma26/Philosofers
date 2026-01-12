#include "philo.h"

void print_status(t_philo *philo, char *msg)
{
    long    timestamp;

    pthread_mutex_lock(&philo->rules->print);
    if(!simulation_finished(philo->rules))
    {
        timestamp = get_time_in_ms() - philo->rules->start_time;
        printf("%ld %d %s \n", timestamp, philo->id, msg);
    }
    pthread_mutex_unlock(&philo->rules->print);
}