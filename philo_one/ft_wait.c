#include "philo_one.h"

void    *ft_wait(void *arg)
{
    t_philo			*philo;

	philo = (t_philo *)arg;
    // protection avec mutex
    return (NULL);
}

void	*ft_lock_forks(t_params *params)
{
	if (params->philo[params->index].id % 2)
	{
		pthread_mutex_lock(&params->philo[params->index].fork.lock);
		if ((params->clock = ft_gettime(params->time_start)) == -1)
			return (NULL);
		printf("[%d]\tPhilosopher |%d| has taken a fork\n", params->clock - params->start, params->philo[params->index].id);
	}
	pthread_mutex_lock(&params->philo[params->index].n_fork->lock);
	printf("[%d]\tPhilosopher |%d| has taken a fork\n", params->clock - params->start, params->philo[params->index].id);
	if (!params->philo[params->index].id % 2)
	{
		pthread_mutex_lock(&params->philo[params->index].fork.lock);
		if ((params->clock = ft_gettime(params->time_start)) == -1)
			return (NULL);
		printf("[%d]\tPhilosopher |%d| has taken a fork\n", params->clock - params->start, params->philo[params->index].id);
	}
	params->philo[params->index].fork_taken = 2;
	return ("done");
}

void	ft_unlock_forks(t_params *params)
{
	pthread_mutex_unlock(&params->philo[params->index].fork.lock);
	pthread_mutex_unlock(&params->philo[params->index].n_fork->lock);
}
