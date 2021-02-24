#include "philo_one.h"

void	ft_putendl(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

void    ft_print(int philo_id, char *action)
{
    printf("%d %s\n", philo_id, action);
}
