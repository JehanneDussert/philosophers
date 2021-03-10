#include "philo_one.h"

void	*ft_eat(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	return (0);
}

void	*ft_sleep(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	return (0);
}

void	*ft_think(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	return (0);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (time < philo->time_to_die)
	{
		pthread_create(&philo->thread, NULL, ft_eat, philo);
		pthread_join(&philo->thread, NULL);
		pthread_create(&philo->thread, NULL, ft_sleep, philo);
		pthread_join(&philo->thread, NULL);
		pthread_create(&philo->thread, NULL, ft_think, philo);
		pthread_join(&philo->thread, NULL);
	}
	return (0);
}
