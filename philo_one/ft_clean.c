#include "philo_one.h"

void    ft_clean(t_philo **philo)
{
	free(*philo);
	(*philo) = NULL;
}