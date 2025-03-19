/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:32:30 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/19 19:45:21 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int only_player(char *string)
{
	int	i;
	int count;

	count = 0;
	i = 0;
	while(string[i] != '\0')
	{
		if(ft_strchr("NSEW", string[i]))
			count++;
		i++;		
	}
	return(count);	
}

int find_map(t_args *s_map)
{
	int lines_map;
	int count;

	lines_map = 0;
	count = 0;
	while(s_map->matrix[lines_map] != NULL)
	{
		count = walk_spaces(s_map->matrix[lines_map]);
		if (s_map->matrix[lines_map][count] == '1')	
			break;
		lines_map++;
	}
	return(lines_map);
}
int find_player(t_args *s_map)
{
	int cols;
	int	count;
	
	count = 0;
	cols = s_map->map_position;
	while(s_map->matrix[cols] != NULL)
	{
		count = count + only_player(s_map->matrix[cols]);
		cols++;
	}
	if(count > 1 || count == 0)
		return(0);
	return(1);
}

