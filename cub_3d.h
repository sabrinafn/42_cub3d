/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:44:46 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/23 15:44:17 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <math.h>
# define ERROR_1 "Impossible to read the file\n"
# define ERROR_2 "Empty File\n"
# define ERROR_3 "Invalid malloc\n"
# define ERROR_4 "Error: Not enough params!\n"
# define ERROR_5 "Error: Too many params!\n"
# define ERROR_6 "Error: The file need be .cub\n"
# define ERROR_7 "Invalid Numbers Elements\n"
# define ERROR_8 "Invalid Elements\n"
# define ERROR_9 "Wrong color number\n"
# define ERROR_10 "Invalid taxture\n"
# define ERROR_11 "Invalid player in map\n"
# define ERROR_12 "Invalid Wall in map\n"
# define ERROR_13 "Invalid Character in map\n"
# define ERROR_14 "Empty line in map\n"




# define WIDTH 800
# define HEIGHT 800
# define MOVE_SPEED 0.1
# define ROTATION_SPEED 0.1

typedef struct s_position
{
	char	direction;
	int 	x;
	int		y;
} 	t_position;

typedef struct s_args
{
	char	**matrix;
	char	*name_file;
	int		countcols;
	int		map_position;
}			t_args;
/*
typedef struct s_args
{
	char	*NO_wall;
	char	*SO_wall;
	char	*WE_wall;
	char	*EA_wall;
	char	*ceiling; // uint
	char	*floor; // uint
	char	**map;
	int		map_max_x;
	int		map_max_y;
}			t_args;
*/
typedef struct s_content
{
	char		**map;
	char		*NO_path;
	char		*SO_path;
	char		*WE_path;
	char		*EA_path;
	char		**color_C;
	char		**color_F;
	uint32_t	ceiling;
	uint32_t	floor;
	int			map_max_x; // value to store height size
	int			map_max_y; // value to store width size
}			t_content;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		hit;
}			t_ray;

typedef struct s_textures
{
	mlx_texture_t	*NO_path;
	mlx_texture_t	*SO_path;
	mlx_texture_t	*WE_path;
	mlx_texture_t	*EA_path;
}	t_textures;

typedef struct s_game
{
	t_ray		*ray_struct;
	t_player	*player_struct;
	t_content	*map_struct;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_textures	*textures;
}	t_game;

int			check_arguments(int argc, char *argv);
int			check_name(char *argv);
int			print_error(char *e);
int			countcols(char *file_name);
char		**makematrix(char *file_name, int count_cols);
int			read_content(t_args *s_map);
int			empty_file(char *argv);
int			validate_map(t_args *s_map);
int			only_player(char *string);
int			find_player(t_args *s_map);
int			invalid_character(t_args *s_map, int cols);
int			validate_wall(t_args *s_map);
int			check_wall(char **matrix, int cols, int i);
int			size_map(t_args *s_map);
int			walk_spaces(char *string);
void		free_matrix(char **malloc_string);
int			validate_content(t_args *s_map);
int			validate_element(char *matrix_line, int line_number);
int			check_elements(char **matrix);
int			validate_numbers(char **matrix);
int			texture_path(char **matrix);
int			empty_line(t_args *s_map);
char	 *get_string(char *string, int count);
int	get_map_sizes_y(t_content *s_content);
int get_map_sizes_x(t_content *s_content);

// init_game
void		init_game(t_game *game);
void		render_raycast_frame(t_game *game);

// init_mlx
int	init_window(t_game *game);
mlx_image_t	*init_img(t_game *game);
t_textures	*init_textures(t_game *game);

// init_structs
int	init_structs_in_game(t_game *game);
void	draw_ceiling_and_floor(t_game *game);
int	get_rgba(int r, int g, int b, int a);

// init player_struct
t_player	*init_player_struct(t_content *map);
t_args		*init_map_struct(void);

// player movements
void	move_player_w(t_game *game);
void	move_player_s(t_game *game);
void	move_player_a(t_game *game);
void	move_player_d(t_game *game);
void	move_player_vision_left(t_game *game);
void	move_player_vision_right(t_game *game);

// calculate_rays
void	init_ray_pos_and_dir(int x, t_ray *ray, t_player *player);
void	init_delta_distance(t_ray *ray);
void	init_step_and_sidedist(t_ray *ray, t_player *player);
void	perform_dda(t_ray *ray, t_content *map);
void	calculate_rays(int x, t_game *game);
int		get_info(t_args *s_map, t_content *s_content);
int find_map(t_args *s_map);
void 	get_color_number(t_content *s_content);

// wall_calculations.c
void	get_wall_height(t_ray *ray);
void	draw_walls(int x, t_game *game);

// key_hooks.c
void	key_pressed_function(mlx_key_data_t keydata, void *param);

void	draw_walls_with_texture(int x, t_game *game);

#endif