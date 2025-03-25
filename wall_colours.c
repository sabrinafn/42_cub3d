/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/25 13:56:31 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int	get_pixel_index(t_game *game, mlx_texture_t *texture)
{
	int	pixel_index;

	game->textures->tex_y = (int)game->textures->tex_pos & (texture->height
			- 1);
	game->textures->tex_pos += game->textures->step;
	pixel_index = (game->textures->tex_y * texture->width
			+ game->textures->tex_x) * 4;
	return (pixel_index);
}

uint32_t	get_current_pixel_color(t_game *game, mlx_texture_t *texture)
{
	int			pixel_index;
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
	uint8_t		alpha;

	pixel_index = get_pixel_index(game, texture);
	red = texture->pixels[pixel_index];
	green = texture->pixels[pixel_index + 1];
	blue = texture->pixels[pixel_index + 2];
	alpha = texture->pixels[pixel_index + 3];
	return (get_rgba(red, green, blue, alpha));
}
