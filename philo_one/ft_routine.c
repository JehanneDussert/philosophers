#include "philo_one.h"

int		ft_is_dead(t_params *params)
{
	if (params->clock > 100000)
		return (1);
	return (0);
}

void	*ft_eat(void *arg)
{
	t_params	*params;

	params = (t_params *)arg;
	printf("%f\t%f\n", ft_gettime(params->time), params->start);
	params->clock = ft_gettime(params->time) - params->start;
	printf("%f\tPhilosopher [%d] is eating\n", params->clock, params->index + 1);
	return (0);
}

void	*ft_sleep(void *arg)
{
	t_params	*params;

	params = (t_params *)arg;
	params->clock = ft_gettime(params->time) - params->start;
	printf("%f\tPhilosopher [%d] is sleeping\n", params->clock, params->index + 1);
	return (0);
}

void	*ft_think(void *arg)
{
	t_params	*params;

	params = (t_params *)arg;
	params->clock = ft_gettime(params->time) - params->start;
	printf("%f\tPhilosopher [%d] is thinking\n", params->clock, params->index + 1);
	return (0);
}

void	*ft_routine(void *arg)
{
	t_params	*params;

	params = (t_params *)arg;
	//printf("clock :%ld [%d]\n", params->clock, params->nb_of_philo);
	while (params->index < params->nb_of_philo)
	{
		pthread_create(&params->philo->thread, NULL, ft_eat, params);
		pthread_join(params->philo->thread, NULL);
		pthread_create(&params->philo->thread, NULL, ft_sleep, params);
		pthread_join(params->philo->thread, NULL);
		pthread_create(&params->philo->thread, NULL, ft_think, params);
		pthread_join(params->philo->thread, NULL);
		params->index += 2;
	}
	return (0);
}
