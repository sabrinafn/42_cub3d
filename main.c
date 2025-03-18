/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:21:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/18 18:55:53 by mgonzaga         ###   ########.fr       */
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
	//if(!validate_map(s_map))
	//	return(1);
	//init_player_struct(player);
	if(!get_info(s_map, s_content))
	 	return(1);
	printf("%s\n", s_content->NO_path);
	printf("%s\n", s_content->SO_path);	
	printf("%s\n", s_content->WE_path);	
	printf("%s\n", s_content->EA_path);	
	printf("%s\n", s_content->color_C);
	printf("%s\n", s_content->color_F);
	int i = 0;
	while (s_content->map[i] != NULL)
	{
		printf("%s\n", s_content->map[i]);
		i++;
	}
	//init_window(player, content);
	return(0);
}


