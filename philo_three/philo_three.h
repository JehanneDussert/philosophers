/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:58:34 by jdussert          #+#    #+#             */
/*   Updated: 2021/04/10 13:23:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/ipc.h>
# include <sys/wait.h>
# include <signal.h>

# define SEM_NAME "forks"
# define LOCK "lock"
# define FORK -1
# define DEATH 0
# define EAT 1
# define DONE 2

typedef struct		s_fork
{
	pthread_mutex_t	lock;
}					t_fork;

typedef struct		s_my_sem
{
	sem_t			*forks;
}					t_my_sem;

typedef struct		s_time
{
	long int		start;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	int				dead;
}					t_time;

typedef struct		s_philo
{
	int				nb_of_meal_eat;
	int				nb_of_meal;
	int				nb_philo;
	long int		last_meal;
	int				id;
	pthread_t		thread;
	pid_t			pid;
}					t_philo;

int					g_nb_forks;
t_my_sem			g_forks;
t_time				g_time;
sem_t				*g_lock;
int					g_eat;
t_philo				*g_philo;

void				ft_putendl(char *str);
void				ft_init_philo(char **argv, t_philo **philo);
void				ft_init_time(char **argv);
int					ft_atoi(const char *str);
long int			ft_gettime(void);
void				*ft_calloc(size_t count, size_t size);
void				*ft_routine(void *arg);
int					ft_wait(long int ms, t_philo *philo);
void				*ft_dead(t_philo *philo);
void				ft_clean(t_philo **philo);
void				*ft_lock_forks(t_philo *philo);
void				*ft_unlock_forks(void);
int					ft_check_meal(t_philo *philo);
void				*ft_meals(t_philo *philo);
void				ft_simple_clean(t_philo **philo);

#endif
