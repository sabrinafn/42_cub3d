# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 18:38:48 by mgonzaga          #+#    #+#              #
#    Updated: 2025/03/20 17:26:27 by sabrifer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D

CC := cc

C_FLAGS := -g3 -Wall -Wextra -Werror

MLX_FLAGS = -lm -ldl -pthread -lglfw

LIBFT_DIR := ./libft

LIBFT := libft/libft.a

FILES := main.c init_game.c init_player_struct.c calculate_rays.c \
		wall_calculations.c key_hooks.c

OBJ := $(FILES:.c=.o)

all: mlx $(LIBFT) $(NAME)

%.o: %.c 
	$(CC) $(C_FLAGS) -c $< -o $@ 

$(LIBFT): 
	make -C $(LIBFT_DIR) 

mlx:
	cmake -S MLX42 -B MLX42/build
	make -j4 -C MLX42/build

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(C_FLAGS) $(OBJ) MLX42/build/libmlx42.a $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean: 
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean 
	rm -rf MLX42/build

v: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

re: fclean all

.PHONY: all fclean clean re v mlx
