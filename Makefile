NAME = Push_swap

SRC_PATH = ./srcs
OBJ_DIR = ./objs

SRCS =	$(SRC_PATH)/coordination.c \
		$(SRC_PATH)/full_sort.c \
		$(SRC_PATH)/location.c \
		$(SRC_PATH)/price.c \
		$(SRC_PATH)/sort_checker.c \
		$(SRC_PATH)/sort_three.c \
		$(SRC_PATH)/mainsort.c \
		$(SRC_PATH)/location_utils.c \
		$(SRC_PATH)/price_utils.c \
		$(SRC_PATH)/sort_three_utils.c \
		$(SRC_PATH)/moves/pop.c \
		$(SRC_PATH)/lib/free_utils.c \
		$(SRC_PATH)/lib/ft_split.c \
		$(SRC_PATH)/lib/join_args.c \
		$(SRC_PATH)/lib/libft_utils.c \
		$(SRC_PATH)/parser/setup.c \
		$(SRC_PATH)/moves/simple_rotations.c \
		$(SRC_PATH)/moves/double_rotations.c \

OBJ = $(SRCS:$(SRC_PATH)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re