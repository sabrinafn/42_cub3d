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

void	draw_wall(int x, t_ray *ray, mlx_image_t *img)
{
	uint32_t	color;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
	int			i;

	get_wall_height(ray);
	color = RGB_Green;;
	if (ray->side == 1)
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
	i = ray->draw_start;
	while (i < ray->draw_end)
	{
		if (i >= 0 && i < HEIGHT && x >= 0 && x < WIDTH)
			mlx_put_pixel(img, x, i, color);
		i++;
	}
}
