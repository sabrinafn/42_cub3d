/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:21:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/23 15:47:40 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int main(int argc, char **argv)
{
	t_game		*game;
	t_args		*s_map;
	t_content	*s_content;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		printf("!game malloc\n");
		return (0);
	}

	// tudo isso em uma outra função. tipo, só escrito: validando_mapa() e
	// outra função só escrito inicialisando_estrutura do mapa()
	if(!check_arguments(argc, argv[1]))
		return(1);
	if(!empty_file(argv[1]))
		return(1);
	s_map = malloc(sizeof(t_args));
	s_content = malloc(sizeof(t_content));
	s_map->name_file = argv[1];
	s_map->countcols = countcols(argv[1]);
	s_map->matrix = makematrix(argv[1], s_map->countcols);
	if(!validate_content(s_map))
		return(1);
	if(!validate_map(s_map))
		return(1);
	if(!get_info(s_map, s_content))
	 	return(1);
	s_content->map_max_y = get_map_sizes_y(s_content);
	s_content->map_max_x = get_map_sizes_x(s_content);
	// até aqui

	game->map = s_content;
	game->player = init_player_struct(game->map);
	init_game(game);
	return(0);
}


