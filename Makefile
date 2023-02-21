SRCS = main.c list.c get_path.c parse.c exec.c file.c free.c print.c
SRCS_B = $(addprefix bonus/, main.c list.c get_path.c parse.c exec.c file.c free.c print.c)
OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}
DEPS = ${SRCS:.c=.d}
DEPS_B = ${SRCS_B:.c=.d}
NAME = pipex
NAME_B = pipex_bonus
INC = -I ./
FLAGS = -g3 -Wall -Werror -Wextra

all : ${NAME}

${NAME} : ${OBJS}
	make -C ./libft/
	gcc ${FLAGS} ${INC} $(OBJS) -o $(NAME) libft/libft.a

%.o:%.c
	gcc ${FLAGS} -c $< -o $@ -MMD

bonus: ${NAME_B}

${NAME_B}: ${OBJS_B} libft/libft.a
	gcc ${FLAGS} ${INC} ${OBJS_B} -o ${NAME_B} libft/libft.a

-include ${DEPS} ${DEPS_B}

clean :
	make -C ./libft/ clean
	rm -rf ${OBJS} ${DEPS} ${OBJS_B} ${DEPS_B}

fclean : clean
	make -C ./libft/ fclean
	rm -rf ${NAME} ${NAME_B}

re : fclean all

.PHONY : all bonus clean fclean re