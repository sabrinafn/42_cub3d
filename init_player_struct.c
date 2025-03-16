/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:32:27 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/26 14:44:54 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

t_position	*find_char(char **map, int map_height, int map_width)
{
	t_position *pos;
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
            if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
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

	map->NO_wall = NULL;
	map->SO_wall = NULL;
	map->WE_wall = NULL;
	map->EA_wall = NULL;
	map->floor = NULL;
	map->ceiling = NULL;
	map->map_max_x = 39;
	map->map_max_y = 15;

	map->map = (char **)malloc(sizeof(char *) * 15);
	map->map[0] = ft_strdup("1111111111111111111111111111111111111\n");
	map->map[1] = ft_strdup("1010010010000000111111111110000001001\n");
	map->map[2] = ft_strdup("1010010000000000100000000010001101001\n");
	map->map[3] = ft_strdup("1010010011111110100111111010010001111\n");
	map->map[4] = ft_strdup("1010010010000000100100000000100000011\n");
	map->map[5] = ft_strdup("1010010010000000000100000011000000001\n");
	map->map[6] = ft_strdup("1011110111111111111111111111111101111\n");
	map->map[7] = ft_strdup("1010000100000000000000000000000100001\n");
	map->map[8] = ft_strdup("1011000100000000000000000000000100111\n");
	map->map[9] = ft_strdup("1000100110000000100000000010011101001\n");
	map->map[10] = ft_strdup("10010010100000001000000000101N0001111\n");
	map->map[11] = ft_strdup("1000001000000000000000000000111111111\n");
	map->map[12] = ft_strdup("1001111111111111000000011111111111111\n");
	map->map[13] = ft_strdup("1111111111111111111111111111111111111\n");
	map->map[14] = NULL;

/*
	map->map_max_x = 8;
	map->map_max_y = 8;

	map->map = (char **)malloc(sizeof(char *) * 8);
	map->map[0] = ft_strdup("1111111\n");
	map->map[1] = ft_strdup("1000001\n");
	map->map[2] = ft_strdup("1000101\n");
	map->map[3] = ft_strdup("1000001\n");
	map->map[4] = ft_strdup("1000101\n");
	map->map[5] = ft_strdup("100N001\n");
	map->map[6] = ft_strdup("1111111\n");
	map->map[7] = NULL;
*/
	return (map);
}
