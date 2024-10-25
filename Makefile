######### COLORS ########

GREEN = \x1B[32m
RED = \x1B[31m
RESET = \x1B[0m

######### FLAGS ########

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = libft

######### DIRECTORIES ########

SRC_DIR = srcs
OBJ_DIR = objs
INCLUDE_DIR = includes
# Add all include directories here
INCLUDE_DIRS = -I$(INCLUDE_DIR) -I$(LIBFT_PATH)/includes

######### FILES ########

SRC_FILES = $(SRC_DIR)/main.c \
            $(SRC_DIR)/exec/exec_cmds.c \
            $(SRC_DIR)/exec/exec_cmds_with_files.c \
            $(SRC_DIR)/exec/get_path_cmd.c \
            $(SRC_DIR)/exec/manages_fd_cmds.c \
            $(SRC_DIR)/parsing/get_cmds.c \
            $(SRC_DIR)/parsing/get_files_and_cmds_from_strs.c \
            $(SRC_DIR)/parsing/get_files.c \
            $(SRC_DIR)/parsing/make_here_doc.c \
            $(SRC_DIR)/utils/free_cmds.c \
            $(SRC_DIR)/utils/free_data.c \
            $(SRC_DIR)/utils/ft_strlen_cmd.c

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

######### LIBRARIES ########

LIBFT = $(LIBFT_PATH)/libft.a

######### NAME ########

NAME = pipex

######### COMMANDS ########

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	@echo -e "$(GREEN)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft 2>/dev/null
	@echo -e "$(GREEN)✓ $(NAME) successfully compiled!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@) 2>/dev/null
	@$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c -o $@ $< 2>/dev/null
	@printf "$(GREEN)█$(RESET)"

$(LIBFT):
	@echo -e "$(GREEN)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) >/dev/null 2>&1
	@echo -e "$(GREEN)✓ libft successfully compiled!$(RESET)"

clean:
	@echo -e "$(RED)Cleaning object files...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) clean >/dev/null 2>&1
	@rm -rf $(OBJ_DIR)
	@echo -e "$(RED)✓ Object files cleaned!$(RESET)"

fclean: clean
	@echo -e "$(RED)Removing executable...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) fclean >/dev/null 2>&1
	@rm -f $(NAME)
	@echo -e "$(RED)✓ Executable removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re