/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:02:47 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/22 12:02:49 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct	s_fork
{
	pthread_mutex_t	lock;
}				t_fork;

typedef struct	s_time
{
	struct timeval	time_start;
	struct timeval	time;
	int				start;
	int				clock;
	int				time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	int				dead;
}				t_time;

typedef struct	s_philo
{
	int				nb_of_meal_eat;
	int				nb_of_meal;
	int				nb_philo;
	int				last_meal;
	int				id;
	t_time			*time;
	t_fork			fork;
	t_fork			*n_fork;
	pthread_t		thread;
}				t_philo;

t_time	g_time;

void   		ft_putendl(char *str);
void		ft_init_philo(char **argv, t_philo **philo);
void		ft_init_time(char **argv);
int			ft_atoi(const char *str);
long int	ft_gettime(void);
void		*ft_calloc(size_t count, size_t size);
void		*ft_routine(void *arg);
void    	ft_wait(long int ms, t_philo *philo);
int			ft_dead(t_philo *philo);
void    	ft_clean(t_philo **philo);
void		*ft_lock_forks(t_philo *philo);
void		ft_unlock_forks(t_philo *philo);
int			ft_check_meal(t_philo *philo);

#endif