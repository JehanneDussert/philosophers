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

void	ft_init_philo(char **argv, t_philo *philo, int i)
{
	philo->id = i + 1;
	philo->time_after.tv_sec = 0;
	philo->time.tv_sec = 0;
	philo->time_after.tv_usec = 0;
	philo->time.tv_usec = 0;
	philo->nb_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->nb_of_time_eat = ft_atoi(argv[5]);
}
