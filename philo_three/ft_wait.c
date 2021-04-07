/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:15 by jdussert          #+#    #+#             */
/*   Updated: 2021/04/07 14:15:59 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*ft_meals(t_philo *philo)
{
	if (philo->nb_of_meal_eat == philo->nb_of_meal && philo->nb_of_meal)
	{
		sem_wait(g_lock);
		exit(EAT);
	}
	return (NULL);
}

int		ft_wait(long int ms, t_philo *philo)
{
	long int	start;

	start = ft_gettime();
	while (ft_gettime() - start < ms)
	{
		ft_dead(philo);
		usleep(100);
	}
	return (1);
}

void	*ft_lock_forks(t_philo *philo)
{
	sem_wait(g_forks.forks);
	sem_wait(g_forks.forks);
	ft_dead(philo);
	ft_meals(philo);
	sem_wait(g_lock);
	printf("[%ld]\tPhilosopher |%d| has taken a fork\n",
	ft_gettime() - g_time.start, philo->id);
	printf("[%ld]\tPhilosopher |%d| has taken a fork\n",
	ft_gettime() - g_time.start, philo->id);
	sem_post(g_lock);
	return ("done");
}

void	*ft_unlock_forks(void)
{
	sem_post(g_forks.forks);
	sem_post(g_forks.forks);
	return ("done");
}
