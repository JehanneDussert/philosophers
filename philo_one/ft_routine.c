/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:08 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/25 14:53:23 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_eat(t_philo *philo)
{
	if (ft_gettime() == -1 || !ft_dead(philo) || g_time.dead)
		return (0);
	printf("[%ld]\tPhilosopher |%d| is eating\n", ft_gettime() - g_time.start,
	philo->id);
	philo->nb_of_meal_eat++;
	return (1);
}

int		ft_sleep(t_philo *philo)
{
	if (ft_gettime() == -1 || !ft_dead(philo) || g_time.dead)
		return (0);
	printf("[%ld]\tPhilosopher |%d| is sleeping\n", ft_gettime() - g_time.start,
	philo->id);
	return (1);
}

int		ft_think(t_philo *philo)
{
	if (ft_gettime() == -1 || !ft_dead(philo) || g_time.dead)
		return (0);
	printf("[%ld]\tPhilosopher |%d| is thinking\n", ft_gettime() - g_time.start,
	philo->id);
	return (1);
}

int		ft_dead(t_philo *philo)
{
	if (g_time.dead)
		return (0);
	else if (ft_gettime() - philo->last_meal > g_time.time_to_die)
	{
		g_time.dead = 1;
		printf("[%ld]\tPhilosopher |%d| died\n", ft_gettime() - g_time.start,
		philo->id);
		return (0);
	}
	else if (philo->nb_of_meal_eat == philo->nb_of_meal && philo->nb_of_meal)
		return (0);
	else if (philo->nb_of_meal_eat < philo->nb_of_meal ||
			philo->nb_of_meal == 0)
		return (3);
	return (0);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (ft_dead(philo) && !g_time.dead)
	{
		if (g_time.dead || ft_lock_forks(philo) == NULL || !ft_dead(philo))
			return (NULL);
		if (!ft_eat(philo))
			return (NULL);
		philo->last_meal = ft_gettime();
		if (!ft_wait(g_time.time_to_eat, philo))
			return (NULL);
		ft_unlock_forks(philo);
		if (!ft_sleep(philo) || !ft_wait(g_time.time_to_sleep, philo)
			|| !ft_think(philo))
			return (NULL);
	}
	return (NULL);
}
