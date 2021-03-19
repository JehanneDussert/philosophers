#include "philo_one.h"

// Penser, manger, dormir. Une chose a la fois
// Un philo doit manger avec deux fourchettes
// Des qu'un philo a fini de manger, pose fourchettes et dort
// Apres avoir dormi, pense
// Mort d'un philo = end of prog

// time_to_die = nb de millisecondes qu'a philo entre 2 repas ou debut simulation 
// avant de mourir

// time_to_eat = temps qu'il prend pour manger et garde ses fourchettes

// time_to_sleep = temps que prend un philo a dormir

// number_of_each_philosophers_must_eat = optionnel, si philo ont tous mange 
// ce nb de fois, simulation s'arrete, si pas ce nb -> simulation s'arrete 
// des qu'un philo meurt

// Philo se voit assigne un numero de 1 a nb_of_philosopher

/*
Functions :

void * memset(void *b, int c, size_t len);
The memset() function writes len bytes of value c (converted to an unsigned char) to the string b.

int usleep(useconds_t microseconds);
The usleep() function suspends execution of the calling thread until either microseconds

int gettimeofday(struct timeval *restrict tp, void *restrict tzp);

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
-> demarre nouveau thread dans processus appelant, le thread commence par appeler fct start_routine, arg = son seul argument
-> se termine avec return (valeur a return)

 int pthread_detach(pthread_t thread);
 -> detacher un thread

*/

/*
    le mutex va me permettre de proteger les fourchettes pour que les philosophes ne se les volent pas
    il faudrait un thread / philosophe qui va permettre de realiser les actions :
    - prend les fourchettes
    - mange
    - dort
    - pense
    - meurt
    + afficher les millisecondes
*/

int		ft_check_meal(t_philo *philo)
{
	int i;

	i = -1;
	while (philo[++i].id < philo[0].nb_philo)
		if (!(philo[i].nb_of_meal_eat == philo[i].nb_of_meal))
			return (0);
	return (1);
}

void    ft_init_thread(t_philo **philo)
{
	int i;
	int n;

	i = -1;
	n = (*philo)[0].nb_philo - 1;
	if (gettimeofday(&g_time.time_start, NULL) == -1)
		return ;
	g_time.start = ft_gettime();
	while (++i <= n)
		if (!(i % 2))
			pthread_create(&(*philo)[i].thread, NULL, ft_routine, &(*philo)[i]);
	i = -1;
	usleep(500);
	while (++i <= n)
		if (i % 2)
			pthread_create(&(*philo)[i].thread, NULL, ft_routine, &(*philo)[i]);
	i--;
	pthread_join((*philo)[i].thread, NULL);
	if ((*philo)[i].nb_of_meal && ft_check_meal(*philo))
		return ;
	printf("[%d]\tPhilosopher |%d| is dead\n", g_time.clock - g_time.start, (*philo)[i].id);
}

void    ft_start(char **argv)
{
    t_philo		*philo;
	int			nb_philo;
	int			i;

	i = -1;
	nb_philo = ft_atoi(argv[1]);
	philo = ft_calloc((nb_philo), sizeof(*philo));
	if (!philo)
		return ;
	ft_init_philo(argv, &philo);
	ft_init_thread(&philo);
	ft_clean(&philo);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		ft_putendl("[ERROR] Wrong number of arguments.");
	else
		ft_start(argv);
	return (0);
}