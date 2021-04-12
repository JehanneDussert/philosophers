/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:27 by jdussert          #+#    #+#             */
/*   Updated: 2021/04/12 11:27:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_simple_clean(t_philo **philo)
{
	sem_close(g_forks.forks);
	sem_close(g_lock);
	if (!philo || !(*philo))
		return ;
	free(*philo);
	(*philo) = NULL;
}

void	ft_clean(t_philo **philo)
{
	int	i;
	int	n;

	i = -1;
	sem_close(g_forks.forks);
	sem_close(g_lock);
	n = (*philo)[0].nb_philo;
	if (!philo || !(*philo))
		return ;
	while (++i < n)
		kill((*philo)[i].pid, SIGKILL);
	free(*philo);
	(*philo) = NULL;
}
