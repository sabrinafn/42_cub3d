/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:46:07 by izanoni           #+#    #+#             */
/*   Updated: 2025/01/25 20:29:57 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int	alloc_maps_elements(t_map *map, char **splited)
{
	if (ft_strncmp(splited[0], "NO", 2) == 0)
		map->no_texture = ft_strdup(split_line[1]);
	else if (ft_strncmp(splited[0], "SO", 2) == 0)
		map->so_texture = ft_strdup(split_line[1]);
	else if (ft_strncmp(splited[0], "WE", 2) == 0)
		map->we_texture = ft_strdup(split_line[1]);
	else if (ft_strncmp(splited[0], "EA", 2) == 0)
		map->ea_texture = ft_strdup(split_line[1]);
	else if (ft_strncmp(splited[0], "F", 1) == 0)
		map->f_color = ft_strdup(split_line[1]);
	else if (ft_strncmp(splited[0], "C", 1) == 0)
		map->c_color = ft_strdup(split_line[1]);
	else
		return(-1);
	return (0);
}

int	check_maps_elements(t_map *map, char **matriz_malloc)
{
	char 		**split_line;
	int			line;
	int			match;

		
	match = 0;
	line = 0;
	while (match < 6)
	{
		if (matriz_malloc[line][0] == '\n')
			line++;
		else
		{
			split_line = ft_split(matriz_malloc[i], ' ');
			
			if (ft_strncmp(&matriz_malloc[line][0], "NO", 2) == 0)
				match++;
			
			free(split_line);
			line++;
		}
	}
	
}
int	validate_element (t_map *map, char **splited)
{
	static char *w_f_c[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
	static char *element[6] = {"NO", "WE", "SO", "EA", "F", "C"};

	i = 0;
	
	if (ft_strncmp(splited[0], "NO", 2) == 0 && w_f_c[0] == NULL)
		w_f_c [0] = splited[1];
	else if (ft_strncmp(splited[0], "WE", 2) == 0 && w_f_c[1] == NULL)
		w_f_c [1] = splited[1];
	else if (ft_strncmp(splited[0], "SO", 2) == 0 && w_f_c[2] == NULL)
		w_f_c [2] = splited[1];
	else if (ft_strncmp(splited[0], "AE", 2) == 0 && w_f_c[3] == NULL)
		w_f_c [3] = splited[1];
	else if (ft_strncmp(splited[0], "F", 1) == 0 && w_f_c[4] == NULL)
		w_f_c [4] = splited[1];
	else if (ft_strncmp(splited[0], "C", 1) == 0 && w_f_c[5] == NULL)
		w_f_c [5] = splited[1];
	
}

" " "\n" NO WE SO EA F C