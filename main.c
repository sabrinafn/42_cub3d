/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:21:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/10 17:42:02 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int	print_error(char *e)
{
	printf("Error\n%s", e);
	return (1);
}

int check_name(char *argv)
{
	int count;
	count = ft_strlen(argv);
	if (ft_strncmp(&argv[count - 4], ".cub", 4) == 0)
		return (0);
	return (1);
}

int check_arguments(int argc, char *argv)
{

	if(argc == 1)
	{
		write(1, "Error: Not enough params!", 24);
		return(1);
	}
	else if(argc > 2)
	{
		write(1, "Error: Too many params!", 23);
		return(1);
	}
	else if(check_name(argv) == 1)
	{
		write(1, "Error: The file need be .cub\n", 32);
		return(1);
	}
	return(0);
}
int empty_file(char *argv)
{
	int fd;
	char *string;
	
	fd = open(argv, O_RDONLY);
	string = get_next_line(fd);
	if(string == NULL)
		return(print_error(ERROR_2));
	free(string);
	close(fd);
	return(0);
}

int main(int argc, char **argv)
{
	//t_player	*player;
	t_args		*s_map;
	t_content	*content;
	
	//player = NULL;
	s_map = malloc(sizeof(t_args));
	s_map->name_file = argv[1];
	s_map->countcols = countcols(argv[1]);
	s_map->matrix = makematrix(argv[1], s_map->countcols);
	s_map->map_position = find_map2(s_map);
	content = malloc(sizeof(t_content));
	if(check_arguments(argc, argv[1]) == 1)
		return(1);
	if(empty_file(argv[1]) == 1)
		return(1);
	if(read_content(s_map) == 1)
		return(1);
	if(get_info(s_map, content) == 1)
		return(1);
	//init_player_struct(player);
	//init_window(player, content);
	return(0);
}

