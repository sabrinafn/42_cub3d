/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/24 19:17:56 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	get_wall_height(t_ray *ray)
{
	// Calculate distance projected on camera direction
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	// Calculate height of line to draw on screen
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	// calculate lowest and highest pixel to fill in current stripe
	ray->draw_start = -ray->line_height / 2 + (HEIGHT / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2) + (HEIGHT / 2);
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

void	find_x_pixel(t_game *game)
{
	// game->textures_wall_x: finds the exact position where the wall was hit
	// it is required to know which x position we need to get the pixels from
	if (game->ray->side == 0)
	{
		game->textures->wall_x = game->player->pos_y + game->ray->perp_wall_dist
			* game->ray->dir_y;
	}
	else
	{
		game->textures->wall_x = game->player->pos_x + game->ray->perp_wall_dist
			* game->ray->dir_x;
	}
	// removes the integer part of a number: 3.14 = 0.14
	// line removes the grid square number, leaving only the position inside
	// that grid square. This position is then used to find the correct
	// pixel on the texture.
	game->textures->wall_x -= floor((game->textures->wall_x));
}

void	find_x_strip(t_game *game, int tex_width)
{
	// x coordinate on the texture
	// tex_x finds which 'strip' of the texture to be used
	game->textures->tex_x = (int)(game->textures->wall_x * (double)(tex_width));
	if (game->ray->side == 0 && game->ray->dir_x > 0)
		game->textures->tex_x = tex_width - game->textures->tex_x - 1;
	if (game->ray->side == 1 && game->ray->dir_y < 0)
		game->textures->tex_x = tex_width - game->textures->tex_x - 1;
}

void	calculate_texture_step_and_position(t_game *game, int tex_height)
{
	// How much to increase the texture coordinate per screen pixel
	// the distance to move
	game->textures->step = 1.0 * tex_height / game->ray->line_height;
	// Starting texture coordinate
	// top of the coordinate of the texture
	game->textures->tex_pos = (game->ray->draw_start - HEIGHT / 2
			+ game->ray->line_height / 2) * game->textures->step;
}

void	calculate_and_draw_walls(t_game *game, mlx_texture_t *texture, int x)
{
	int			y;
	int			pixel_index;
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
	uint8_t		alpha;
	uint32_t	color;

	y = game->ray->draw_start;
	while (y < game->ray->draw_end)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		// tex_y is like rounding tex_pos down to the nearest pixel coordinate.
		game->textures->tex_y = (int)game->textures->tex_pos & (texture->height - 1);
	
		// Starting texture coordinate;
		// top of the coordinate of the texture;
		// updating tex_pos to move to a different pixel
		game->textures->tex_pos += game->textures->step;

		// finds the current pixel in the t_textures structs from mlx, to put it on the screen
		pixel_index = (game->textures->tex_y * texture->width + game->textures->tex_x) * 4;

		// get the 4 colors parts to form the color
		red = texture->pixels[pixel_index];
		green = texture->pixels[pixel_index + 1];
		blue = texture->pixels[pixel_index + 2];
		alpha = texture->pixels[pixel_index + 3];
		color = get_rgba(red, green, blue, alpha);
		
		// putting the pixel on the window
		if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
			mlx_put_pixel(game->img, x, y, color);
		y++;
	}
}
