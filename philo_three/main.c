/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:20 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/26 15:06:57 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		ft_check_params(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (ft_atoi(argv[i]) == -1)
			return (0);
	return (1);
}
/*
void	ft_init_thread(t_philo **philo)
{
	int		i;
	int		n;

	i = 0;
	n = (*philo)[0].nb_philo;
	if ((g_time.start = ft_gettime()) == -1)
		return ;
	while (i < n && g_time.dead)
	{
		if (((*philo)[i].pid = fork()) == 0)
			ft_routine(&(*philo)[i]);
		else if (((*philo)[i].pid = fork()) == -1)
			return (ft_putendl("[ERROR] Fork error."));
		i += 2;
	}
	i = 1;
	usleep(1000);
	while (++i < n && g_time.dead)
	{
		if (((*philo)[i].pid = fork()) == 0)
			ft_routine(&(*philo)[i]);
		else if (((*philo)[i].pid = fork()) == -1)
			return (ft_putendl("[ERROR] Fork error."));
		i += 2;
	}
	i = -1;
	// while (++i < n)
	// {
	// 	printf("i :%d %d\n", i, (*philo)[i].pid);
	// 	if ((*philo)[i].pid == 0)
	// 		waitpid((*philo)[i].pid, &status, 0);
	// }
	if ((*philo)[i - 1].nb_of_meal && ft_check_meal(*philo))
		return ;
}*/

void	ft_init_thread(t_philo *philo)
{
	int i;

	i = -1;
	//printf("init thread\n");
	if ((g_time.start = ft_gettime()) == -1)
		return ;
	if (!(philo->id % 2) && g_time.dead)
		pthread_create(&philo->thread, NULL, ft_routine, philo);
	else if ((philo->id % 2) && g_time.dead)
		pthread_create(&philo->thread, NULL, ft_routine, philo);
}

void	ft_init_fork(t_philo **philo)
{
	int i = -1;
	int n = (*philo)[0].nb_philo;

	while (++i < n && g_time.dead)
	{
		if (((*philo)[i].pid = fork()) == 0)
			ft_init_thread(&(*philo)[i]);
		else if (((*philo)[i].pid = fork()) == -1)
			return (ft_putendl("[ERROR] Fork error."));
	}
	i = -1;
	while (++i < n)
		pthread_join((*philo)[i].thread, NULL);
	if ((*philo)[i - 1].nb_of_meal && ft_check_meal(*philo))
		return ;
}

int		ft_start(char **argv)
{
	t_philo	*philo;
	int		nb_philo;
	int		i;
	int 	status;

	i = -1;
	if (!ft_check_params(argv))
		return (0);
	sem_unlink(SEM_NAME);
	sem_unlink(DEAD);
	nb_philo = ft_atoi(argv[1]);
	philo = ft_calloc((nb_philo), sizeof(*philo));
	if (!philo)
		return (0);
	ft_init_time(argv);
	ft_init_philo(argv, &philo);
	ft_init_fork(&philo);
	//ft_init_thread(&philo);
	i = -1;
	//while (++i < nb_philo)
	//	kill(philo[i].pid, SIGQUIT);
	while (++i < nb_philo)
	{
		//printf("i :%d %d\n", i, philo[i].pid);
		if (philo[i].pid == 0)
			waitpid(philo[i].pid, &status, 0);
	}
	ft_clean(&philo);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		ft_putendl("[ERROR] Wrong number of arguments.");
	else if (ft_check_params(argv) && ft_atoi(argv[1]) < 2)
		ft_putendl("[ERROR] Wrong number of philosophers.");
	else if (!ft_start(argv))
		ft_putendl("[ERROR] Wrong argument.");
	return (0);
}
