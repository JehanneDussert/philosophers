/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:08 by jdussert          #+#    #+#             */
/*   Updated: 2021/04/05 17:13:57 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		ft_eat(t_philo *philo)
{
	if (ft_gettime() == -1 || ft_dead(philo) || g_time.dead)
		return (0);
	sem_wait(g_lock);
	printf("[%ld]\tPhilosopher |%d| is eating\n", ft_gettime() - g_time.start,
	philo->id);
	sem_post(g_lock);
	philo->nb_of_meal_eat++;
	return (1);
}

int		ft_sleep(t_philo *philo)
{
	if (ft_gettime() == -1 || ft_dead(philo))
		return (0);
	sem_wait(g_lock);
	printf("[%ld]\tPhilosopher |%d| is sleeping\n", ft_gettime() - g_time.start,
	philo->id);
	sem_post(g_lock);
	return (1);
}

int		ft_think(t_philo *philo)
{
	if (ft_gettime() == -1 || ft_dead(philo) || g_time.dead)
		return (0);
	sem_wait(g_lock);
	printf("[%ld]\tPhilosopher |%d| is thinking\n", ft_gettime() - g_time.start,
	philo->id);
	sem_post(g_lock);
	return (1);
}

void	*ft_dead(t_philo *philo)
{
	if (ft_gettime() - philo->last_meal > g_time.time_to_die)
	{
		g_time.dead = 1;
		sem_wait(g_lock);
		printf("[%ld]\tPhilosopher |%d| died\n", ft_gettime() - g_time.start,
		philo->id);
		exit (DEATH);
	}
	else if (philo->nb_of_meal_eat == philo->nb_of_meal && philo->nb_of_meal)
		exit (EAT);
	else if (philo->nb_of_meal_eat < philo->nb_of_meal ||
			philo->nb_of_meal == 0)
		return (NULL);
	return (NULL);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!g_time.dead)
	{
		if (g_time.dead)
			sem_wait(g_lock);
		ft_lock_forks(philo);
		ft_eat(philo);
		philo->last_meal = ft_gettime();
		ft_wait(g_time.time_to_eat, philo);
		ft_sleep(philo);
		ft_wait(g_time.time_to_sleep, philo);
		ft_think(philo);
	}
	return (NULL);
}
