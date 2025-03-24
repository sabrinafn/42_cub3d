/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:00:09 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/24 18:50:53 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	get_content(char **file_matrix, t_content *s_content)
{
	if (!get_map(file_matrix, s_content))
	{
		printf("error when creating map\n");
		return (0);
	}
	if (!get_color(file_matrix, s_content))
	{
		printf("error when creating color\n");
		return (0);
	}
	if (!get_texture_path(file_matrix, s_content))
	{
		printf("error when creating texture\n");
		return (0);
	}
	get_color_number(s_content);
	get_map_sizes_y(s_content);
	get_map_sizes_x(s_content);
	return (1);
}

int	get_color(char **matrix, t_content *s_content)
{
	int		cols;
	int		count;

	count = 0;
	cols = 0;
	while (matrix[cols] != NULL)
	{
		count = walk_spaces(matrix[cols]);
		if (matrix[cols][count] == 'F' || matrix[cols][count] == 'C')
		{
			if (ft_strchr(matrix[cols], 'F') != NULL)
				s_content->color_F = get_color_split(matrix[cols], count);
			else if (ft_strchr(matrix[cols], 'C') != NULL)
				s_content->color_C = get_color_split(matrix[cols], count);
		}
		cols++;
	}
	if (!s_content->color_C || !s_content->color_F)
		return (print_error(ERROR_3));
	return (1);
}

char	**get_color_split(char *string, int count)
{
	char	*temp;
	char	**result;
	int		i;

	i = 0;
	result = NULL;
	temp = ft_calloc(ft_strlen(string), sizeof(char *));
	while (string[count] && (string[count] < '0'
			|| string[count] > '9'))
		count++;
	while (string[count] != '\0' && string[count] != '\n')
	{
		temp[i] = string[count];
		i++;
		count++;
	}
	result = ft_split(temp, ',');
	free(temp);
	return (result);
}
