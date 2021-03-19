#include "philo_one.h"

int	ft_eat(t_philo *philo)
{
	if ((g_time.clock = ft_gettime()) == -1)
		return (-1);
	if (!g_time.dead || !ft_dead(philo))
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
	if (!g_time.dead || !ft_dead(philo))
		return (-1);
	printf("[%d]\tPhilosopher |%d| is sleeping\n", g_time.clock - g_time.start, philo->id);
	return (0);
}

int	ft_think(t_philo *philo)
{
	if ((g_time.clock = ft_gettime()) == -1)
		return (-1);
	if (!g_time.dead || !ft_dead(philo))
		return (-1);
	printf("[%d]\tPhilosopher |%d| is thinking\n", g_time.clock - g_time.start, philo->id);
	return (0);
}

int		ft_dead(t_philo	*philo)
{
	if (philo->nb_of_meal_eat == philo->nb_of_meal && philo->nb_of_meal)
		return (0);
	else if (g_time.start + g_time.time_to_die < g_time.clock)
	{
		printf("enter\n");
		return ((g_time.dead = 0));
	}
	else if (philo->nb_of_meal_eat < philo->nb_of_meal || philo->nb_of_meal == 0)
		return (1);
	else if (g_time.start + g_time.time_to_die > g_time.clock)
		return (1);
	return (0);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (ft_dead(philo) && g_time.dead)
	{

		printf("1 end\n");
		if (!ft_dead(philo) || !g_time.dead || ft_lock_forks(philo) == NULL)
			return (NULL);
		printf("2 end\n");
		ft_eat(philo);
		printf("3 end\n");
		ft_wait(g_time.time_to_eat);
		ft_unlock_forks(philo);
		if (ft_dead(philo) && g_time.dead)
		{
			ft_sleep(philo);
			ft_wait(g_time.time_to_sleep);
			ft_think(philo);
		}
		if (!g_time.dead || !ft_dead(philo))
			return (NULL);
	}
	return (NULL);
}
