/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:11:33 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/22 12:11:56 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		ft_init_philo(char **argv, t_philo **philo)
{
	int	i;
	int	n;

	i = -1;
	n = ft_atoi(argv[1]) - 1;
	while (++i < n)
	{
		(*philo)[i].nb_philo = n + 1;
		(*philo)[i].id = i + 1;
		(*philo)[i].last_meal = ft_gettime();
		pthread_mutex_init(&(*philo)[i].fork.lock, NULL);
		(*philo)[i].n_fork = &(*philo)[i + 1].fork;
		(*philo)[i].nb_of_meal_eat = 0;
		if (argv[5])
			(*philo)[i].nb_of_meal = ft_atoi(argv[5]);
	}
	if (argv[5])
		(*philo)[i].nb_of_meal = ft_atoi(argv[5]);
	(*philo)[i].last_meal = ft_gettime();
	pthread_mutex_init(&(*philo)[i].fork.lock, NULL);
	(*philo)[i].id = i + 1;
	(*philo)[i].n_fork = &(*philo)[0].fork;
}

void		ft_init_time(char **argv)
{
	g_time.time_to_die = ft_atoi(argv[2]);
	g_time.time_to_eat = ft_atoi(argv[3]);
	g_time.time_to_sleep = ft_atoi(argv[4]);
	g_time.dead = 0;
	if ((g_time.clock = ft_gettime()) == -1)
		return ;
}
