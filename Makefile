# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 15:07:21 by mevangel          #+#    #+#              #
#    Updated: 2023/11/23 20:46:37 by mevangel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-lglfw -L "$(HOME)/.brew/opt/glfw/lib/"

GREEN	=	\033[0;32m
CYAN	=	\033[0;36m
WHITE	=	\033[0m

SRC_DIR	=	./srcs/
OBJ_DIR	=	./objs/

SRC		=	$(SRC_DIR)main.c \
			$(SRC_DIR)parsing.c \
			$(SRC_DIR)init_game.c
OBJ		=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIB		=	my_lib/my_lib.a
MLX42	=	MLX42/build/libmlx42.a

$(NAME): $(MLX42) $(OBJ)
		@cd my_lib && make
		@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(MLX42) $(OBJ) $(LIB)
		@echo "$(GREEN)so_long compiled!$(WHITE)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(MLX42):
	@if [ ! -d "./MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	# @make --silent -C MLX42
	@cd MLX42 && cmake -B build
	@cd MLX42 && cmake --build build -j4

all:	$(MLX42) $(NAME)

cleanmlx:
		@rm -rf MLX42
		@echo "$(CYAN)MLX42 folder is deleted!$(WHITE)"
		
clean:	
		@cd my_lib && make clean
		@rm -rf $(OBJ_DIR)
		@echo "$(CYAN)object files cleaned!$(WHITE)"

fclean:	
		@cd my_lib && make clean
		@rm -rf $(OBJ_DIR)
		@cd my_lib && make fclean
		@rm -f $(NAME)
		@echo "$(CYAN)Executable and object files cleaned!$(WHITE)"

cleanEverything:
		@rm -rf MLX42
		@cd my_lib && make clean
		@rm -rf $(OBJ_DIR)
		@cd my_lib && make fclean
		@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re