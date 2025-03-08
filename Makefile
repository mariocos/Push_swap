NAME = Push_swap

SRC_PATH = ./srcs
OBJ_DIR = ./objs

SRCS =	$(SRC_PATH)/coordination.c \
		$(SRC_PATH)/full_sort.c \
		$(SRC_PATH)/location.c \
		$(SRC_PATH)/pop.c \
		$(SRC_PATH)/price.c \
		$(SRC_PATH)/rotations.c \
		$(SRC_PATH)/sort_checker.c \
		$(SRC_PATH)/sort_three.c \
		$(SRC_PATH)/setup.c \
		$(SRC_PATH)/mainsort.c \
		$(SRC_PATH)/libft_utils.c \
		$(SRC_PATH)/location_utils.c \
		$(SRC_PATH)/price_utils.c \
		$(SRC_PATH)/rotations_utils.c \
		$(SRC_PATH)/sort_three_utils.c \
		$(SRC_PATH)/special_case.c \
		$(SRC_PATH)/special_case_utils.c \

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