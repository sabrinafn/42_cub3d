/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/30 19:50:31 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

mlx_texture_t	*get_wall_texture(t_game *game)
{
	mlx_texture_t	*texture;

	if (game->ray->side == 0)
	{
		if (game->ray->dir_x > 0)
			texture = game->textures->ea_path;
		else
			texture = game->textures->we_path;
	}
	else
	{
		if (game->ray->dir_y > 0)
			texture = game->textures->so_path;
		else
			texture = game->textures->no_path;
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
	tex->no_path = mlx_load_png(game->map->no_path);
	tex->so_path = mlx_load_png(game->map->so_path);
	tex->we_path = mlx_load_png(game->map->we_path);
	tex->ea_path = mlx_load_png(game->map->ea_path);
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
