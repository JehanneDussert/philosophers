NAME = philo_three

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

SRCS = 

OBJS	= ${SRCS:.c=.o}

$(NAME)	:	${OBJS} 
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L

$(LIBFT_PATH)$(LIBFT): ${LIBFT_FILES}
	make all -C ${LIBFT_PATH}

${MINILIBX_PATH}${MINILIBX} : ${MINILIBX_FILES}
	make -C ${MINILIBX_PATH}

all : ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all

work : all clean