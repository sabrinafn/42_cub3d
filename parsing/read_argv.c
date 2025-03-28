/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:13:53 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/28 14:52:12 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	countcols(char *file_name)
{
	int		count;
	char	*string;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		print_error(ERROR_1);
		exit(1);
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
	free(string);
	count = (count / 2) + 1;
	return (count);
}

char	**makematrix(char *file_name, int count_cols)
{
	char	**matrix_malloc;
	int		count;
	int		fd;

	count = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit(print_error(ERROR_1) + 1);
	matrix_malloc = ft_calloc(count_cols + 1, sizeof(char *));
	if (matrix_malloc == NULL)
		exit(print_error(ERROR_3) + 1);
	while (count < count_cols)
	{
		matrix_malloc[count] = get_next_line(fd);
		if (!matrix_malloc[count])
		{
			free_matrix(matrix_malloc);
			break ;
		}
		count++;
	}
	close(fd);
	return (matrix_malloc);
}

int	find_map(char **file_matrix)
{
	int	lines_map;
	int	count;

	lines_map = 0;
	count = 0;
	while (file_matrix[lines_map] != NULL)
	{
		count = walk_spaces(file_matrix[lines_map]);
		if (file_matrix[lines_map][count] == '1')
			break ;
		lines_map++;
	}
	return (lines_map);
}
