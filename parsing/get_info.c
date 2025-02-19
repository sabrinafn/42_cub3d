/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:00:09 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/02/19 11:40:23 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"
void get_texture_path(char **matrix, t_content *s_content)
{
	int cols;
	char **temp;
	
	temp = NULL;
	cols = 0;
	while(matrix[cols] != NULL)
	{
		if(ft_strchr(matrix[cols], 'NWSE') != NULL) 
		{
			temp = ft_split(matrix[cols], ' ');
			if(ft_strchr(matrix[cols], 'N') != NULL)
				s_content->NO_path = temp[1];
			if(ft_strchr(matrix[cols], 'W') != NULL)
				s_content->WE_path = temp[1];	
			if(ft_strchr(matrix[cols], 'S') != NULL)
				s_content->SO_path = temp[1];
			if(ft_strchr(matrix[cols], 'E') != NULL)
				s_content->EA_path = temp[1];
			free_matrix(temp);
		}
		cols++;	
	}
}

void get_color(char **matrix, t_content *s_content)
{
		int cols;
	char **temp;
	
	temp = NULL;
	cols = 0;
	while(matrix[cols] != NULL)
	{
		if(ft_strchr(matrix[cols][0], 'FC') != NULL) 
			temp = ft_split(matrix[cols], ' ');
			if(ft_strchr(matrix[cols], 'F') != NULL)
				s_content->color_F = temp[1];
			if(ft_strchr(matrix[cols], 'C') != NULL)
				s_content->color_C = temp[1];
			free_matrix(temp);	
		}
		cols++;	
	}

void getmap(t_map s_map, t_content *s_content)
{
	int count;

	count = s_map.map_position;
	s_content->map = malloc((s_map.countcols + 1) * sizeof(char *));
	while (s_map.matrix[count] != NULL)
	{
		 
	}
}

