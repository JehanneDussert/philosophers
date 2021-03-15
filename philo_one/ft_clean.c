#include "philo_one.h"

void    ft_clean(t_philo **philo, t_params *params)
{
	free(*philo);
	(*philo) = NULL;
	params = NULL;
}