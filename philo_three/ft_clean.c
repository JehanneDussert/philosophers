/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:27 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/25 16:52:10 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_clean(t_philo **philo)
{
	int	i;
	int	n;

	i = -1;
	n = (*philo)[0].nb_philo;
	if (!philo)
		return ;
	free(*philo);
	(*philo) = NULL;
	if (sem_close(g_forks.forks) == -1)
		return ;
	else if (sem_unlink(SEM_NAME) == -1)
		return ;
	else if (sem_close(g_time.dead) == -1)
		return ;
	else if (sem_unlink(DEAD) == -1)
		return ;
}
