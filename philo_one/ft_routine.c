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
<<<<<<< HEAD
	if ((g_time.clock = ft_gettime()) == -1)
		return (0);
	printf("%d %d\n", philo->nb_of_meal_eat, philo->nb_of_meal);
	//printf("%d %d %d %d\n", g_time.clock, philo->last_meal, g_time.clock - philo->last_meal, g_time.time_to_die);
	if (philo->last_meal && g_time.clock - philo->last_meal > g_time.time_to_die)
		g_time.stop = 1;
	else if (philo->nb_of_meal_eat < philo->nb_of_meal || philo->nb_of_meal == 0)
=======
	if (philo->nb_of_meal_eat == philo->nb_of_meal && philo->nb_of_meal)
		return (1);
	else if (g_time.clock - g_time.start < g_time.time_to_die)
>>>>>>> correct_nb_meal
		return (2);
	else if (philo->nb_of_meal_eat < philo->nb_of_meal || philo->nb_of_meal == 0)
		return (3);
	return (1);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (ft_dead(philo) > 1)
	{
		printf("%d\n", ft_dead(philo));
		if (ft_lock_forks(philo) == NULL)
			return (NULL);
		ft_eat(philo);
		ft_wait(g_time.time_to_eat);
<<<<<<< HEAD
		if (ft_dead(philo) != 0)
			ft_unlock_forks(philo);
		if (ft_dead(philo) != 3)
=======
		ft_unlock_forks(philo);
		if (ft_dead(philo) > 1)
>>>>>>> correct_nb_meal
		{
			ft_sleep(philo);
			ft_wait(g_time.time_to_sleep);
			ft_think(philo);
		}
	}
	return (NULL);
}
