SRCS		=	srcs/parsing.c \
				srcs/pile.c \
				srcs/push_swap.c \

OBJS		=	${SRCS:.c=.o}

PUSH_SWAP	=	push_swap

INCLUDE		=	-Iinclude
LIBS		=	libft/libft.a

CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -g3

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${PUSH_SWAP}:	${OBJS}
				make -C libft
				${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${PUSH_SWAP}

all:	${PUSH_SWAP}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${PUSH_SWAP}

re:		fclean all

.PHONY: all clean fclean re
