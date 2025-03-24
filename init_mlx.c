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
	printf("string path: [%s]\n", game->map->NO_path);
	tex->NO_path = mlx_load_png(game->map->NO_path);
	tex->SO_path = mlx_load_png(game->map->SO_path);
	tex->WE_path = mlx_load_png(game->map->WE_path);
	tex->EA_path = mlx_load_png(game->map->EA_path);
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
