/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:08 by jdussert          #+#    #+#             */
/*   Updated: 2021/04/06 16:07:05 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&g_print);
	printf("[%ld]\tPhilosopher |%d| is eating\n", ft_gettime() - g_time.start,
	philo->id);
	pthread_mutex_unlock(&g_print);
	philo->nb_of_meal_eat++;
	return (1);
}

int		ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&g_print);
	printf("[%ld]\tPhilosopher |%d| is sleeping\n", ft_gettime() - g_time.start,
	philo->id);
	pthread_mutex_unlock(&g_print);
	return (1);
}

int		ft_think(t_philo *philo)
{
	pthread_mutex_lock(&g_print);
	printf("[%ld]\tPhilosopher |%d| is thinking\n", ft_gettime() - g_time.start,
	philo->id);
	pthread_mutex_unlock(&g_print);
	return (1);
}

int		ft_meals(t_philo *philo)
{
	if (philo->nb_of_meal_eat == philo->nb_of_meal && philo->nb_of_meal)
		return (0);
	return (1);
}

int		ft_dead(t_philo *philo)
{
	if (ft_gettime() - philo->last_meal > g_time.time_to_die)
	{
		g_time.dead = 1;
		pthread_mutex_lock(&g_print);
		printf("[%ld]\tPhilosopher |%d| died\n", ft_gettime() - g_time.start,
		philo->id);
		exit(0);
	}
	return (1);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (ft_dead(philo))
	{
		ft_lock_forks(philo);
		ft_eat(philo);
		philo->last_meal = ft_gettime();
		ft_wait(g_time.time_to_eat, philo);
		ft_unlock_forks(philo);
		if (!ft_meals(philo))
			return (NULL);
		ft_sleep(philo);
		ft_wait(g_time.time_to_sleep, philo);
		ft_think(philo);
		ft_dead(philo);
	}
	return (NULL);
}
