/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/19 16:22:14 by sabrifer         ###   ########.fr       */
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

void	init_img(mlx_t *mlx, unsigned int floor, unsigned int ceiling)
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
		i++;
	}
}

void	init_window(void)
{
	mlx_t			*mlx;
	unsigned int	baby_pink;
	unsigned int	violet;

	baby_pink = get_rgba(255, 199, 231, 255);
	violet = get_rgba(128, 112, 214, 255);
	mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!mlx)
		ft_putstr_fd("Error opening window\n", 2);
	init_img(mlx, baby_pink, violet);
	mlx_loop(mlx);
}
