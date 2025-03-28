/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:21:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/28 16:47:33 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int	main(int argc, char **argv)
{
	t_game		*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (1);
	if (!check_arguments(argc, argv[1]))
		return (1);
	init_map(argv[1], game);
	init_game(game);
	cleanup_program(game);
	return (0);
}

void	init_map(char *argv, t_game *game)
{
	char	**file_matrix;

	file_matrix = makematrix(argv, countcols(argv));
	if (!validate_content(file_matrix))
	{
		free_matrix(file_matrix);
		free(game);
		exit (1);
	}
	game->map = malloc(sizeof(t_content));
	if (!get_content(file_matrix, game->map))
	{
		free_matrix(file_matrix);
		cleanup_program(game);
		exit (1);
	}
}
