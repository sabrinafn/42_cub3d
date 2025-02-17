/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/17 20:22:33 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

// RGB 244, 194, 194

unsigned int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	init_window(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	// criar funcão pra converter char *str para 3 ints separados

	int r, g, b;

	r = 255;
	g = 199;
	b = 231;

	unsigned int hex_colour = rgb_to_hex(r, g, b);
	printf("hex color: %x\n", hex_colour);

	mlx = mlx_init(1024, 1024, "Cub3D", true);
	if (!mlx)
		ft_putstr_fd("Error opening window\n", 2);
	img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_putstr_fd("Error creating image\n", 2);
	// Even after the image is being displayed, we can still modify the buffer.
	int i = 0;
	int j = 0;
	while (i < 256)
	{
		while (j < 256)
		{
			mlx_put_pixel(img, i, j, 0xFF);
			// está invertendo as cores 
			j++;
		}
		i++;
	}
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop(mlx);
}
