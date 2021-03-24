/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:15 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/24 17:00:20 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		ft_wait(long int ms, t_philo *philo)
{
	long int	start;

	start = ft_gettime();
	while (ft_dead(philo) && ft_gettime() - start < ms && !g_time.dead)
	{
		if (!ft_dead(philo) || g_time.dead)
			return (0);
		usleep(100);
	}
	return (1);
}

void	*ft_lock_forks(t_philo *philo)
{
	if (!ft_dead(philo))
		return (NULL);
	if (ft_dead(philo) && philo->id % 2)
	{
		pthread_mutex_lock(&philo->fork.lock);
		if (ft_gettime() == -1 || !ft_dead(philo))
			return (ft_unlock_forks(philo));
		printf("[%ld]\tPhilosopher |%d| has taken a fork\n",
		ft_gettime() - g_time.start, philo->id);
	}
	if (philo->nb_philo > 1)
		pthread_mutex_lock(&philo->n_fork->lock);
	if (ft_gettime() == -1 || !ft_dead(philo) || g_time.dead)
		return (ft_unlock_forks(philo));
	printf("[%ld]\tPhilosopher |%d| has taken a fork\n",
	ft_gettime() - g_time.start, philo->id);
	if (ft_dead(philo) && !(philo->id % 2))
	{
		pthread_mutex_lock(&philo->fork.lock);
		if (ft_gettime() == -1 || !ft_dead(philo))
			return (ft_unlock_forks(philo));
		printf("[%ld]\tPhilosopher |%d| has taken a fork\n",
		ft_gettime() - g_time.start, philo->id);
	}
	return ("done");
}

void	*ft_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork.lock);
	pthread_mutex_unlock(&philo->n_fork->lock);
	return (NULL);
}
