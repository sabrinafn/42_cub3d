/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:21:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/30 19:49:36 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

t_game	*init_map(char *argv)
{
	char	**file_matrix;
	t_game	*game;

	file_matrix = makematrix(argv, countcols(argv));
	if (!validate_content(file_matrix))
	{
		free_matrix(file_matrix);
		exit(1);
	}
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = malloc(sizeof(t_content));
	if (!get_content(file_matrix, game->map))
	{
		free_matrix(file_matrix);
		cleanup_program(game);
		exit(1);
	}
	return (game);
}
