# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 18:38:48 by mgonzaga          #+#    #+#              #
#    Updated: 2025/03/30 17:20:42 by sabrifer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D

CC := cc

C_FLAGS := -g3 -Wall -Wextra -Werror

MLX_FLAGS = -lm -ldl -pthread -lglfw

LIBFT_DIR := ./libft

LIBFT := libft/libft.a

MLXLIB := MLX42/build/libmlx42.a

FILES := main.c \
		01.parsing/01.check_argv.c 01.parsing/02.read_argv.c 01.parsing/03.map_validation.c \
		01.parsing/04.parsing_content.c 01.parsing/05.character_mapvalidation.c \
		01.parsing/06.player_mapvalidation.c 01.parsing/07.wall_mapvalidation.c 01.parsing/08.utils.c \
		02.get_content/01.init_map.c 02.get_content/02.get_info.c 02.get_content/03.get_info_map.c \
		02.get_content/04.get_info_utils.c \
		03.init_game/01.init_game.c 03.init_game/02.init_structs.c 03.init_game/03.init_player_struct.c \
		03.init_game/04.init_mlx.c 03.init_game/05.init_pixels.c 03.init_game/06.cleanup_cub3d.c \
		04.moves/01.key_hooks.c 04.moves/02.key_hooks.c \
		05.rays_and_walls/01.calculate_rays.c 05.rays_and_walls/02.wall_calculations.c \
		05.rays_and_walls/03.wall_colours.c

OBJ := $(FILES:.c=.o)

all: $(MLXLIB) $(LIBFT) $(NAME)

%.o: %.c 
	@$(CC) $(C_FLAGS) -c $< -o $@ > /dev/null 2>&1

$(LIBFT): 
	@make -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "Compiling libft..."

$(MLXLIB):
	@cmake -S MLX42 -B MLX42/build > /dev/null 2>&1
	@make -j4 -C MLX42/build > /dev/null 2>&1
	@echo "Compiling mlx42..."

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(C_FLAGS) $(OBJ) $(MLXLIB) $(LIBFT) $(MLX_FLAGS) -o $(NAME) > /dev/null 2>&1
	@echo "Compiling cub3D..."
	@$(MAKE) -s print_message

clean: 
	@rm -f $(OBJ) > /dev/null 2>&1
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@echo "Cleaning cub3D object files..."
	@echo "Cleaning libft object files..."

fclean: clean
	@rm -f $(NAME) > /dev/null 2>&1
	@make -C $(LIBFT_DIR) fclean  > /dev/null 2>&1
	@rm -rf MLX42/build > /dev/null 2>&1
	@echo "Cleaning cub3D..."
	@echo "Cleaning libft directory..."
	@echo "Cleaning mlx42/build directory..."

print_message:
	@echo "----------------------------------------"
	@echo "|                                      |"
	@echo "|       Program Fully Compiled!        |"
	@echo "|                                      |"
	@echo "----------------------------------------"


re: fclean all

.PHONY: all fclean clean re print_message

# compile with suppression file:
# valgrind --leak-check=full --suppressions=mlx.sup ./cub3D [map]
