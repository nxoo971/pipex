SRCS	= 	ft_printf.c		extract_spec_info.c		accept.c		explain_specification.c	\
			algo_flag.c		precision.c				exec_integer.c	exec_octal.c			\
			exec_binary.c	exec_unsigned.c			exec_double.c	exec_string.c			\
			calc_len.c		operations.c			color.c			print.c

NAME	= libftprintf.a

INC		= -I ./

FLAGS	= -Wall -Werror -Wextra

OBJS	= ${SRCS:.c=.o}

DEPS	= ${SRCS:.c=.d}

%.o:%.c
		gcc ${FLAGS} -c $< -o $@ ${INC} -MMD

all : ${NAME}

${NAME} : ${OBJS}
		make -C ./libft/ any
		cp libft/libft.a $(NAME)
		ar rcs ${NAME} ${OBJS}

clean :
		rm -rf ${OBJS} ${DEPS}

fclean : clean
		rm -rf ${NAME}

re : fclean all

.PHONY : all bonus clean fclean re

-include: ${DEPS}