/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:20 by jdussert          #+#    #+#             */
/*   Updated: 2021/03/25 17:00:22 by jdussert         ###   ########.fr       */
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

void	ft_init_thread(t_philo **philo)
{
	int		i;
	int		n;
	pid_t	*pid;
	int		status;

	i = -1;
	n = (*philo)[0].nb_philo;
	pid = ft_calloc((n), sizeof(*pid));
	if (!pid)
		return ;
	if ((g_time.start = ft_gettime()) == -1)
		return ;
	while (++i < n)
		if (!(i % 2) && g_time.dead)
			if ((pid[i] = fork()) == 0)
				ft_routine(&(*philo)[i]);
	i = -1;
	usleep(1000);
	while (++i < n)
		if (i % 2 && g_time.dead)
			if ((pid[i] = fork()) == 0)
				ft_routine(&(*philo)[i]);
	i = -1;
	while (++i < n)
		waitpid(pid[i], &status, 0);
	if ((*philo)[i - 1].nb_of_meal && ft_check_meal(*philo))
		return ;
}

int		ft_start(char **argv)
{
	t_philo	*philo;
	int		nb_philo;
	int		i;

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
	ft_init_thread(&philo);
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
