/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:15 by jdussert          #+#    #+#             */
/*   Updated: 2021/04/07 16:14:42 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_wait(long int ms, t_philo *philo)
{
	long int	start;

	start = ft_gettime();
	while (ft_gettime() - start < ms)
	{
		if (!ft_dead(philo))
			return (0);
		usleep(300);
	}
	return (1);
}

void	ft_mutex(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	if (!ft_dead(philo))
		return ;
	pthread_mutex_lock(&g_print);
	printf("[%ld]\tPhilosopher |%d| has taken a fork\n",
	ft_gettime() - g_time.start, philo->id);
	pthread_mutex_unlock(&g_print);
	ft_dead(philo);
}

void	*ft_lock_forks(t_philo *philo)
{
	if (g_time.dead || !ft_dead(philo))
		return (NULL);
	if (philo->id % 2 && !g_time.dead && ft_dead(philo))
		ft_mutex(philo, &philo->fork.lock);
	if (!g_time.dead && ft_dead(philo))
		ft_mutex(philo, &philo->n_fork->lock);
	if (!(philo->id % 2) && !g_time.dead && ft_dead(philo))
		ft_mutex(philo, &philo->fork.lock);
	return ("done");
}

void	*ft_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork.lock);
	pthread_mutex_unlock(&philo->n_fork->lock);
	return (NULL);
}
