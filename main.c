/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:21:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/26 13:57:42 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	free_all(t_game *game)
{
//	typedef struct s_game
//{
//	t_ray		*ray;
//	t_player	*player;
//	t_content	*map;
//	mlx_t		*mlx;
//	mlx_image_t	*img;
//	t_textures	*textures;
//	t_game;

	if (game->map)
	{
		//free_matrix(game->map->map);
		//free(game->map->NO_path);
		//free(game->map->SO_path);
		//free(game->map->WE_path);
		//free(game->map->EA_path);
		//free_matrix(game->map->color_C);
		//free_matrix(game->map->color_F);
		free(game->map);
	}

}

int	main(int argc, char **argv)
{
	t_game		*game;
	char		**file_matrix;
	t_content	*s_content;

	if (!check_arguments(argc, argv[1]))
		return (1);
	file_matrix = makematrix(argv[1], countcols(argv[1]));
	if (!validate_content(file_matrix))
		return (1);
	s_content = malloc(sizeof(t_content));
	if (!get_content(file_matrix, s_content))
		return (1);
	free_matrix(file_matrix);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		printf("!game malloc\n");
		return (1);
	}
	game->map = s_content;
	init_game(game);
	free_matrix(s_content->map);
	free_matrix(s_content->color_C);
	free_matrix(s_content->color_F);
	free(s_content->NO_path);
	free(s_content->SO_path);
	free(s_content->WE_path);
	free(s_content->EA_path);
	free(s_content);
	free(game);
	return(0);
}


