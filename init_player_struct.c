/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:32:27 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/20 14:40:15 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

t_position	*find_char(char **map, int map_height, int map_width)
{
	t_position	*pos;
	int			y;
	int			x;

	y = 0;
	x = 0;
	pos = (t_position *)malloc(sizeof(t_position));
	if (!pos)
		return (NULL);
	pos->x = -1;
	pos->y = -1;
	pos->direction = '\0';
	if (map == NULL)
		return (pos);
	while (y < map_height && map[y] != NULL)
	{
		x = 0;
		while (x < map_width)
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W'
				|| map[y][x] == 'E')
			{
				pos->x = x;
				pos->y = y;
				pos->direction = map[y][x];
				return (pos);
			}
			x++;
		}
		y++;
	}
	return (pos); // Not found, return invalid position
}

t_player	*init_player_struct(t_content *map)
{
	t_player	*player;
	t_position	*pos;

	player = (t_player *)malloc(sizeof(t_player));
	pos = find_char(map->map, map->map_max_y, map->map_max_x);
	player->pos_x = pos->x + 0.5;
	player->pos_y = pos->y + 0.5;
	//	printf("player->pos-x = [%d]\n", pos->x);
	//	printf("player->pos-y = [%d]\n", pos->y);
	//	printf("player->direction = [%c]\n", pos->direction);
	if (pos->direction == 'N')
	{
		printf("found north\n");
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (pos->direction == 'S')
	{
		printf("found south\n");
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (pos->direction == 'E')
	{
		printf("found east\n");
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (pos->direction == 'W')
	{
		printf("found west\n");
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	return (player);
}
