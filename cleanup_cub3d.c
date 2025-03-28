/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:21:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/28 16:48:28 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	cleanup_mlx(t_game *game)
{
	mlx_delete_image(game->mlx, game->img);
	mlx_delete_texture(game->textures->no_path);
	mlx_delete_texture(game->textures->so_path);
	mlx_delete_texture(game->textures->we_path);
	mlx_delete_texture(game->textures->ea_path);
	free(game->textures);
	free(game->ray);
	free(game->player);
	mlx_terminate(game->mlx);
}

void	cleanup_program(t_game *game)
{
	free_matrix(game->map->map);
	free_matrix(game->map->color_c);
	free_matrix(game->map->color_f);
	free(game->map->no_path);
	free(game->map->so_path);
	free(game->map->we_path);
	free(game->map->ea_path);
	free(game->map);
	free(game);
}
