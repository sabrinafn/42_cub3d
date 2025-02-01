/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:38:13 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/02/01 17:55:58 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int valide_wall(t_map s_map)
{
	int cols;
	int i;
	
	cols = s_map.map_position;
	i = 0;
	while(s_map.matrix[cols] != NULL)
	{
		i = 0;
		while(s_map.matrix[cols][i] != '\0')
		{
			if(s_map.matrix[cols][i] == '0'
			|| ft_strchr("NSEW", s_map.matrix[cols][i]))
			{
				if(check_wall(s_map.matrix, cols, i))
				return(1);
			}
			i++;	
		}
		cols++;	
	}
	return(0);
}

int check_wall(char **matrix, int cols, int i)
{
	if(i == 0)
		return(1);
	else if(cols == 0 || !matrix[cols + 1])
		return(1);
	else if(matrix[cols][i + 1] == ' '
		|| matrix[cols][i - 1] == ' '
		|| matrix[cols + 1][i] == ' '
		|| matrix[cols - 1][i] == ' ')
		return(1);
	else if(matrix[cols][i + 1] == '\n'
	|| matrix[cols + 1][i] == '\n'
	|| matrix[cols - 1][i] == '\n')	
		return(1);
	else if(matrix[cols][i + 1] == '\0'
	|| matrix[cols + 1][i] == '\0'
	|| matrix[cols - 1][i] == '\0')
		return(1);
	return(0);		
}

int size_map(t_map s_map)
{
	int i;
	int count;

	count = 0;
	if((s_map.countcols - s_map.map_position) < 9)
		return(1);
	i = walk_spaces(s_map.matrix[0]);
	while(s_map.matrix[s_map.map_position][i] != '\0')
	{
		count++;
		i++;
	}
	if(count < 9)
		return(1);
	return(0);		
}

int empy_line(t_map s_map)
{
	int cols;
	int i;

	cols = s_map.map_position;
	while(s_map.matrix[cols] != NULL)
	{
		i = walk_spaces(s_map.matrix[cols]);
		if(i > 1 && s_map.matrix[cols][i] == '\0')
			return (1);
		if(s_map.matrix[cols][i] == '\0')
			break ;
		cols++;	
	}
	while(s_map.matrix[cols] != NULL)
	{
		i = walk_spaces(s_map.matrix[cols]);
		if(s_map.matrix[cols][i] != '\0')
			return(1);
		cols++;	
	}
	return(0);
}
