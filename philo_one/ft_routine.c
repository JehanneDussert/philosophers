#include "philo_one.h"

int		ft_is_dead(t_params *params)
{
	// need to change it
	if (params->clock > 100000)
		return (1);
	return (0);
}

int	ft_eat(t_params *params)
{
	if ((params->clock = ft_gettime(params->time_start)) == -1)
		return (-1);
	printf("[%d]\tPhilosopher |%d| is eating\n", params->clock - params->start, params->philo[params->index].id);
	params->philo[params->index].nb_of_meal_eat++;
	params->philo[params->index].last_meal = params->clock;
	return (0);
}

int	ft_sleep(t_params *params)
{
	if ((params->clock = ft_gettime(params->time_start)) == -1)
		return (-1);
	printf("[%d]\tPhilosopher |%d| is sleeping\n", params->clock - params->start, params->philo[params->index].id);
	return (0);
}

int	ft_think(t_params *params)
{
	if ((params->clock = ft_gettime(params->time_start)) == -1)
		return (-1);
	printf("[%d]\tPhilosopher |%d| is thinking\n", params->clock - params->start, params->philo[params->index].id);
	return (0);
}

int		ft_dead(t_params *params)
{
	if (params->clock - params->start < params->time_to_die)
		return (1);
	else if (params->philo[params->index].nb_of_meal_eat < params->nb_of_time_eat)
		return (2);
	return (0);
}

void	*ft_routine(void *arg)
{
	t_params	*params;

	params = (t_params *)arg;
	while (ft_dead(params))
	{
		if (ft_lock_forks(params) == NULL)
			return (NULL);
		ft_eat(params);
		ft_unlock_forks(params);
		ft_sleep(params);
		ft_think(params);
	}
	return (NULL);
}
