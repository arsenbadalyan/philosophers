#include "philo.h"

unsigned int get_cur_time()
{
    struct timeval tv;
    static int count;
    static unsigned int start;
    
    if(count == 0)
    {
        gettimeofday(&tv, NULL);
        start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
        count++;
    } else
        gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - start);
}

void ms_sleep(unsigned int time)
{
    usleep(time * 1000);
}