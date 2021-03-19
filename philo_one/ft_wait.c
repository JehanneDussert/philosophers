#include "philo_one.h"

void    ft_wait(long int ms)
{
	long int start;

	start = ft_gettime();
	while (ft_gettime() - start < ms)
		usleep(100);
}

void	*ft_lock_forks(t_philo *philo)
{
	if ((g_time.clock = ft_gettime()) == -1 || !g_time.dead || !ft_dead(philo))
		return (NULL);
	printf("1 %d %d\n", g_time.dead, ft_dead(philo));
	if (philo->id % 2 && g_time.dead && ft_dead(philo))
	{
		pthread_mutex_lock(&philo->fork.lock);
		printf("[%d]\tPhilosopher |%d| has taken a fork\n", g_time.clock - g_time.start, philo->id);
	}
	printf("2 %d %d\n", g_time.dead, ft_dead(philo));
	if ((g_time.clock = ft_gettime()) == -1 || !g_time.dead || !ft_dead(philo))
		return (NULL);
	printf("3 %d %d\n", g_time.dead, ft_dead(philo));
	if (g_time.dead && ft_dead(philo))
	{
		printf("la 4 %d %d\n", g_time.dead, ft_dead(philo));
		pthread_mutex_lock(&philo->n_fork->lock);
		printf("[%d]\tPhilosopher |%d| has taken a fork\n", g_time.clock - g_time.start, philo->id);
	}
	if ((g_time.clock = ft_gettime()) == -1 || !g_time.dead || !ft_dead(philo))
		return (NULL);
	printf("end\n");
	printf("5 %d %d\n", g_time.dead, ft_dead(philo));
	if (!(philo->id % 2) && g_time.dead && ft_dead(philo))
	{
		pthread_mutex_lock(&philo->fork.lock);
		printf("[%d]\tPhilosopher |%d| has taken a fork\n", g_time.clock - g_time.start, philo->id);
	}
	printf("out\n");
	return (NULL);
}

void	ft_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork.lock);
	pthread_mutex_unlock(&philo->n_fork->lock);
}
