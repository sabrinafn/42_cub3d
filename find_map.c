/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:25:28 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/01/26 11:35:40 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int walk_spaces(char *string)
{
	int i;

	i = 0;
	while(string[i] == ' ' || string[i] == '\n')
		i++;
	return(i);	
}
int find_map(t_map s_map)
{
	int cols;
	int line;
	int count;

	cols = 0;
	line = 0;
	count = 0;	
	while(s_map.matrix[cols] != NULL)
	{
		if(count == 6)
			break;
		line = walk_spaces(s_map.matrix[cols]);
		if(s_map.matrix[cols][line] == '\0' || s_map.matrix[cols][line] == '\n')
			cols++;
		else
		{
			cols++;
			count++;
		}
	}
	return(cols);
}
int find_map2(t_map s_map)
{
	int cols;
	int line;

	cols = find_map(s_map);
	while(s_map.matrix[cols] != NULL)
	{	
		line = walk_spaces(s_map.matrix[cols]);
		if(s_map.matrix[cols][line] == '\0')
			cols++;
		else	
			break;	
	}
	return(cols);
}
int	valide_char(char *string)
{
	int	i;

	i = 0;
	while(string[i] != '\0')
	{
		if(ft_strchr("0NSEW1 \n", string[i]) == NULL)
			return(1);
		i++;		
	}
	return(0);			
}

int	invalid_character(t_map s_map, int cols)
{
	while(s_map.matrix[cols] != NULL)
	{
		if(valide_char(s_map.matrix[cols]) == 1)
			return(1);
		cols++;	
	}
	return(0);	
}

