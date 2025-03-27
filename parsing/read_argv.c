/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:13:53 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/27 16:49:17 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int countcols(char *file_name)
{
    int fd;
    int count = 0;
    char *line;

    // Abre o arquivo em modo leitura
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    // Lê as linhas até o fim do arquivo
    while ((line = get_next_line(fd)) != NULL)
    {
        count++;  // Conta cada linha
        free(line);  // Libera a memória alocada para a linha
    }

    close(fd);  // Fecha o arquivo

    return ((count / 2) + 1);  // Retorna o número de linhas
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
		if (!matrix_malloc[count])
			break ;
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
