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

void    ft_init_thread(t_params *params)
{
	params->start = ft_gettime(params->time_start);
	printf("Start :%f\n", params->start);
	//while (!ft_is_dead(params))
	{
    	params->index = 0;
		ft_routine(params);
		params->index = 1;
		ft_routine(params);
	}
	printf("%f\tPhilosopher [%d] is dead\n", params->clock, params->index + 1);
}

/*void    ft_init_thread(t_params *params)
{
    //pthread_t	thread;
	//int			i;

	params->index = 0;
	gettimeofday(&params->start, NULL);
	ft_routine(params);
	params->index = 1;
	ft_routine(params);
	pthread_create(&thread, NULL, ft_wait, params);
	while (++i < params->nb_of_philo)
	{
		params->index = i;
		printf("i :%d\n", i);
		if (!i % 2)
		{
			ft_routine(params);
			//pthread_create(&thread, NULL, ft_routine, params);
			//pthread_join(params->philo->thread, NULL);
		}
		// dans le create on va prevoir si i % 2 ou si !i% 2 ou si !i % 2 && i == nb_philo
	}
	// un-mutex ?
	i = 0;
	while (++i < params->nb_of_philo)
	{
		params->index = i;
		if (i % 2)
		{
			ft_routine(params);
			//pthread_create(&thread, NULL, ft_routine, params);
			//pthread_join(params->philo->thread, NULL);
		}
	}
}*/

void    ft_start(char **argv)
{
    t_philo		*philo;
	t_params	params;
    int     nb_philo;
    int     i;

    i = -1;
	nb_philo = ft_atoi(argv[1]);
    philo = ft_calloc((nb_philo + 1), sizeof(*philo));
    if (!philo)
        return ;
	while (++i < nb_philo)
		ft_init_philo(argv, &philo[i], i);
	ft_init_params(&params, philo, argv);
	ft_init_thread(&params);
	//ft_clean(philo);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
        ft_putendl("[ERROR] Wrong number of arguments.");
    else
        ft_start(argv);
    return (0);
}