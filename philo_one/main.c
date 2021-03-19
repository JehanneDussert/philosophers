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
	while (++i <= n)
		if (!(i % 2))
			pthread_create(&(*philo)[i].thread, NULL, ft_routine, &(*philo)[i]);
	i = -1;
	usleep(500);
	while (++i <= n)
		if (i % 2)
			pthread_create(&(*philo)[i].thread, NULL, ft_routine, &(*philo)[i]);
	i--;
	pthread_join((*philo)[i].thread, NULL);
	if ((*philo)[i].nb_of_meal && ft_check_meal(*philo))
		return ;
	printf("[%d]\tPhilosopher |%d| is dead\n", g_time.clock - g_time.start, (*philo)[i].id);
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