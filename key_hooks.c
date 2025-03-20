/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:14:24 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/20 14:38:31 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	key_pressed_function(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	(void)keydata;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player_w(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player_s(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A)) // move player to the left
		move_player_a(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D)) // move player to the right
		move_player_d(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)) // move camera to the left
		move_player_vision_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)) // move camera to the right
		move_player_vision_right(game);
}

void	move_player_w(t_game *game)
{
	double	new_x;
	double	new_y;
	int		new_pos_x;
	int		new_pos_y;

	new_y = game->player_struct->pos_y + game->player_struct->dir_y
		* MOVE_SPEED;
	new_x = game->player_struct->pos_x + game->player_struct->dir_x
		* MOVE_SPEED;
	new_pos_x = (int)new_x;
	new_pos_y = (int)new_y;
	if (game->map_struct->map[new_pos_y][new_pos_x] != '1'
		&& new_x < game->map_struct->map_max_x
		&& new_y < game->map_struct->map_max_y)
	{
		game->player_struct->pos_x = new_x;
		game->player_struct->pos_y = new_y;
		render_raycast_frame(game);
	}
}

void	move_player_s(t_game *game)
{
	double	new_x;
	double	new_y;
	int		new_pos_x;
	int		new_pos_y;

	new_y = game->player_struct->pos_y - game->player_struct->dir_y
		* MOVE_SPEED;
	new_x = game->player_struct->pos_x - game->player_struct->dir_x
		* MOVE_SPEED;
	new_pos_x = (int)new_x;
	new_pos_y = (int)new_y;
	if (game->map_struct->map[new_pos_y][new_pos_x] != '1'
		&& new_x < game->map_struct->map_max_x
		&& new_y < game->map_struct->map_max_y)
	{
		game->player_struct->pos_x = new_x;
		game->player_struct->pos_y = new_y;
		render_raycast_frame(game);
	}
}

void	move_player_a(t_game *game) // move left
{
	double	new_x;
	double	new_y;
	int		new_pos_x;
	int		new_pos_y;

	new_y = game->player_struct->pos_y - game->player_struct->plane_y
		* MOVE_SPEED;
	new_x = game->player_struct->pos_x - game->player_struct->plane_x
		* MOVE_SPEED;
	new_pos_x = (int)new_x;
	new_pos_y = (int)new_y;
	if (game->map_struct->map[new_pos_y][new_pos_x] != '1'
		&& new_x < game->map_struct->map_max_x
		&& new_y < game->map_struct->map_max_y)
	{
		game->player_struct->pos_x = new_x;
		game->player_struct->pos_y = new_y;
		render_raycast_frame(game);
	}
}

void	move_player_d(t_game *game) // move right
{
	double	new_x;
	double	new_y;
	int		new_pos_x;
	int		new_pos_y;

	new_y = game->player_struct->pos_y + game->player_struct->plane_y
		* MOVE_SPEED;
	new_x = game->player_struct->pos_x + game->player_struct->plane_x
		* MOVE_SPEED;
	new_pos_x = (int)new_x;
	new_pos_y = (int)new_y;
	if (game->map_struct->map[new_pos_y][new_pos_x] != '1'
		&& new_x < game->map_struct->map_max_x
		&& new_y < game->map_struct->map_max_y)
	{
		game->player_struct->pos_x = new_x;
		game->player_struct->pos_y = new_y;
		render_raycast_frame(game);
	}
}

void	move_player_vision_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player_struct->dir_x;
	game->player_struct->dir_x = game->player_struct->dir_x
		* cos(-ROTATION_SPEED) - game->player_struct->dir_y
		* sin(-ROTATION_SPEED);
	game->player_struct->dir_y = old_dir_x * sin(-ROTATION_SPEED)
		+ game->player_struct->dir_y * cos(-ROTATION_SPEED);
	old_plane_x = game->player_struct->plane_x;
	game->player_struct->plane_x = game->player_struct->plane_x
		* cos(-ROTATION_SPEED) - game->player_struct->plane_y
		* sin(-ROTATION_SPEED);
	game->player_struct->plane_y = old_plane_x * sin(-ROTATION_SPEED)
		+ game->player_struct->plane_y * cos(-ROTATION_SPEED);
	render_raycast_frame(game);
}

void	move_player_vision_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player_struct->dir_x;
	game->player_struct->dir_x = game->player_struct->dir_x
		* cos(ROTATION_SPEED) - game->player_struct->dir_y
		* sin(ROTATION_SPEED);
	game->player_struct->dir_y = old_dir_x * sin(ROTATION_SPEED)
		+ game->player_struct->dir_y * cos(ROTATION_SPEED);
	old_plane_x = game->player_struct->plane_x;
	game->player_struct->plane_x = game->player_struct->plane_x
		* cos(ROTATION_SPEED) - game->player_struct->plane_y
		* sin(ROTATION_SPEED);
	game->player_struct->plane_y = old_plane_x * sin(ROTATION_SPEED)
		+ game->player_struct->plane_y * cos(ROTATION_SPEED);
	render_raycast_frame(game);
}
