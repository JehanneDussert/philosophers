/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:27 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/22 13:56:42 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_clean(t_philo **philo)
{
	int	i;
	int	n;

	i = -1;
	n = (*philo)[0].nb_philo;
	if (!philo)
		return ;
	while (++i < n)
		pthread_mutex_destroy(&(*philo)[i].fork.lock);
	free(*philo);
	(*philo) = NULL;
}
