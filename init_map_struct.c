/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:32:27 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/09 16:42:45 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

t_map	*init_map_struct(char *path)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));

	map->NO_wall = NULL;
	map->SO_wall = NULL;
	map->WE_wall = NULL;
	map->EA_wall = NULL;
	map->floor = NULL;
	map->ceiling = NULL;
	map->map_max_x = 8;
	map->map_max_y = 8;

	map->map = (char **)malloc(sizeof(char *) * 8);
	map->map[0] = ft_strdup("1111111\n");
	map->map[1] = ft_strdup("1001001\n");
	map->map[2] = ft_strdup("1010101\n");
	map->map[3] = ft_strdup("1000001\n");
	map->map[4] = ft_strdup("1000001\n");
	map->map[5] = ft_strdup("100N001\n");
	map->map[6] = ft_strdup("1111111\n");
	map->map[7] = NULL;

	return (map);
}
