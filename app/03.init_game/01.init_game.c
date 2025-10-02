/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/30 19:50:13 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

void	draw_walls_with_texture(int x, t_game *game)
{
	mlx_texture_t	*texture;

	texture = get_wall_texture(game);
	calculate_x_for_vertical_slice(game, texture->width);
	calculate_texture_step_and_position(game, texture->height);
	calculate_and_draw_walls(game, texture, x);
}

void	render_raycast_frame(void *param)
{
	int		x;
	t_game	*game;

	x = 0;
	game = (t_game *)param;
	clear_image(game);
	draw_ceiling_and_floor(game);
	while (x < WIDTH)
	{
		calculate_rays(x, game);
		get_wall_height(game->ray);
		draw_walls_with_texture(x, game);
		x++;
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

void	init_game(t_game *game)
{
	if (!game)
		return ;
	if (!init_window(game))
		print_error(ERROR_16);
	if (!init_structs_in_game(game))
		print_error(ERROR_3);
	mlx_key_hook(game->mlx, &key_pressed_function, game);
	mlx_loop_hook(game->mlx, render_raycast_frame, game);
	mlx_loop(game->mlx);
	cleanup_mlx(game);
}
