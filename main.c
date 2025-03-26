/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:21:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/26 10:19:08 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

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
	int i;
	i = 0;
	// while(s_content->map[i] != NULL)
	// {
	// 	printf("%s\n",s_content->map[i]);
	// 	i++;
	// }
	free_matrix(file_matrix);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		printf("!game malloc\n");
		return (0);
	}
	game->map_struct = s_content;
	game->player_struct = init_player_struct(game->map_struct);
	init_game(game);
	return(0);
}


