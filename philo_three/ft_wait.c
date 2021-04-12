/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:15 by jdussert          #+#    #+#             */
/*   Updated: 2021/04/12 11:23:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*ft_meals(t_philo *philo)
{
	if (philo->nb_of_meal_eat == philo->nb_of_meal && philo->nb_of_meal)
	{
		ft_unlock_forks();
		ft_simple_clean(&g_philo);
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
		usleep(300);
	}
	return (1);
}

void	*ft_lock_forks(t_philo *philo)
{
	sem_wait(g_forks.forks);
	sem_wait(g_forks.forks);
	ft_dead(philo);
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
