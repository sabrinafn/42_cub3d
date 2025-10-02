/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.init_player_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:32:27 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/30 19:50:25 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	update_struct_position(t_position **pos, int x, int y, char c)
{
	(*pos)->x = x;
	(*pos)->y = y;
	(*pos)->direction = c;
}

void	find_char(t_position *pos, char **map, int map_height, int map_width)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_height && map[y])
	{
		x = 0;
		while (x < map_width)
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W'
				|| map[y][x] == 'E')
			{
				update_struct_position(&pos, x, y, map[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	set_direction_north_and_south(char dir, t_player **player)
{
	if (dir == 'N')
	{
		(*player)->dir_x = 0;
		(*player)->dir_y = -1;
		(*player)->plane_x = 0.66;
		(*player)->plane_y = 0;
	}
	else if (dir == 'S')
	{
		(*player)->dir_x = 0;
		(*player)->dir_y = 1;
		(*player)->plane_x = -0.66;
		(*player)->plane_y = 0;
	}
}

void	set_direction_west_and_east(char dir, t_player **player)
{
	if (dir == 'E')
	{
		(*player)->dir_x = 1;
		(*player)->dir_y = 0;
		(*player)->plane_x = 0;
		(*player)->plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		(*player)->dir_x = -1;
		(*player)->dir_y = 0;
		(*player)->plane_x = 0;
		(*player)->plane_y = -0.66;
	}
}

t_player	*init_player_struct(t_content *map)
{
	t_player	*player;
	t_position	*pos;

	player = (t_player *)malloc(sizeof(t_player));
	pos = (t_position *)malloc(sizeof(t_position));
	pos->x = -1;
	pos->y = -1;
	find_char(pos, map->map, map->map_max_y, map->map_max_x);
	player->pos_x = pos->x + 0.5;
	player->pos_y = pos->y + 0.5;
	if (pos->direction == 'N' || pos->direction == 'S')
		set_direction_north_and_south(pos->direction, &player);
	else if (pos->direction == 'W' || pos->direction == 'E')
		set_direction_west_and_east(pos->direction, &player);
	if (pos)
		free(pos);
	return (player);
}
