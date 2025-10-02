NAME := cub3D

CC := cc

C_FLAGS := -Wall -Wextra -Werror

MLX_FLAGS = -lm -ldl -pthread -lglfw
MLX_LIB := ./MLX42/build/libmlx42.a

LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

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

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(C_FLAGS) $(OBJ) $(MLX_LIB) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# Run with Valgrind:
# valgrind --leak-check=full --suppressions=mlx.sup ./cub3D [map]

.PHONY: all clean fclean re
