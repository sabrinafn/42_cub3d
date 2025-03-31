/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.init_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/30 19:50:18 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	draw_ceiling_and_floor(t_game *game)
{
	int				i;
	int				j;
	unsigned int	ceiling;
	unsigned int	floor;

	i = 0;
	j = 0;
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

void	clear_image(t_game *game)
{
	int				i;
	int				j;
	unsigned int	blank;

	i = 0;
	j = 0;
	blank = 0xFFFFFFFF;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			mlx_put_pixel(game->img, i, j, blank);
			j++;
		}
		i++;
	}
}
