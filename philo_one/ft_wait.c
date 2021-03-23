/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:15 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/22 12:03:16 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    ft_wait(long int ms, t_philo *philo)
{
	long int start;

	start = ft_gettime();
	while (ft_dead(philo) && ft_gettime() - start < ms)
		usleep(100);
}

void	*ft_lock_forks(t_philo *philo)
{
	if (!ft_dead(philo))
		return (NULL);
	if (ft_dead(philo) && philo->id % 2)
	{
		pthread_mutex_lock(&philo->fork.lock);
		printf("[%d]\tPhilosopher |%d| has taken a fork\n", g_time.clock - g_time.start, philo->id);
	}
	pthread_mutex_lock(&philo->n_fork->lock);
	if (!ft_dead(philo))
		return (NULL);
	printf("[%d]\tPhilosopher |%d| has taken a fork\n", g_time.clock - g_time.start, philo->id);
	if (ft_dead(philo) && !(philo->id % 2))
	{
		pthread_mutex_lock(&philo->fork.lock);
		printf("[%d]\tPhilosopher |%d| has taken a fork\n", g_time.clock - g_time.start, philo->id);
	}
	printf("out\n");
	return (NULL);
}

void	ft_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork.lock);
	pthread_mutex_unlock(&philo->n_fork->lock);
}
