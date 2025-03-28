/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/03/27 19:41:51 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	draw_walls_with_texture(int x, t_game *game)
{
	mlx_texture_t	*texture;

	texture = get_wall_texture(game);
	calculate_x_for_vertical_slice(game, texture->width);
	calculate_texture_step_and_position(game, texture->height);
	calculate_and_draw_walls(game, texture, x);
}

void	draw_minimap(t_game *game)
{
	int			x;
	int			y;
	int			mini_x;
	int			mini_y;

	x = 0;
	y = 0;
	mini_x = game->map->map_max_x;
	mini_y = game->map->map_max_y;
	while (y < HEIGHT)
	{
		printf("hi\n");
		x = 0;
		while (x < WIDTH)
		{
			if (game->map->map[y][x] == 1)
				mlx_put_pixel(game->img, y, x, 0X00000000);
			x++;
		}
		y++;
	}
	//x = 0;
	//y = 0;
	//while (y < HEIGHT)
	//{
	//	while (x < WIDTH)
	//	{
	//		if (game->map->map[y][x] == 'N' ||game->map->map[y][x] == 'S'
	//			|| game->map->map[y][x] == 'W' ||game->map->map[y][x] == 'E')
	//			mlx_put_pixel(game->img, map_y + y, map_x + x, 0xFF0000FF);
	//		x++;
	//	}
	//	y++;
	//}
}

void	render_raycast_frame(void *param)
{
	int		x;
	t_game	*game;

	x = 0;
	game = (t_game *)param;
	draw_ceiling_and_floor(game);
	while (x < WIDTH)
	{
		// check the functions being called and if their names make sense
		calculate_rays(x, game);
		get_wall_height(game->ray);
		draw_walls_with_texture(x, game);
		draw_minimap(game);
		x++;
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

int	init_game(t_game *game)
{
	if (!init_window(game))
		return (print_error(ERROR_16));
	if (!init_structs_in_game(game))
		return (print_error(ERROR_3));
	mlx_key_hook(game->mlx, &key_pressed_function, game);
	mlx_loop_hook(game->mlx, render_raycast_frame, game);
	mlx_loop(game->mlx);
	cleanup_mlx(game);
	return (1);
}
