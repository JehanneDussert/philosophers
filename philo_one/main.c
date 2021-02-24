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

void    ft_start(char **argv)
{
    t_philo	*philo;
    int     nb_philo;

	nb_philo = ft_atoi(argv[1]);
	philo = ft_calloc(nb_philo + 2, sizeof(t_philo *));
	if (!philo)
		return ;
	ft_init_philo(argv, philo);
    free(philo);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
        ft_putendl("[ERROR] Wrong number of arguments.");
    else
        ft_start(argv);
    return (0);
}