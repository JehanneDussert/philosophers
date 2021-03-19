#include "philo_one.h"

int		ft_atoi(const char *str)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0' && (str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r' ||
		str[i] == ' '))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
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

void	ft_init_philo(char **argv, t_philo **philo)
{
	int	i;
	int	n;

	i = -1;
	n = ft_atoi(argv[1]) - 1;
	while(++i < n)
	{
		(*philo)[i].nb_philo = n + 1;
		(*philo)[i].id = i + 1;
		pthread_mutex_init(&(*philo)[i].fork.lock, NULL);
		(*philo)[i].n_fork = &(*philo)[i + 1].fork;
		(*philo)[i].nb_of_meal_eat = 0;
		if (argv[5])
			(*philo)[i].nb_of_meal = ft_atoi(argv[5]);
	}
	if (argv[5])
		(*philo)[i].nb_of_meal = ft_atoi(argv[5]);
	pthread_mutex_init(&(*philo)[i].fork.lock, NULL);
	(*philo)[i].id = i + 1;
	(*philo)[i].n_fork = &(*philo)[0].fork;
	g_time.time_to_die = ft_atoi(argv[2]);
	g_time.time_to_eat = ft_atoi(argv[3]);
<<<<<<< HEAD
	g_time.time_to_sleep= ft_atoi(argv[4]);
=======
	g_time.time_to_sleep = ft_atoi(argv[4]);
>>>>>>> correct_nb_meal
}

long int ft_gettime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int		ft_check_meal(t_philo *philo)
{
	int i;

	i = -1;
	while (philo[++i].id < philo[0].nb_philo)
		if (!(philo[i].nb_of_meal_eat == philo[i].nb_of_meal))
			return (0);
	return (1);
}
