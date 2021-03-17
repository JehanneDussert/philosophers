#include "philo_one.h"

void    ft_wait(void)
{
	long int start;

	start = ft_gettime();
	while (ft_gettime() - start < g_time.time_to_die)
		usleep(400);
}

void	*ft_lock_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->fork.lock);
		if ((g_time.clock = ft_gettime()) == -1)
			return (NULL);
		printf("[%d]\tPhilosopher |%d| has taken a fork\n", g_time.clock - g_time.start, philo->id);
	}
	pthread_mutex_lock(&philo->n_fork->lock);
	printf("[%d]\tPhilosopher |%d| has taken a fork\n", g_time.clock - g_time.start, philo->id);
	if (!(philo->id % 2))
	{
		pthread_mutex_lock(&philo->fork.lock);
		if ((g_time.clock = ft_gettime()) == -1)
			return (NULL);
		printf("[%d]\tPhilosopher |%d| has taken a fork\n", g_time.clock - g_time.start, philo->id);
	}
	return ("done");
}

void	ft_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork.lock);
	pthread_mutex_unlock(&philo->n_fork->lock);
}
