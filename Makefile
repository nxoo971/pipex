SRCS	=	main.c		list.c		get_path.c		parse.c	\
			exec.c		file.c		free.c			print.c

NAME	= pipex

INC		= -I ./

#FLAGS	= -Wall -Werror -Wextra
FLAGS	= -g3

OBJS	= ${SRCS:.c=.o}

DEPS	= ${SRCS:.c=.d}

all : ${NAME}

${NAME} : ${OBJS}
		make -C ./ft_printf/libft/
		make -C ./ft_printf/
		gcc ${FLAGS} ${INC} $(OBJS) -o $(NAME) ft_printf/libftprintf.a

%.o:%.c
		gcc ${FLAGS} -c $< -o $@ -MMD

clean :
		make -C ./ft_printf/ clean
		make -C ./ft_printf/libft/ clean
		rm -rf ${OBJS} ${DEPS}

mclean :
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME}

re : fclean all

.PHONY : all bonus clean fclean re

-include: ${DEPS}