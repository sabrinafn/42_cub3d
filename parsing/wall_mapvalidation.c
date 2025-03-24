/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:38:13 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/24 14:28:17 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int validate_wall(char **file_matrix)
{
	int cols;
	int i;
	
	cols = find_map(file_matrix);
	i = 0;
	while(file_matrix[cols] != NULL)
	{
		i = 0;
		while(file_matrix[cols][i] != '\0')
		{
			if(file_matrix[cols][i] == '0'
			|| ft_strchr("NSEW", file_matrix[cols][i]))
			{
				if(!check_wall(file_matrix, cols, i))
					return(0);
			}
			i++;	
		}
		cols++;	
	}
	return(1);
}

int check_wall(char **matrix, int cols, int i)
{
	
	if(i == 0)
		return(0);
	else if(cols == 0 || !matrix[cols + 1])
		return(0);
	else if(matrix[cols][i + 1] == ' '
		|| matrix[cols][i - 1] == ' '
		|| matrix[cols + 1][i] == ' '
		|| matrix[cols - 1][i] == ' ')
		return(0);
	else if(matrix[cols][i + 1] == '\n'
	|| matrix[cols + 1][i] == '\n'
	|| matrix[cols - 1][i] == '\n')	
		return(0);
	else if(matrix[cols][i + 1] == '\0'
	|| matrix[cols + 1][i] == '\0'
	|| matrix[cols - 1][i] == '\0')
		return(0);
	return(1);		
}



int empty_line(char **file_matrix)
{
	int cols;
	int i;

	cols = find_map(file_matrix);
	while(file_matrix[cols] != NULL)
	{
		i = walk_spaces(file_matrix[cols]);
		if(i > 1 && file_matrix[cols][i] == '\0')
			return (0);
		if(file_matrix[cols][i] == '\0')
			break ;
		cols++;	
	}
	while(file_matrix[cols] != NULL)
	{
		i = walk_spaces(file_matrix[cols]);
		if(file_matrix[cols][i] != '\0')
			return(0);
		cols++;	
	}
	return(1);
}
