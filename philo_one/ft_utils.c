/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:30 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/22 14:23:37 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			ft_is_ascii(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0' && (str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r' ||
		str[i] == ' ') && str[i] != '-' && str[i] == '+')
		i++;
	while (str[i] && ft_is_ascii(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] && !ft_is_ascii(str[i]))
		return (-1);
	return (result);
}

void		*ft_calloc(size_t count, size_t size)
{
	char	*r;
	size_t	i;

	i = 0;
	if (!size || !count)
	{
		size = 1;
		count = 1;
	}
	if (!(r = malloc(count * size)))
		return (NULL);
	while (i < (size * count))
	{
		*(char *)r = '\0';
		r++;
		i++;
	}
	return (r - i);
}

long int	ft_gettime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int			ft_check_meal(t_philo *philo)
{
	int i;

	i = -1;
	while (philo[++i].id < philo[0].nb_philo)
		if (!(philo[i].nb_of_meal_eat == philo[i].nb_of_meal))
			return (0);
	return (1);
}
