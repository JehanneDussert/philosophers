/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:15 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/25 17:02:45 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		ft_wait(long int ms, t_philo *philo)
{
	long int	start;

	start = ft_gettime();
	while (ft_dead(philo) && ft_gettime() - start < ms && g_time.dead)
	{
		if (!ft_dead(philo) || !g_time.dead)
			return (0);
		usleep(100);
	}
	return (1);
}

void	*ft_lock_forks(t_philo *philo)
{
	if (!ft_dead(philo) || !g_time.dead)
		return (NULL);
	if (ft_dead(philo) && philo->id % 2)
	{
		sem_wait(g_forks.forks);
		if (ft_gettime() == -1 || !ft_dead(philo))
			return (ft_unlock_forks(philo));
		printf("[%ld]\tPhilosopher |%d| has taken a fork\n",
		ft_gettime() - g_time.start, philo->id);
	}
	sem_wait(g_forks.forks);
	if (ft_gettime() == -1 || !ft_dead(philo) || !g_time.dead)
		return (ft_unlock_forks(philo));
	printf("[%ld]\tPhilosopher |%d| has taken a fork\n",
	ft_gettime() - g_time.start, philo->id);
	if (ft_dead(philo) && !(philo->id % 2))
	{
		sem_wait(g_forks.forks);
		if (ft_gettime() == -1 || !ft_dead(philo))
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
