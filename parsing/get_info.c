/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:00:09 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/10 18:16:02 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int get_texture_path(char **matrix, t_content *s_content)
{
	int cols;
	char **temp;
	int valid;

	valid = 0;
	temp = NULL;
	cols = 0;
	while(matrix[cols] != NULL)
	{
		if(ft_strchr(matrix[cols], 'NWSE') != NULL) 
		{
			temp = ft_split(matrix[cols], ' ');
			if(ft_strchr(matrix[cols], 'N') != NULL)
				valid = malloc_path(s_content->NO_path,temp[1]);
			else if(ft_strchr(matrix[cols], 'W') != NULL)
				valid = malloc_path(s_content->WE_path, temp[1]);	
			else if(ft_strchr(matrix[cols], 'S') != NULL)
				valid = malloc_path(s_content->SO_path, temp[1]);
			else if(ft_strchr(matrix[cols], 'E') != NULL)
				valid = malloc_path(s_content->EA_path,temp[1]);
			free_matrix(temp);
			if(valid == 1)
				return(1);
		}
		cols++;	
	}
	return(0);
}

int malloc_path(char *path, char *temp)
{
	int count;

	count = ft_strlen(temp);
	path = malloc((count + 1) * sizeof(char));
	if(!path)
		return(1);
	ft_strlcpy(path, temp, count);	
	return(0);
}

int get_color(char **matrix, t_content *s_content)
{
	int cols;
	char **temp;

	temp = NULL;
	cols = 0;
	while(matrix[cols] != NULL)
	{
		if(ft_strchr(&matrix[cols][0], 'F') != NULL || ft_strchr(&matrix[cols][0], 'C') != NULL)
		{
			temp = ft_split(matrix[cols], ' ');
			if(ft_strchr(matrix[cols], 'F') != NULL)
			{
				s_content->color_F = malloc((ft_strlen(temp[1]) + 1) * sizeof(char));
				ft_strlcpy(s_content->color_F, temp[1], ft_strlen(temp[1]));
			}
			else if(ft_strchr(matrix[cols], 'C') != NULL)
			{
				s_content->color_C = malloc((ft_strlen(temp[1]) + 1) * sizeof(char));
				ft_strlcpy(s_content->color_C, temp[1], ft_strlen(temp[1]));
			}
			free_matrix(temp);
		}
		cols++;	
	}
	if(!s_content->color_C || !s_content->color_F)
		return(1);
	return(0);
}
	

int get_map(t_args *s_map, t_content *s_content)
{
	int count;
	int i;
	int j;
	int lines_map;
	
	j = 0;
	i = 0;
	lines_map = 0;
	count = s_map->map_position;
	while(s_map->matrix[count] != NULL)
	{
		lines_map++;
		count++;
	}
	s_content->map = malloc((lines_map + 1) * sizeof(char *));
	if(!s_content->map)
	{
		printf("return error - malloc - matrix s_content\n");
		return(1);
	}
	count = s_map->map_position;
	while (s_map->matrix[count] != NULL)
	{
		i = ft_strlen(s_map->matrix[count]);
		s_content->map[j] = malloc((i + 1) * sizeof(char));
		if(!s_content->map[j])
		{
			free_matrix(s_content->map);
			return(1);
		}
		ft_strlcpy(s_content->map[j], s_map->matrix[count], i);
		j++;
		count++;
	}
	return(0);
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
	printf("estou aqui2");
	if(get_map(s_map, s_content) == 1)
	{
		printf("error when creating map\n");
		return(1);
	}
	printf("estou aqui");
	if(get_color(s_map->matrix, s_content) == 1)
	{
		printf("error when creating color\n");
		return(1);
	}
	if(get_texture_path(s_map->matrix, s_content) == 1)
	{
		printf("error when creating texture\n");
		return(1);
	}
	get_map_sizes(s_map, s_content);
	return (0);
}
