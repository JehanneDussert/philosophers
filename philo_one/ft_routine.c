#include "philo_one.h"

int		ft_is_dead(t_params *params)
{
	if (params->clock > 100000)
		return (1);
	return (0);
}

int	ft_eat(t_params *params)
{
	if (!(params->clock = ft_gettime()))
		return (-1);
	printf("[%ld]\tPhilosopher |%d| is eating\n", params->clock - params->start, params->index);
	return (0);
}

int	ft_sleep(t_params *params)
{
	if (!(params->clock = ft_gettime()))
		return (-1);
	printf("[%ld]\tPhilosopher |%d| is sleeping\n", params->clock - params->start, params->index);
	return (0);
}

int	ft_think(t_params *params)
{
	if (!(params->clock = ft_gettime()))
		return (-1);
	printf("[%ld]\tPhilosopher |%d| is thinking\n", params->clock - params->start, params->index);
	return (0);
}

void	*ft_routine(void *arg)
{
	t_params	*params;

	params = (t_params *)arg;
	ft_eat(params);
	ft_sleep(params);
	ft_think(params);
	return (0);
}
