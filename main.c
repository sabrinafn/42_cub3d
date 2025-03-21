/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:21:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/21 18:14:20 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int main(int argc, char **argv)
{
	//t_player	*player;
	t_args		*s_map;
	t_content	*s_content;
	//player = NULL;
	s_map = malloc(sizeof(t_args));
	s_content = malloc(sizeof(t_content));
	s_map->name_file = argv[1];
	s_map->countcols = countcols(argv[1]);
	s_map->matrix = makematrix(argv[1], s_map->countcols);
	if(!check_arguments(argc, argv[1]))
		return(1);
	if(!empty_file(argv[1]))
		return(1);
	if(!validate_content(s_map))
		return(1);
	if(!validate_map(s_map))
		return(1);
	//init_player_struct(player);
	if(!get_info(s_map, s_content))
	 	return(1);
	 int i = 0;
	 while (s_content->color_F[i] != NULL)
	 {
	 	printf("%s\n", s_content->color_F[i]);
	 	i++;
	 }
	 //get_map_sizes_y(s_content);
	 printf("floor: %X\n", s_content->floor);
	 printf("celing: %X\n", s_content->ceiling);
	// printf("y: %i", s_content->map_max_y);

	//init_window(player, content);
	return(0);
}


