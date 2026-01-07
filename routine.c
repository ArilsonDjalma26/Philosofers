#include "philo.h"

void    *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        usleep(1000); //evita deadlock inicial
    while (!simulation_finished(philo->rules))
    {
        eat(philo);
        sleep_philo(philo);
        think(philo);
    }
    return (NULL);
}