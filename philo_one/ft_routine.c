#include "philo_one.h"

int	ft_eat(t_philo *philo)
{
	if ((g_time.clock = ft_gettime()) == -1)
		return (-1);
	printf("[%d]\tPhilosopher |%d| is eating\n", g_time.clock - g_time.start, philo->id);
	philo->nb_of_meal_eat++;
	philo->last_meal = g_time.clock;
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	if ((g_time.clock = ft_gettime()) == -1)
		return (-1);
	printf("[%d]\tPhilosopher |%d| is sleeping\n", g_time.clock - g_time.start, philo->id);
	return (0);
}

int	ft_think(t_philo *philo)
{
	if ((g_time.clock = ft_gettime()) == -1)
		return (-1);
	printf("[%d]\tPhilosopher |%d| is thinking\n", g_time.clock - g_time.start, philo->id);
	return (0);
}

int		ft_dead(t_philo	*philo)
{
	if (g_time.clock - g_time.start < g_time.time_to_die)
		return (1);
	else if (philo->nb_of_meal_eat <= philo->nb_of_meal || philo->nb_of_meal == 0)
		return (2);
	printf("out\n");
	return (0);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (ft_dead(philo))
	{
		printf("philo id lo :%d\n", philo->id);
		ft_lock_forks(philo);
		//if (ft_lock_forks(philo) == NULL)
		//	return (NULL);
		printf("philo id :%d\n", philo->id);
		ft_eat(philo);
		ft_wait();
		ft_unlock_forks(philo);
		ft_sleep(philo);
		ft_wait();
		ft_think(philo);
	}
	return (NULL);
}
