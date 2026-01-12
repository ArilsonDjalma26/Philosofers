#include "philo.h"

void eat(t_philo *philo)
{
    if(simulation_finished(philo->rules))
        return ;
    pthread_mutex_lock(philo->left_fork);
    print_status(philo, "has taken a fork");
    pthread_mutex_lock(philo->rigth_fork);
    print_status(philo, "has taken fork");
    philo->last_meal = get_time_in_ms();
    print_status(philo, "is eating");
    precise_sleep(philo->rules->time_eat);
    philo->meal_eaten++;
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->rigth_fork);
}
void    think(t_philo *philo)
{
    if(simulation_finished(philo->rules))
        return ;
    print_status(philo, "is thinking");
}
void    sleep_philo(t_philo *philo)
{
    if(simulation_finished(philo->rules))
        return;
    print_status(philo, "is sleeping");
    precise_sleep(philo->rules->time_sleep);
}
