/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:51:41 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/25 16:17:19 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	check_elements(char **matrix)
{
	int	cols;
	int	line;
	int	count;

	cols = 0;
	line = 0;
	count = 0;
	while (matrix[cols] != NULL)
	{
		line = walk_spaces(matrix[cols]);
		if (matrix[cols][line] != '\0' && matrix[cols][line] != '\n')
		{
			if (matrix[cols][line] == '1')
				break ;
			if (!validate_element(matrix[cols], line))
				return (0);
			else
				count++;
		}
		cols++;
	}
	if (count != 6)
		return (print_error(ERROR_7));
	return (1);
}

int	validate_element(char *matrix_line, int line_number)
{
	char	*temp;

	temp = malloc(4 * sizeof(char));
	temp[0] = matrix_line[line_number];
	temp[1] = matrix_line[line_number + 1];
	temp[2] = matrix_line[line_number + 2];
	temp[3] = '\0';
	if (ft_strncmp(temp, "NO ", 3) == 0 || ft_strncmp(temp, "SO ", 3) == 0 \
		|| ft_strncmp(temp, "WE ", 3) == 0 || ft_strncmp(temp, "EA ", 3) == 0 \
		|| ft_strncmp(temp, "F ", 2) == 0 || ft_strncmp(temp, "C ", 2) == 0)
	{
		free (temp);
		return (1);
	}	
	else
	{
		free (temp);
		return (print_error(ERROR_8));
	}
}

int	validate_numbers(char **matrix)
{
	int	cols;
	int	count;

	count = 0;
	cols = 0;
	while (matrix[cols] != NULL)
	{
		count = walk_spaces(matrix[cols]);
		if (matrix[cols][count] == 'F' || matrix[cols][count] == 'C')
		{
			if (!check_numbers(matrix[cols], count))
				return (print_error(ERROR_9));
		}
		cols++;
	}
	return (1);
}

int	check_numbers(char *string, int count)
{
	int		number;
	char	*temp;
	int		i;

	temp = malloc(4 * sizeof(char));
	number = 0;
	i = 0;
	while (string[count])
	{
		ft_bzero(temp, 4);
		i = 0;
		while (string[count] && (string[count] < '0' || string[count] > '9'))
			count++;
		while (string[count] && (string[count] >= '0' && string[count] <= '9'))
			temp[i++] = string[count++];
		number = ft_atoi(temp);
		if (number < 0 || number > 255)
		{
			free (temp);
			return (0);
		}
	}
	free (temp);
	return (1);
}

int	texture_path(char **m)
{
	int				cols;
	char			**temp;
	mlx_texture_t	*text;
	int				count;

	cols = 0;
	while (m[cols] != NULL)
	{
		count = walk_spaces(m[cols]);
		if (m[cols][count] == 'N' || m[cols][count] == 'W' \
		|| m[cols][count] == 'S' || m[cols][count] == 'E')
		{
			temp = ft_split(m[cols], ' ');
			//temp[1][ft_strlen(temp[1] - 1)] = '\0';
			text = mlx_load_png(temp[1]);
			if (text == NULL)
			{
				free_matrix(temp);
				return (print_error(ERROR_15));
			}
			mlx_delete_texture(text);
			free_matrix(temp);
		}
		cols++;
	}
	return (1);
}
