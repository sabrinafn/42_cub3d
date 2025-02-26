/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/19 16:25:32 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

// RGB 244, 194, 194
// # define WIDTH 800
// # define HEIGHT 600

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

mlx_image_t	*init_img(mlx_t *mlx, unsigned int floor, unsigned int ceiling)
{
	mlx_image_t	*img;
	int			i;
	int			j;
	
	i = 0;
	j = 0;
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_putstr_fd("Error creating image\n", 2);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (j < HEIGHT / 2)
				mlx_put_pixel(img, i, j, ceiling);
			else
				mlx_put_pixel(img, i, j, floor);
			j++;
		}
		i++;
	}
	return (img);
}

void	calculate_rays_direction(t_player *player)
{
	int x;
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	x = 0;
	while (x < WIDTH)
	{
		ray->camera_x = 2 * x / (double)WIDTH - 1;
		ray->dir_x = player->dir_x + (player->plane_x * ray->camera_x);
		ray->dir_y = player->dir_y + (player->plane_y * ray->camera_x);
		ray->map_x = (int)player->pos_x;
		ray->map_y = (int)player->pos_y;
		x++;
	}
}

void	init_window(t_player *player)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	unsigned int	ceiling;
	unsigned int	floor;
	
	ceiling = get_rgba(255, 199, 231, 255);
	floor = get_rgba(128, 112, 214, 255);
	mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!mlx)
		ft_putstr_fd("Error opening window\n", 2);
	img = init_img(mlx, ceiling, floor);
	mlx_image_to_window(mlx, img, WIDTH, HEIGHT);
	
	calculate_rays_direction(player);
	mlx_loop(mlx);
}
