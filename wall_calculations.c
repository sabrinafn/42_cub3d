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

void	get_wall_height(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + (HEIGHT / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2) + (HEIGHT / 2);
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

void	find_x_pixel(t_game *game)
{
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
	game->textures->wall_x -= floor((game->textures->wall_x));
}

void	calculate_x_for_vertical_slice(t_game *game, int tex_width)
{
	find_x_pixel(game);
	game->textures->tex_x = (int)(game->textures->wall_x * (double)(tex_width));
	if (game->ray->side == 0 && game->ray->dir_x > 0)
		game->textures->tex_x = tex_width - game->textures->tex_x - 1;
	if (game->ray->side == 1 && game->ray->dir_y < 0)
		game->textures->tex_x = tex_width - game->textures->tex_x - 1;
}

void	calculate_texture_step_and_position(t_game *game, int tex_height)
{
	game->textures->step = 1.0 * tex_height / game->ray->line_height;
	game->textures->tex_pos = (game->ray->draw_start - HEIGHT / 2
			+ game->ray->line_height / 2) * game->textures->step;
}

void	calculate_and_draw_walls(t_game *game, mlx_texture_t *texture, int x)
{
	int			y;
	uint32_t	color;

	y = game->ray->draw_start;
	while (y <= game->ray->draw_end)
	{
		color = get_current_pixel_color(game, texture);
		if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
			mlx_put_pixel(game->img, x, y, color);
		y++;
	}
}
