/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:20 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/22 12:03:21 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    ft_init_thread(t_philo **philo)
{
	int i;
	int n;

	i = -1;
	n = (*philo)[0].nb_philo - 1;
	if (gettimeofday(&g_time.time_start, NULL) == -1)
		return ;
	g_time.start = ft_gettime();
	while (++i <= n && g_time.dead)
		if (!(i % 2))
		{
			pthread_create(&(*philo)[i].thread, NULL, ft_routine, &(*philo)[i]);
			printf("1 dead :%d\n", g_time.dead);		
		}
	i = -1;
	usleep(500);
	while (++i <= n && g_time.dead)
		{
			pthread_create(&(*philo)[i].thread, NULL, ft_routine, &(*philo)[i]);
			printf("2 dead :%d\n", g_time.dead);		
		}
	i--;
	printf("3 dead :%d\n", g_time.dead);
	if ((g_time.clock = ft_gettime()) == -1)
		return ;
	printf("la %d %d %d\n", g_time.dead, ft_dead(&(*philo)[i]), i);
	if (g_time.dead && ft_dead(&(*philo)[i]))
		pthread_join((*philo)[i].thread, NULL);
	printf("here\n");
	if ((*philo)[i].nb_of_meal && ft_check_meal(*philo))
		return ;
}

void    ft_start(char **argv)
{
    t_philo		*philo;
	int			nb_philo;
	int			i;

	i = -1;
	nb_philo = ft_atoi(argv[1]);
	philo = ft_calloc((nb_philo), sizeof(*philo));
	if (!philo)
		return ;
	ft_init_time(argv);
	ft_init_philo(argv, &philo);
	ft_init_thread(&philo);
	ft_clean(&philo);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		ft_putendl("[ERROR] Wrong number of arguments.");
	else
		ft_start(argv);
	return (0);
}
