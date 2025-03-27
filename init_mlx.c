/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/27 14:39:31 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

mlx_texture_t	*get_wall_texture(t_game *game)
{
	mlx_texture_t	*texture;

	if (game->ray->side == 0)
	{
		if (game->ray->dir_x > 0)
			texture = game->textures->EA_path;
		else
			texture = game->textures->WE_path;
	}
	else
	{
		if (game->ray->dir_y > 0)
			texture = game->textures->SO_path;
		else
			texture = game->textures->NO_path;
	}
	return (texture);
}

t_textures	*init_textures(t_game *game)
{
	t_textures	*tex;

	tex = (t_textures *)malloc(sizeof(t_textures));
	if (!tex)
	{
		print_error(ERROR_3);
		return (NULL);
	}
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
		print_error(ERROR_18);
		return (NULL);
	}
	return (img);
}

int	init_window(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!game->mlx)
		return (print_error(ERROR_17));
	return (1);
}
