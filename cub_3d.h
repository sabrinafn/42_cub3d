/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:44:46 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/02/17 16:13:44 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# define ERROR_1 "Impossible to read the file\n"
# define ERROR_2 "Empty File\n"
# define ERROR_3 "Invalid malloc\n"

# define WIDTH 800
# define HEIGHT 600

typedef struct s_map
{
	char	**matrix;
	char	*name_file;
	int		countcols;
	int		map_position;
}			t_map;

typedef struct s_args
{
	char	*NO_wall;
	char	*SO_wall;
	char	*WE_wall;
	char	*EA_wall;
	char	*ceiling;
	char	*floor;
	char	**map;
}			t_args;

int			check_arguments(int argc, char *argv);
int			check_name(char *argv);
int			print_error(char *e);
int			countcols(char *file_name);
char		**makematrix(char *file_name, int count_cols);
int			read_content(char *file_name);
int			ampy_file(char *argv);
int			find_map(t_map s_map);
int			find_map2(t_map s_map);
int			validate_map(t_map s_map);
int			only_player(char *string);
int			find_player(t_map s_map);
int			invalid_character(t_map s_map, int cols);
int			valide_wall(t_map s_map);
int			check_wall(char **matrix, int cols, int i);
int			size_map(t_map s_map);
int			walk_spaces(char *string);
void		free_matrix(char **malloc_string);
int			valide_content(t_map s_map);
int			validate_element(char **matrix);
int			six_content(char **matrix);
int			valide_numbers(char **matrix);
int			texture_path(char **matrix);
int			empy_line(t_map s_map);
void		init_window(void);

#endif
