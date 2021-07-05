NAME = push_swap

SRC_DIR = srcs

SRC =	main.c \
		operations/swap.c \
		operations/push.c \
		operations/rotate.c \
		operations/rev_rotate.c \
		utils/lowest_nr_a.c \
		utils/highest_nr_a.c \
		sorters/small_sorters.c \
		sorters/five_sorter.c \
		sorters/big_sorter.c \
		utils/a_sorted.c \
		utils/init_stk.c \
		utils/ft_error.c \
		utils/chunker.c \
		utils/lowest_nr_b.c \
		utils/highest_nr_b.c \
		utils/clear_chnk.c \
		utils/ft_free_tab.c \
		utils/numeric.c \
		utils/tab_cnt.c \
		utils/duplicate_check.c \
		utils/ft_atol.c \
		utils/ft_split.c \

OBJ_DIR = objs


OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

HEADER_FOLDER = includes

CC = gcc

CFLAGS = -Werror -Wall -Wextra -I${HEADER_FOLDER} -g

RM = rm -rf


all:	$(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/operations
	@mkdir -p $(OBJ_DIR)/sorters
	@mkdir -p $(OBJ_DIR)/utils

$(NAME):	$(OBJ_DIR) $(OBJ)
	@echo "Making push_swap"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(HEADER)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files"
	@$(RM) $(OBJ) $(OBJ_DIR)

fclean:
	@echo "Removing object files"
	@$(RM) $(NAME) $(OBJ) $(OBJ_DIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
