SRCS		=	srcs/making_b.c \
				srcs/parsing.c \
				srcs/pile_exodus.c \
				srcs/pile_genesis.c \
				srcs/pile_leviticus.c \
				srcs/push_swap.c \
				srcs/sort.c \

SRCS_BONUS	=	srcs/checker.c \
				srcs/making_b.c \
				srcs/parsing.c \
				srcs/pile_exodus.c \
				srcs/pile_genesis.c \
				srcs/pile_leviticus.c \
				srcs/sort.c \

OBJS		=	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

PUSH_SWAP	=	push_swap
CHECKER		=	checker

INCLUDE		=	-Iinclude
LIBS		=	libft/libft.a

CC			=	cc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -g3

.c.o:
				${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${PUSH_SWAP}:	${OBJS}
				make -C libft
				${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${PUSH_SWAP}

all:			${PUSH_SWAP}

bonus:			${OBJS_BONUS}
				make -C libft
				${CC} ${CFLAGS} ${OBJS_BONUS} ${LIBS} -o ${CHECKER}

clean:
				make clean -C libft
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
				make fclean -C libft
				${RM} ${PUSH_SWAP} ${CHECKER}

re:				fclean all

.PHONY: 		all clean fclean re
