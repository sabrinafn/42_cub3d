/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:00:09 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/20 19:08:54 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int get_texture_path(char **matrix, t_content *s_content)
{
	int cols;
	int count;

	cols = 0;
	count = 0;

		while(matrix[cols] != NULL)
		{
				count = walk_spaces(matrix[cols]);	
				if(matrix[cols][count] == 'N')
					s_content->NO_path = get_string(matrix[cols], count + 2);
				else if(matrix[cols][count] == 'S')
				s_content->SO_path = get_string(matrix[cols], count + 2);
				else if(matrix[cols][count] == 'E')
					s_content->EA_path = get_string(matrix[cols], count + 2);
				else if(matrix[cols][count] == 'W')
					s_content->WE_path = get_string(matrix[cols], count + 2);
			cols++;	
		}
	if(!s_content->EA_path || !s_content->NO_path || !s_content->SO_path || !s_content->WE_path)
		return(0);
	return(1);
}

char *get_string(char *string, int count)
{
	char *result;
	int i;

	i = 0;
	result = ft_calloc((ft_strlen(string)), sizeof(char));
	while (string[count] == ' ' || string[count] == '\t')
			count++;
	while (string[count] != '\0')
	{
		result[i] =  string[count];
		i++;
		count++;
	}
	return(result);
}

int get_color(char **matrix, t_content *s_content)
{
	int cols;
	int count;
	int i;

	i = 0;
	count = 0;
	cols = 0;
	while(matrix[cols] != NULL)
	{
			count = walk_spaces(matrix[cols]);	
			i = 0;
			if(matrix[cols][count] == 'F')
			{
				s_content->color_F = ft_calloc(4, sizeof(char *));
				while (matrix[cols][count] && (matrix[cols][count] < '0' || matrix[cols][count] > '9'))
					count++;
				while (matrix[cols][count] != '\0')
				{
					s_content->color_F[i] =  matrix[cols][count];
					i++;
					count++;
				}
			}
			else if(matrix[cols][count] == 'C')
			{
				s_content->color_C = ft_calloc(4, sizeof(char *));
				while (matrix[cols][count] && (matrix[cols][count] < '0' || matrix[cols][count] > '9'))
					count++;
				while (matrix[cols][count] != '\0')
				{
					if(matrix[cols][count] == ',')
					{
						count++;
						i++;		
					}
					s_content->color_C[i][] =  matrix[cols][count];
					i++;
					count++;
				}
			}
			cols++;	
	}
	if(!s_content->color_C || !s_content->color_F)
		return(print_error(ERROR_3));
	return(1);
}

void 	get_color_number(t_content *s_content)
{
	
}

int get_map(t_args *s_map, t_content *s_content)
{
	int i;
	int j;
	int lines_map;
	
	j = 0;
	i = 0;
	lines_map = 0;
	lines_map = s_map->map_position;
	s_content->map = malloc((lines_map + 1) * sizeof(char *));
	if(!s_content->map)
		return(print_error(ERROR_3));
	while (s_map->matrix[lines_map] != NULL)
	{
		i = ft_strlen(s_map->matrix[lines_map]);
		s_content->map[j] = malloc((i + 1) * sizeof(char));
		if(!s_content->map[j])
		{
			free_matrix(s_content->map);
			return(print_error(ERROR_3));
		}
		ft_strlcpy(s_content->map[j], s_map->matrix[lines_map], i);
		j++;
		lines_map++;
	}
	return(1);
}

void	get_map_sizes(t_args *s_map, t_content *s_content)
{
	int	i;

	i = 0;

	while (s_map->matrix[i])
		i++;
	s_content->map_max_y = i;
	if (s_content->map_max_y > 0)
	{
		i = 0;
		while (s_map->matrix[0][i])
			i++;
		s_content->map_max_x = i;
	}
}

int get_info(t_args *s_map, t_content *s_content)
{
	if(!get_map(s_map, s_content))
	{
		printf("error when creating map\n");
		return(0);
	}
	if(!get_color(s_map->matrix, s_content))
	{
		printf("error when creating color\n");
		return(0);
	}
	if(!get_texture_path(s_map->matrix, s_content))
	{
		printf("error when creating texture\n");
		return(0);
	}
	//get_map_sizes(s_map, s_content);
	return (1);
}
