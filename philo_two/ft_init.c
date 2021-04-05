/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:11:33 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/25 14:37:11 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
	if ((g_forks.forks = sem_open(SEM_NAME, O_CREAT, 644, g_nb_forks)) == SEM_FAILED)
		printf("error\n");
}

void		ft_init_time(char **argv)
{
	g_time.time_to_die = ft_atoi(argv[2]);
	g_time.time_to_eat = ft_atoi(argv[3]);
	g_time.time_to_sleep = ft_atoi(argv[4]);
	g_time.dead = 0;
}
