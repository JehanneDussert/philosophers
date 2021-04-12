/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:11:33 by jdussert          #+#    #+#             */
/*   Updated: 2021/04/12 09:11:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		ft_init_philo(char **argv, t_philo **philo)
{
	int	i;

	i = -1;
	g_nb_forks = ft_atoi(argv[1]);
	while (++i < g_nb_forks)
	{
		(*philo)[i].nb_philo = g_nb_forks;
		(*philo)[i].id = i + 1;
		(*philo)[i].last_meal = ft_gettime();
		(*philo)[i].nb_of_meal_eat = 0;
		if (argv[5])
			(*philo)[i].nb_of_meal = ft_atoi(argv[5]);
	}
	if ((g_forks.forks = sem_open(SEM_NAME, O_CREAT, 644, g_nb_forks))
		== SEM_FAILED)
		printf("[ERROR] Can't open semaphore.\n");
	else if ((g_lock = sem_open(LOCK, O_CREAT, 644, 1)) == SEM_FAILED)
	{
		sem_close(g_forks.forks);
		printf("[ERROR] Can't open semaphore.\n");
	}
	g_eat = 0;
}

void		ft_init_time(char **argv)
{
	g_time.time_to_die = ft_atoi(argv[2]);
	g_time.time_to_eat = ft_atoi(argv[3]);
	g_time.time_to_sleep = ft_atoi(argv[4]);
	g_time.dead = 0;
}
