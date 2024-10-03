CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

NAME = push_swap

SRCS =	coordination.c \
		full_sort.c \
		location.c \
		pop.c \
		price.c \
		rotations.c \
		sort_checker.c \
		sort_three.c \
		setup.c \
		mainsort.c \
		libft_utils.c \
		location_utils.c \
		price_utils.c \
		rotations_utils.c \
		sort_three_utils.c \

OBJS = ${SRCS:.c=.o}

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
