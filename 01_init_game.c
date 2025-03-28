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
	mlx_image_t	*img_mini;
	int			x;
	int			y;

	x = 0;
	y = 0;
	int mini_width = 100;
	int	mini_height = 100;
	while (x < mini_width)
	{
		printf("hi\n");
		y = 0;
		while (y < mini_height)
		{
			if (game->map->map[x][y] == 1)
			{
				printf("found wall\n");
				mlx_put_pixel(img_mini, x, y, 0x00000000);
			}
			y++;
		}
		x++;
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

void	clear_image(t_game *game)
{

	int				i;
	int				j;
	unsigned int	blank;

	i = 0;
	j = 0;
	blank = 0xFFFFFFFF;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
				mlx_put_pixel(game->img, i, j, blank);
			j++;
		}
		i++;
	}
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
