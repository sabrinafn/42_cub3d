/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:13:53 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/01/24 15:34:06 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	countcols(char *file_name)
{
	int		count;
	char	*string;
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (print_error(ERROR_1));
	count = 0;
	string = get_next_line(fd);
	while (string != NULL)
	{
		count++;
		free(string);
		string = get_next_line(fd);
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
		count++;
	}
	return (matriz_malloc);
}

int	read_content(char *file_name)
{
	t_map s_map;

	s_map.name_file = file_name;
	s_map.matrix = makematrix(file_name, countcols(file_name));
}
