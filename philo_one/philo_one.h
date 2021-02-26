#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct  s_philo
{
	int	nb_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int	nb_of_time_eat;
}               t_philo;

void    ft_putendl(char *str);
void	ft_init_philo(char **argv, t_philo *philo);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);

#endif