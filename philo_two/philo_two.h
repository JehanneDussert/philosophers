/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:58:34 by jdussert          #+#    #+#             */
/*   Updated: 2021/04/06 18:10:17 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

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

# define SEM_NAME "forks"
# define LOCK "lock"

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
}					t_philo;

int					g_nb_forks;
t_my_sem			g_forks;
sem_t				*g_lock;
t_time				g_time;

void				ft_putendl(char *str);
void				ft_init_philo(char **argv, t_philo **philo);
void				ft_init_time(char **argv);
int					ft_atoi(const char *str);
long int			ft_gettime(void);
void				*ft_calloc(size_t count, size_t size);
void				*ft_routine(void *arg);
int					ft_wait(long int ms, t_philo *philo);
int					ft_dead(t_philo *philo);
void				ft_clean(t_philo **philo);
void				*ft_lock_forks(t_philo *philo);
void				*ft_unlock_forks(void);
int					ft_check_meal(t_philo *philo);

#endif
