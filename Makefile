SRCS		=	main.c list.c get_path.c parse.c exec.c file.c free.c print.c
OBJS		=	$(SRCS:.c=.o)
DEPS		=	$(SRCS:.c=.d)

SRCS_BONUS	=	$(addprefix bonus/, main.c list.c get_path.c parse.c exec.c file.c free.c print.c)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
DEPS_BONUS	=	$(SRCS_BONUS:.c=.d)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3 -MMD -MP
INCLUDE		=	-I include
PIPEX		=	pipex
LIBS		=	libft/libft.a
RM			=	rm -rf

${PIPEX}:	${OBJS}
			make -C libft
			${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${PIPEX}

all:	${PIPEX}

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

bonus:	${OBJS_BONUS}
		make -C libft
		${CC} ${CFLAGS} ${OBJS_BONUS} ${LIBS}  -o ${PIPEX}

clean:
		${RM} ${OBJS}
		${RM} ${OBJS_BONUS}
		${RM} ${DEPS}
		${RM} ${DEPS_BONUS}

fclean:	clean
		${RM} ${PIPEX}
		make fclean -C libft/

re:		fclean all

-include ${DEPS}

.PHONY: all clean fclean re