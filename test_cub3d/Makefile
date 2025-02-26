# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 18:38:48 by mgonzaga          #+#    #+#              #
#    Updated: 2025/01/31 15:27:10 by mgonzaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT = libft/libft.a

FILES = main.c parsing/read_content.c parsing/find_map.c parsing/map_validation.c \
parsing/find_player.c parsing/wall_validation.c parsing/free_things.c parsing/parsing_content.c \
init_window.c

OBJ = $(FILES:%.c=%.o)
MLX_FLAGS = -lm -ldl -pthread -lglfw

all: mlx libft $(NAME) 
libft: 
	make all -C libft 
mlx:
	cmake -S MLX42 -B MLX42/build
	cmake -S MLX42 --build MLX42/build
	make -j4 -C MLX42/build
%.o: %.c 
	cc -g3 -Wall -Wextra -Werror  -c $< -o $@ 
$(NAME): $(OBJ) $(LIBFT)
	cc -g3 -Wall -Wextra -Werror $(OBJ) MLX42/build/libmlx42.a $(LIBFT) $(MLX_FLAGS) -o $(NAME)
fclean: clean
	rm -f $(NAME)
	make fclean -C libft
clean: 
	rm -f $(OBJ)
	make clean -C libft
	rm -f -r MLX42/build  
v: all
	valgrind --leak-check=full --show-leak-kinds=all $(NAME) $(FILES)
re: fclean all

.PHONY: all fclean clean re libft
