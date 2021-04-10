NAME = philo_three

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread -g

SRCS = main.c ft_utils.c ft_print.c ft_routine.c ft_wait.c ft_clean.c ft_init.c

OBJS	= ${SRCS:.c=.o}

$(NAME)	:	${OBJS} 
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all : ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all

work : all clean