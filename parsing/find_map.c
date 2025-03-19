/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:25:28 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/19 19:16:37 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int walk_spaces(char *string)
{
	int i;

	i = 0;
	while(string[i] == ' ' || string[i] == '\n' || string[i] == '\t')
		i++;
	return(i);	
}

int	validate_char(char *string)
{
	int	i;

	i = 0;
	while(string[i] != '\0')
	{
		if(ft_strchr("0NSEW1 \n\t", string[i]) == NULL)
			return(0);
		i++;		
	}
	return(1);			
}

int	invalid_character(t_args *s_map, int cols)
{
	while(s_map->matrix[cols] != NULL)
	{
		if(!validate_char(s_map->matrix[cols]))
			return(0);
		cols++;	
	}
	return(1);	
}

