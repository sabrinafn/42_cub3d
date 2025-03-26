/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:13:53 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/26 18:06:58 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int countcols(char *file_name)
{
    int count;
    char *string;
    int fd;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        printf("Error\nImpossible to read the file\n");
        exit(1);
    }
    count = 0;
    while ((string = get_next_line(fd)) != NULL)
    {
        count++;
        free(string);
    }
    close(fd);
	count = (count / 2) + 1;
    return(count);
}




char	**makematrix(char *file_name, int count_cols)
{
	char	**matrix_malloc;
	int		count;
	int		fd;

	count = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nImpossible to read the file\n");
		exit(1);
	}
	matrix_malloc = ft_calloc(count_cols + 1, sizeof(char *));
	if (matrix_malloc == NULL)
	{
		printf("Error\nInvalid malloc\n");
		exit(1);
	}
	while (count < count_cols)
	{
		matrix_malloc[count] = get_next_line(fd);
		printf("%s", matrix_malloc[count]);
		printf("%i\n", count_cols);
		
	//	if (!matrix_malloc[count])
	//	{
			
			//free_matrix(matrix_malloc);
		//	return (NULL);
	//	}
		count++;
	}
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
