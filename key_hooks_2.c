/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:14:24 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/27 19:24:20 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	move_player_vision_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x
		* cos(-ROTATION_SPEED) - game->player->dir_y
		* sin(-ROTATION_SPEED);
	game->player->dir_y = old_dir_x * sin(-ROTATION_SPEED)
		+ game->player->dir_y * cos(-ROTATION_SPEED);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x
		* cos(-ROTATION_SPEED) - game->player->plane_y
		* sin(-ROTATION_SPEED);
	game->player->plane_y = old_plane_x * sin(-ROTATION_SPEED)
		+ game->player->plane_y * cos(-ROTATION_SPEED);
}

void	move_player_vision_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x
		* cos(ROTATION_SPEED) - game->player->dir_y
		* sin(ROTATION_SPEED);
	game->player->dir_y = old_dir_x * sin(ROTATION_SPEED)
		+ game->player->dir_y * cos(ROTATION_SPEED);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x
		* cos(ROTATION_SPEED) - game->player->plane_y
		* sin(ROTATION_SPEED);
	game->player->plane_y = old_plane_x * sin(ROTATION_SPEED)
		+ game->player->plane_y * cos(ROTATION_SPEED);
}
