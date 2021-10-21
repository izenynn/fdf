# COLORS
NOCOL=\033[0m
RED=\033[1;31m
YEL=\033[1;33m
ORG=\033[0;33m
GRN=\033[1;32m
DGRAY=\033[1;30m
BLU=\033[1;34m

# NAMES
NAME = fdf

LIBFT_NAME = libft.a

# MAKE
MAKE = make

# COMPILER
CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFLAGS += -I ./$(LIBFT_DIR)/inc -I ./inc

LDFLAGS = -L $(LIBFT_DIR)

LDLIBS = -lft

LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

# PATHS
SRC_PATH = src
OBJ_PATH = obj
LIB_PATH = lib

# LIBS DIR

LIBFT_DIR = $(LIB_PATH)/libft

# SOURCES
SRC_FILES =		main.c		tab_utils.c		handle_args.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJ_FILES = $(SRC_FILES:%.c=%.o)

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_FILES))

.PHONY: all bonus clean fclean re norm

all: $(NAME) $(CHECKER_NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LDLIBS)

#TODO Minilibx

$(LIBFT):
	$(MAKE) all -sC $(LIBFT_DIR)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null

clean:
	$(MAKE) clean -sC $(LIBFT_DIR)
	rm -rf $(OBJ_PATH)

fclean: clean
	$(MAKE) fclean -sC $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

norm:
	@printf "\n${GRN}##########${YEL} NORMINETTE ${GRN}##########${NOCOL}\n"
	@printf "\n${GRN}LIBFT:${BLU}\n\n"
	@norminette $(LIBFT_DIR)
	@printf "\n${GRN}FDF:${BLU}\n\n"
	@norminette $(SRC_PATH)