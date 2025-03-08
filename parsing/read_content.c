/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:13:53 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/02/19 14:54:20 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	countcols(char *file_name)
{
	int		count;
	char	*string;
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		print_error(ERROR_1);
		exit(0);
	}
	count = 0;
	while (1)
	{
		string = get_next_line(fd);
		if (!string)
			break ;
		count++;
		free (string);

	}
	close(fd);
	return (count);
}

char	**makematrix(char *file_name, int count_cols)
{
	char	**matriz_malloc;
	int		count;
	int		fd;
	
	count = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit(print_error(ERROR_1));
	matriz_malloc = ft_calloc (count_cols + 1, sizeof(char *));
	if (matriz_malloc == NULL)
		exit(print_error(ERROR_3));
	while (count < count_cols)
	{
		matriz_malloc[count] = get_next_line(fd);
		if (!matriz_malloc[count])
			return (NULL);
		count++;
	}
	return (matriz_malloc);
}

int	read_content(t_map *s_map, char *file_name)
{
	s_map->name_file = file_name;
	s_map->countcols = countcols(file_name);
	s_map->matrix = makematrix(file_name, s_map->countcols);
	if(validate_content(s_map))
	{
		free_matrix(s_map->matrix);
		printf("deu errado");
		return(1);
	}
	s_map->map_position = find_map2(s_map);
	if (validate_map(*s_map) == 1)
	{
		free_matrix(s_map->matrix);
		return(1);
	}
	free_matrix(s_map->matrix);
	return(0);	
}

