/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:21:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/23 15:37:56 by mgonzaga         ###   ########.fr       */
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
	s_content->map_max_y = get_map_sizes_y(s_content);
	 int i = 0;
	 while (s_content->color_F[i] != NULL)
	 {
	 	printf("%s\n", s_content->color_F[i]);
	 	i++;
	 }
	 //get_map_sizes_y(s_content);
	 printf("y: %i\n", s_content->map_max_y);
	 printf("celing: %x\n", s_content->ceiling);
	// printf("y: %i", s_content->map_max_y);

	//init_window(player, content);
	return(0);
}


