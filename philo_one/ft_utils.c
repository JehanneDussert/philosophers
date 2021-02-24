#include "philo_one.h"

void	ft_putendl(char *str)
{
	int i;

	i = 0;
	while (str[i++])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

void	ft_init_struct(char **argv, t_struct *struct)
{
	struct->nb_of_philo = argv[1];
	struct->time_to_die = argv[2];
	struct->time_to_eat = argv[3];
	struct->time_to_sleep argv[4];
	if (argv[5])
		struct->nb_of_time_eat = argv[5];
}