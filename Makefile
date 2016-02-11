.PHONY: all, clean, fclean, re

NAME = fillit
LIBFT = libft.a
SRC_NAME = 	main.c 					\
			get_tetriminos.c 		\
			get_tetriminos2.c 		\
			resolver.c 				\
			print_map.c 			\
			error.c 				\
			add.c 					\
			check.c 				\
			check2.c 				\
			check_tetrimino.c 		\
			read_file.c 			\
			search.c 				\
			function.c 				\

OBJ_PATH = obj
SRC_PATH = srcs

CFLAGS = -Wall -Wextra -Werror

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@gcc -Llibft $(OBJ) -lft -o $(NAME)
	@echo "\033[32mCompiling" [ $(NAME) ]"\033[0m"

$(LIBFT):
	@make -C ./libft/

$(addprefix $(OBJ_PATH)/, %.o): $(addprefix $(SRC_PATH)/, %.c)
	@mkdir -p $(OBJ_PATH)
	@gcc $(CFLAGS) -o $@ -c $^
	@echo "\033[33mLinking" [ $< ] "\033[0m"

clean:
	@rm -fv $(OBJ)
	@rmdir -p $(OBJ_PATH) 2> /dev/null || true
	@make clean -C ./libft/
	@echo "\033[31mCleaning" [ $(NAME) ] "...\033[0m"

fclean: clean
	@rm -fv $(NAME)
	@make fclean -C ./libft/
	@echo "\033[31mDelete" [ $(NAME) ] "\033[0m"

re: fclean all