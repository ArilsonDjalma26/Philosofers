#include "philo.h"

int simulation_finished(t_rules *rules)
{
    int finished;

    pthread_mutex_lock(&rules->finish_mutex);
    finished = rules->finished;
    pthread_mutex_unlock(&rules->finish_mutex);
    return (finished);
}