/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:00 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

// RGB 244, 194, 194
// # define WIDTH 800
// # define HEIGHT 601

#define RGB_Red 0xFF0000FF    // Red
#define RGB_Green 0x00FF00FF  // Green
#define RGB_Blue 0x0000FFFF   // Blue
#define RGB_White 0xFFFFFFFF  // White
#define RGB_Yellow 0xFFFF00FF // Yellow

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

mlx_image_t	*init_img(mlx_t *mlx, unsigned int floor, unsigned int ceiling)
{
	mlx_image_t	*img;
	int			i;
	int			j;

	i = 0;
	j = 0;
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_putstr_fd("Error creating image\n", 2);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (j < HEIGHT / 2)
				mlx_put_pixel(img, i, j, ceiling);
			else
				mlx_put_pixel(img, i, j, floor);
			j++;
		}
		i++;
	}
	return (img);
}

void	render_raycast_frame(t_game *game)
{
	unsigned int	ceiling;
	unsigned int	floor;
	int			x;
	t_ray		*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	ceiling = get_rgba(255, 199, 231, 255);
	floor = get_rgba(128, 112, 214, 255);
	game->img = init_img(game->mlx, ceiling, floor);
	x = 0;
	while (x < WIDTH)
	{
		calculate_rays(x, ray, game->player_struct);
		perform_dda(ray, game->map_struct);
		draw_wall(x, ray, game->img);
		x++;
	}
}

void	key_pressed_function(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	(void)keydata;

	// W 
	// A
	// S
	// D
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player_w(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player_s(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A)) // left
		move_player_a(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D)) // right
		move_player_d(game);
}

void	move_player_w(t_game *game)
{
	double	new_x;
	double	new_y;
	int	new_pos_x;
	int	new_pos_y;

	new_y = game->player_struct->pos_y + game->player_struct->dir_y * MOVE_SPEED;
	new_x = game->player_struct->pos_x + game->player_struct->dir_x * MOVE_SPEED;
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
	int	new_pos_x;
	int	new_pos_y;

	new_y = game->player_struct->pos_y - game->player_struct->dir_y * MOVE_SPEED;
	new_x = game->player_struct->pos_x - game->player_struct->dir_x * MOVE_SPEED;
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
	int	new_pos_x;
	int	new_pos_y;

	new_y = game->player_struct->pos_y - game->player_struct->plane_y * MOVE_SPEED;
	new_x = game->player_struct->pos_x - game->player_struct->plane_x * MOVE_SPEED;
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
	int	new_pos_x;
	int	new_pos_y;

	new_y = game->player_struct->pos_y + game->player_struct->plane_y * MOVE_SPEED;
	new_x = game->player_struct->pos_x + game->player_struct->plane_x * MOVE_SPEED;
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

void	init_window(t_game *game)
{

	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!game->mlx)
		ft_putstr_fd("Error opening window\n", 2);

	//mlx_image_to_window(game->mlx, game->img, WIDTH, HEIGHT);
	render_raycast_frame(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	mlx_key_hook(game->mlx, &key_pressed_function, game);
	mlx_loop(game->mlx);
}
/********************************************************************
Implement Raycasting Loop:

- Create a function that iterates through each vertical screen column.
- For each column:
	- Calculate the ray direction.
	- Call the DDA function to find the wall intersection.
	- Calculate the distance to the wall.
	- Calculate the wall height on the screen.
	- Calculate the texture coordinate.
********************************************************************/
