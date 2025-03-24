/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:00 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

#define RGB_Red 0xFF0000FF    // Red
#define RGB_Green 0x00FF00FF  // Green
#define RGB_Blue 0x0000FFFF   // Blue
#define RGB_White 0xFFFFFFFF  // White
#define RGB_Yellow 0xFFFF00FF // Yellow

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

mlx_texture_t	*get_wall_texture(t_game *game)
{
	mlx_texture_t	*texture;

    if (game->ray_struct->side == 0)
	{
		if (game->ray_struct->dir_x > 0)
            texture = game->textures->EA_path;
		else
			texture = game->textures->WE_path;

    }
	else
	{
        if (game->ray_struct->dir_y > 0)
			texture = game->textures->SO_path;
        else
			texture = game->textures->NO_path;
    }
	return (texture);
}

void	draw_walls_with_texture(int x, t_game *game)
{
	mlx_texture_t	*texture;
	int y;
	int pixel_index;
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;
	uint32_t color;

	texture = get_wall_texture(game);

	if (game->ray_struct->side == 0)
	{
		game->textures->wall_x = game->player_struct->pos_y
		+ game->ray_struct->perp_wall_dist * game->ray_struct->dir_y;
	}
	else
	{
		game->textures->wall_x = game->player_struct->pos_x
		+ game->ray_struct->perp_wall_dist * game->ray_struct->dir_x;
	}
	game->textures->wall_x -= floor((game->textures->wall_x));

  	//x coordinate on the texture
	game->textures->tex_x = (int)(game->textures->wall_x * (double)(texture->width));
	if (game->ray_struct->side == 0 && game->ray_struct->dir_x > 0)
		game->textures->tex_x = texture->width - game->textures->tex_x - 1;
	if (game->ray_struct->side == 1 && game->ray_struct->dir_y < 0)
		game->textures->tex_x = texture->width - game->textures->tex_x - 1;

	// How much to increase the texture coordinate per screen pixel
	game->textures->step = 1.0 * texture->height / game->ray_struct->line_height;
	// Starting texture coordinate
	game->textures->tex_pos = (game->ray_struct->draw_start - HEIGHT / 2 + game->ray_struct->line_height / 2) * game->textures->step;
	
	y = game->ray_struct->draw_start;

	while (y < game->ray_struct->draw_end)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		game->textures->tex_y = (int)game->textures->tex_pos & (texture
->height - 1);

		game->textures->tex_pos += game->textures->step;
		//uint32 color = texture[texNum][texHeight * texY + texX];
		// replaced by ->
		pixel_index = (game->textures->tex_y * texture
->width + game->textures->tex_x) * 4;
		red = texture->pixels[pixel_index];
		green = texture->pixels[pixel_index + 1];
		blue = texture->pixels[pixel_index + 2];
		alpha = texture->pixels[pixel_index + 3];

		color = get_rgba(red, green, blue, alpha);
		
		if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
			mlx_put_pixel(game->img, x, y, color);
		y++;
	}

	//mlx_delete_texture(wall_texture);
}

// update function to only draw wall with colors
/*
void	draw_walls_with_colors(int x, t_game *game)
{
	uint32_t	color;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
	int			i;

	color = RGB_Green;
	if (game->ray_struct->side == 1)
	{
		// Darken the color when it is a side wall (divide each component by 2)
		r = (color >> 24) & 0xFF;
		g = (color >> 16) & 0xFF;
		b = (color >> 8) & 0xFF;
		a = color & 0xFF;
		r /= 2;
		g /= 2;
		b /= 2;
		color = (r << 24) | (g << 16) | (b << 8) | a;
	}
	i = game->ray_struct->draw_start;
	while (i < game->ray_struct->draw_end)
	{
		if (i >= 0 && i < HEIGHT && x >= 0 && x < WIDTH)
			mlx_put_pixel(game->img, x, i, color);
		i++;

}
	//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
	//if(game->ray_struct->side == 1)
	//	color = (color >> 1) & 8355711;
	//buffer[y][x] = color;
*/