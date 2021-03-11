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

void	ft_init_params(t_params *params, t_philo *philo, char **argv)
{
	params->nb_of_philo = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		params->nb_of_time_eat = ft_atoi(argv[5]);
	params->philo = philo;
}

void	ft_init_philo(char **argv, t_philo *philo, int i)
{
	philo->id = i + 1;
	if (argv[5])
		philo->nb_of_meal_eat = 0;
}

int ft_gettime(struct timeval start)
{
	struct timeval	time;
	int			new;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	new = (((time.tv_sec - start.tv_sec) * 1000000 + time.tv_usec) - start.tv_usec) / 100;
	return (new);
}
