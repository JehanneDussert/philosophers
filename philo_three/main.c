/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:03:20 by jdussert          #+#    #+#             */
/*   Updated: 2021/04/05 17:12:18 by jdussert         ###   ########.fr       */
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

void	ft_init_fork(t_philo **philo)
{
	int i;
	int n;
	int status;
	int ret;

	i = -1;
	n = (*philo)[0].nb_philo;
	if ((g_time.start = ft_gettime()) == -1)
		return ;
	while (++i < n)
		if (((*philo)[i].pid = fork()) == 0)
			ft_routine(&(*philo)[i]);
	usleep(1000);
	i = -1;
	while (++i < n)
	{
		wait(&status);
		ret = WEXITSTATUS(status);
		if (ret == DEATH)
			while (i < n)
				kill((*philo)[i++].pid, SIGQUIT);
		else if (ret == EAT)
			return ;
	}
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
	sem_unlink(LOCK);
	nb_philo = ft_atoi(argv[1]);
	philo = ft_calloc((nb_philo), sizeof(*philo));
	if (!philo)
		return (0);
	ft_init_time(argv);
	ft_init_philo(argv, &philo);
	ft_init_fork(&philo);
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
