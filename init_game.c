/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <sabrifer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:43 by sabrifer          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:00 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

mlx_image_t	*init_img(t_game *game)
{
	mlx_image_t *img;

	img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!img)
	{
		ft_putstr_fd("Error creating image2\n", 2);
		return (NULL);
	}
	return (img);
}

void	draw_ceiling_and_floor(t_game *game)
{
	int				i;
	int				j;
	unsigned int	ceiling;
	unsigned int	floor;

	i = 0;
	j = 0;
	ceiling = get_rgba(128, 112, 214, 255);
	floor = get_rgba(255, 199, 231, 255);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (j < HEIGHT / 2)
				mlx_put_pixel(game->img, i, j, ceiling);
			else
				mlx_put_pixel(game->img, i, j, floor);
			j++;
		}
		i++;
	}
}

void	render_raycast_frame(t_game *game)
{
	int		x;

	x = 0;
	draw_ceiling_and_floor(game);
	while (x < WIDTH)
	{
		calculate_rays(x, game);
		draw_walls(x, game);
		x++;
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

int	init_structs_in_game(t_game *game)
{
	game->img = init_img(game);
	if (!game->img)
	{
		ft_putstr_fd("game->img error\n", 2);
		return (0);
	}
	game->ray_struct = (t_ray *)malloc(sizeof(t_ray));
	if (!game->ray_struct)
	{
		ft_putstr_fd("game->ray_struct error\n", 2);
		return (0);
	}
	return (1);
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

void	init_game(t_game *game)
{
	if (!init_window(game))
		exit(0);
	if (!init_structs_in_game(game))
		exit(0);
	
	t_textures	*tex;
	mlx_texture_t	*wall_tex;
		tex = (t_textures *)malloc(sizeof(t_textures));
	if (!tex)
		printf("error in malloc textures\n");
	game->textures = tex;
	printf("before load_png\n");
	wall_tex = mlx_load_png(game->map_struct->NO_wall);
	printf("after load_png\n");
	game->textures->NO_wall = wall_tex;
	game->textures->SO_wall = wall_tex;
	game->textures->WE_wall = wall_tex;
	game->textures->EA_wall = wall_tex;
		
	render_raycast_frame(game);
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
