/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:44:46 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/02/26 13:52:07 by sabrifer         ###   ########.fr       */
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

# define WIDTH 1200
# define HEIGHT 1200

typedef struct s_args
{
	char	**matrix;
	char	*name_file;
	int		countcols;
	int		map_position;
}			t_args;

/*typedef struct s_map
{
	char	*NO_wall;
	char	*SO_wall;
	char	*WE_wall;
	char	*EA_wall;
	char	*ceiling;
	char	*floor;
	char	**map;
	int		map_max_x;
	int		map_max_y;
}			t_map;*/

typedef struct s_content
{
	char	**map;
	char	*NO_path;
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
	char	*color_C;
	char	*color_F;
	int		map_max_x; // value to store height size
	int		map_max_y; // value to store width size
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
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}			t_ray;

int			check_arguments(int argc, char *argv);
int			check_name(char *argv);
int			print_error(char *e);
int			countcols(char *file_name);
char		**makematrix(char *file_name, int count_cols);
int			read_content(char *file_name, t_args *s_map);
int			empty_file(char *argv);
int			find_map(t_args *s_map);
int			find_map2(t_args *s_map);
int			validate_map(t_args s_map);
int			only_player(char *string);
int			find_player(t_args s_map);
int			invalid_character(t_args s_map, int cols);
int			validate_wall(t_args s_map);
int			check_wall(char **matrix, int cols, int i);
int			size_map(t_args s_map);
int			walk_spaces(char *string);
void		free_matrix(char **malloc_string);
int			validate_content(t_args *s_map);
int			validate_element(char **matrix);
int			six_content(char **matrix);
int			validate_numbers(char **matrix);
int			texture_path(char **matrix);
int			empty_line(t_args s_map);

// init window
void		init_window(t_player *player, t_content *map);

// init player_struct
int			init_player_struct(t_player *player);
t_content	*init_content_struct(char *path);

int			get_content(t_args *s_map, t_content *s_content);
int 		get_color(char **matrix, t_content *s_content);
int 		get_texture_path(char **matrix, t_content *s_content);
int 		malloc_path(char *path, char *temp);

int		get_info(t_args *s_map, t_content *s_content);

#endif
