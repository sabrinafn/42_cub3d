/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/20 14:39:27 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

t_textures	*init_textures(t_game *game)
{
	t_textures	*tex;

	tex = (t_textures *)malloc(sizeof(t_textures));
	if (!tex)
	{
		printf("error in malloc textures\n");
		return (NULL);
	}
	tex->NO_wall = mlx_load_png(game->map_struct->NO_wall);
	tex->SO_wall = mlx_load_png(game->map_struct->SO_wall);
	tex->WE_wall = mlx_load_png(game->map_struct->WE_wall);
	tex->EA_wall = mlx_load_png(game->map_struct->EA_wall);
	return (tex);
}

mlx_image_t	*init_img(t_game *game)
{
	mlx_image_t	*img;

	img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!img)
	{
		ft_putstr_fd("Error creating image2\n", 2);
		return (NULL);
	}
	return (img);
}

int	init_window(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!game->mlx)
	{
		ft_putstr_fd("game->mlx error\n", 2);
		return (0);
	}
	return (1);
}
