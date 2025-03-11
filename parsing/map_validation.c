/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:34:53 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/11 18:51:58 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int validate_map(t_args **s_map)
{
	if(size_map(*s_map))
	{
		write(1, "Map size invalid\n", 19);	
		return(1);		
	}
	if(invalid_character(s_map, s_map.map_position) == 1)
	{
		write(1, "Invalid character in map\n", 24);
		return(1);
	}
	if(find_player(s_map) == 1)
	{
		write(1, "Invalid player\n", 15);	
		return(1);	
	}
	if(validate_wall(s_map))
	{
		write(1, "Invalid wall\n", 14);	
		return(1);
	}
	if(empty_line(s_map))
	{
		write(1, "Invalid Map\n", 14);	
		return(1);
	}
	return(0);
}

