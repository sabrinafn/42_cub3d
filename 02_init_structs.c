/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/23 12:30:00 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_ceiling_and_floor(t_game *game)
{
	int				i;
	int				j;
	unsigned int	ceiling;
	unsigned int	floor;

	i = 0;
	j = 0;
	//ceiling = get_rgba(128, 112, 214, 255);
	//floor = get_rgba(255, 199, 231, 255);
	ceiling = game->map->ceiling;
	floor = game->map->floor;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (j < HEIGHT / 2)
				mlx_put_pixel(game->img, i, j, ceiling);
			else
				mlx_put_pixel(game->img, i, j, floor);
			j++;
		}
		i++;
	}
}

int	init_structs_in_game(t_game *game)
{
	// the following two structs might have to be initialized in the main function
	//game->map = init_map_struct();
	//init_player_struct(t_content *map)
	game->img = init_img(game);
	if (!game->img)
	{
		ft_putstr_fd("game->img error\n", 2);
		return (0);
	}
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	if (!game->ray)
	{
		ft_putstr_fd("game->ray error\n", 2);
		return (0);
	}
	game->textures = init_textures(game);
	if (!game->textures)
	{
		ft_putstr_fd("game->textures error\n", 2);
		return (0);
	}
	return (1);
}
