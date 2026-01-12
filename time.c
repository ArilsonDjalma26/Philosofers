#include "philo.h"

void    precise_sleep(long time)
{
    long start;

    start = get_time_in_ms();
    while (get_time_in_ms() - start < time)
        usleep(100);
}
long    get_time_in_ms(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}