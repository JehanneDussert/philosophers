/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:15 by jdussert          #+#    #+#             */
/*   Updated: 2021/04/06 12:21:39 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		ft_wait(long int ms, t_philo *philo)
{
	long int	start;

	start = ft_gettime();
	while (ft_gettime() - start < ms)
	{
		if (!ft_dead(philo) || g_time.dead)
			return (0);
		usleep(100);
	}
	return (1);
}

void	ft_lock_forks(t_philo *philo)
{
	sem_wait(g_forks.forks);
	sem_wait(g_forks.forks);
	sem_wait(g_lock);
	printf("[%ld]\tPhilosopher |%d| has taken a fork\n",
	ft_gettime() - g_time.start, philo->id);
	sem_post(g_forks.forks);
	printf("[%ld]\tPhilosopher |%d| has taken a fork\n",
	ft_gettime() - g_time.start, philo->id);
	sem_post(g_forks.forks);
	sem_post(g_lock);
}
