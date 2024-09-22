# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes

# Name of the executable
NAME = push_swap

# Source files
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

# Object files
OBJS = ${SRCS:.c=.o}

# Clean up tool
RM = rm -f

# Rule to compile .c files into .o files
.c.o:
	${CC} ${CFLAGS} -c $< -o $@

# Build the executable
${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

# Default rule
all: ${NAME}

# Clean up object files
clean:
	${RM} ${OBJS}

# Clean up object files and executable
fclean: clean
	${RM} ${NAME}

# Rebuild the project
re: fclean all

# Phony rules to avoid issues with files named 'clean', 'fclean', or 'all'
.PHONY: all clean fclean re
