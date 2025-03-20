/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thisfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:50:08 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/20 19:36:09 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"

// RGB 244, 194, 194
# define WIDTH 6
# define HEIGHT 6
# include <stdio.h>

/*	NO ./assets/wall/brick-1l.png
	SO ./assets/wall/brick-2l.png
	WE ./assets/wall/brick-2d.png
	EA ./assets/wall/brick-1d.png

	C 238,245,255
	F 210,227,200
*/



mlx_image_t	*init_img(mlx_t *mlx, unsigned int floor, unsigned int ceiling)
{
	mlx_image_t	*img;
	int			i;
	int			j;

	i = 0;
	j = 0;
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT / 2)
		{
			mlx_put_pixel(img, i, j, ceiling);
			j++;
		}
		while (j >= HEIGHT / 2 && j != HEIGHT)
		{
			mlx_put_pixel(img, i, j, floor);
			j++;
		}
		printf("hi\n");
		i++;
	}
	printf("out of the loop\n");
	return (img);
}

/*
void	calculate_rays(mlx_image_t *img, unsigned int wall, int x)
{
	// initial direction vector
	double dirX = -1, dirY = 0;
	
	// camera plane
	double planeX = 0, planeY = 0.66;

	double camera_x = 2 * x / (double)WIDTH - 1;
	double ray_dir_x = dirX + planeX * camera_x;
	double ray_dir_y = dirY + planeY * camera_x;
	mlx_put_pixel(img, ray_dir_x, ray_dir_y, wall);
}*/

int	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	unsigned int	ceiling;
	unsigned int	floor;
	unsigned int	wall;

	int	map[WIDTH][HEIGHT] =
	{
		{1, 1, 1, 1, 1, 1},
		{1, 5, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1}
	};
	int pos_x = 1;
	int pos_y = 1;

	int dir_x = -1;
	int dir_y = 0;

	int plane_x = 0;
	float plane_y = 0.66;

	ceiling = get_rgba(255, 199, 231, 255);
	floor = get_rgba(128, 112, 214, 255);
	wall = 0x00000000;
	mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	img = init_img(mlx, ceiling, floor);

	mlx_image_to_window(mlx, img, WIDTH, HEIGHT);
/*	int x = 0;
	while (x < WIDTH)
	{
		calculate_rays(img, wall, x);
		x++;
	}*/
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return (0);
}
