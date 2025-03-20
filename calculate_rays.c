/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:03:11 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/20 14:37:15 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	init_ray_pos_and_dir(int x, t_ray *ray, t_player *player)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->dir_x = player->dir_x + (player->plane_x * ray->camera_x);
	ray->dir_y = player->dir_y + (player->plane_y * ray->camera_x);
	// which box of the map we're in
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
}

void	init_delta_distance(t_ray *ray)
{
	// length of ray from current position to next x or y-side
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->hit = 0;
}

void	init_step_and_sidedist(t_ray *ray, t_player *player)
{
	// calculate step and initial sideDist
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

void	perform_dda(t_ray *ray, t_args *map)
{
	// perform DDA
	while (ray->hit == 0)
	{
		// jump to next map square, either in x-direction, or in y-direction
		if (ray->side_dist_x <= ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->map[ray->map_y][ray->map_x] == '1'
			&& ray->map_x < map->map_max_x && ray->map_y < map->map_max_y)
			ray->hit = 1;
	}
}

void	calculate_rays(int x, t_game *game)
{
	init_ray_pos_and_dir(x, game->ray_struct, game->player_struct);
	init_delta_distance(game->ray_struct);
	init_step_and_sidedist(game->ray_struct, game->player_struct);
	perform_dda(game->ray_struct, game->map_struct);
}
