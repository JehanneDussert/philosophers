#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <stdio.h>

typedef struct  s_struct
{
	int	nb_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int	nb_of_time_eat;
}               t_struct;

void    ft_putendl(char *str);

#endif