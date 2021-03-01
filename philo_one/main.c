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

void    ft_time(void)
{
    int i = 0;
    struct timeval time_before;
    struct timeval time_after;
    gettimeofday(&time_before, NULL);
    while (i++ < 100)
    {
        gettimeofday(&time_after, NULL);
        printf("%ld\n", ((time_after.tv_sec - time_before.tv_sec) * 1000000 + time_after.tv_usec) - time_before.tv_usec);
    }
    gettimeofday(&time_after, NULL);
    printf("%ld\n\n", ((time_after.tv_sec - time_before.tv_sec) * 1000000 + time_after.tv_usec) - time_before.tv_usec);
    
}

void *thread_1(void *arg) 
{
    //printf("enter\n");
	printf("%s\n", arg);
	// Arrêt propre du thread
	pthread_exit(EXIT_SUCCESS);
}

void    ft_thread(void)
{
    pthread_t thread1;

	printf("Avant la création du thread.\n");
	// Création du thread
	pthread_create(&thread1, NULL, thread_1, thread1);
	printf("Après la création du thread.\n");

}

void    ft_start(char **argv)
{
    t_philo	**all_philo;
    int     nb_philo;
    int     i;

    i = -1;
	nb_philo = ft_atoi(argv[1]);
    all_philo = ft_calloc((nb_philo + 1), sizeof(*all_philo));
    while (++i < nb_philo)
    {
	    all_philo[i] = ft_calloc(nb_philo + 1, sizeof(t_philo));
	    ft_init_philo(argv, all_philo[i]);
    }
    all_philo[nb_philo] = NULL;
	if (!all_philo)
		return ;
    //ft_time();
    ft_thread();
    //free(philo);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
        ft_putendl("[ERROR] Wrong number of arguments.");
    else
        ft_start(argv);
    return (0);
}