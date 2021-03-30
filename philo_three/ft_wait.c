/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:15 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/30 15:20:40 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		ft_wait(long int ms, t_philo *philo)
{
	long int	start;
	(void)philo;
	
	start = ft_gettime();
	while (ft_gettime() - start < ms && !g_dead)
	{
		if (g_dead)
			return (0);
		usleep(100);
	}
	return (1);
}

void	*ft_lock_forks(t_philo *philo)
{
	if (g_dead)
		return (NULL);
	if (!g_dead && philo->id % 2)
	{
		sem_wait(g_forks.forks);
		if (ft_gettime() == -1 || g_dead)
			return (ft_unlock_forks(philo));
		printf("[%ld]\tPhilosopher |%d| has taken a fork\n",
		ft_gettime() - g_time.start, philo->id);
	}
	sem_wait(g_forks.forks);
	if (ft_gettime() == -1 || g_dead)
		return (ft_unlock_forks(philo));
	printf("[%ld]\tPhilosopher |%d| has taken a fork\n",
	ft_gettime() - g_time.start, philo->id);
	if (!g_dead && !(philo->id % 2))
	{
		sem_wait(g_forks.forks);
		if (ft_gettime() == -1 || g_dead)
			return (ft_unlock_forks(philo));
		printf("[%ld]\tPhilosopher |%d| has taken a fork\n",
		ft_gettime() - g_time.start, philo->id);
	}
	return ("done");
}

void	*ft_unlock_forks(t_philo *philo)
{
	(void)philo;
	sem_post(g_forks.forks);
	sem_post(g_forks.forks);
	return (NULL);
}
