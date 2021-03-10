#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct	s_philo
{
	int			nb_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int 		time_to_sleep;
	int			nb_of_time_eat;
	int			id;
	int			index;
	pthread_t	thread;
}				t_philo;

typedef struct  s_params
{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int 			time_to_sleep;
	int				nb_of_time_eat;
	int				index;
	struct timeval	time_before;
	struct timeval	time_after;
	struct timeval	time;
	t_philo			philo[200];
}               t_params;

void    ft_putendl(char *str);
void	ft_init_philo(char **argv, t_philo *philo, int i);
int		ft_atoi(const char *str);
long	ft_gettime(void);
void	*ft_calloc(size_t count, size_t size);
void	*ft_routine(void *arg);
void    *ft_wait(void *arg);
void    ft_clean(t_params *params);

#endif