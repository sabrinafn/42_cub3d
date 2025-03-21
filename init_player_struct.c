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

t_player	*init_player_struct(t_args *map)
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

t_args	*init_map_struct(void)
{
	t_args	*map;

	map = (t_args *)malloc(sizeof(t_args));
	map->NO_wall = "./assets/textures/ollie_polite_cat-256x256.png";
	map->SO_wall = "./assets/textures/ollie_polite_cat-256x256.png";
	map->WE_wall = "./assets/textures/crying_cat.png";
	map->EA_wall = "./assets/textures/crying_cat.png";
	map->floor = NULL;
	map->ceiling = NULL;
	map->map_max_x = 39;
	map->map_max_y = 15;
	map->map = (char **)malloc(sizeof(char *) * 15);
	map->map[0] = ft_strdup("		1111111111111111111111111\n");
	map->map[1] = ft_strdup("		1000000000110000000000001\n");
	map->map[2] = ft_strdup("		1011000001110000001111111\n");
	map->map[3] = ft_strdup("11111111100000000000000001\n");
	map->map[4] = ft_strdup("11111111101100000111000001111111\n");
	map->map[5] = ft_strdup("100000000011000001110111111111111\n");
	map->map[6] = ft_strdup("11110111111111011100000000001\n");
	map->map[7] = ft_strdup("11110111111111011101010010001			111\n");
	map->map[8] = ft_strdup("11000000110101011100000010001			101\n");
	map->map[9] = ft_strdup("10000000000000001100000010001			111\n");
	map->map[10] = ft_strdup("10000000000000001101010010001\n");
	map->map[11] = ft_strdup("11000001110101011111011110N0111\n");
	map->map[12] = ft_strdup("11110111 1110101 101111010001\n");
	map->map[13] = ft_strdup("11111111 1111111 111111111111\n");
	map->map[14] = NULL;
	/*
		map->map_max_x = 8;
		map->map_max_y = 8;
		map->map = (char **)malloc(sizeof(char *) * 8);
		map->map[0] = ft_strdup("1111111\n");
		map->map[1] = ft_strdup("1000001\n");
		map->map[2] = ft_strdup("1000101\n");
		map->map[3] = ft_strdup("100N001\n");
		map->map[4] = ft_strdup("1000101\n");
		map->map[5] = ft_strdup("1000001\n");
		map->map[6] = ft_strdup("1111111\n");
		map->map[7] = NULL;
	*/
	return (map);
}
