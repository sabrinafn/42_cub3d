/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.get_info_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:18:29 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/30 19:49:57 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	get_texture_path(char **matrix, t_content *s_content)
{
	int	cols;
	int	count;

	cols = 0;
	count = 0;
	while (matrix[cols] != NULL)
	{
		count = walk_spaces(matrix[cols]);
		if (matrix[cols][count] == 'N')
			s_content->no_path = get_string(matrix[cols], count + 2);
		else if (matrix[cols][count] == 'S')
			s_content->so_path = get_string(matrix[cols], count + 2);
		else if (matrix[cols][count] == 'E')
			s_content->ea_path = get_string(matrix[cols], count + 2);
		else if (matrix[cols][count] == 'W')
			s_content->we_path = get_string(matrix[cols], count + 2);
		cols++;
	}
	if (!s_content->ea_path || !s_content->no_path || !s_content->so_path
		|| !s_content->we_path)
		return (print_error(ERROR_3));
	return (1);
}

char	*get_string(char *string, int count)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_calloc((ft_strlen(string)), sizeof(char));
	while (string[count] == ' ' || string[count] == '\t')
		count++;
	while (string[count] != '\0' && string[count] != '\n')
	{
		result[i] = string[count];
		i++;
		count++;
	}
	return (result);
}

uint32_t	ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	get_color_number(t_content *s_content)
{
	int	number[3];
	int	number2[3];

	number[0] = ft_atoi(s_content->color_f[0]);
	number[1] = ft_atoi(s_content->color_f[1]);
	number[2] = ft_atoi(s_content->color_f[2]);
	s_content->floor = ft_pixel(number[0], number[1], number[2], 255);
	number2[0] = ft_atoi(s_content->color_c[0]);
	number2[1] = ft_atoi(s_content->color_c[1]);
	number2[2] = ft_atoi(s_content->color_c[2]);
	s_content->ceiling = ft_pixel(number2[0], number2[1], number2[2], 255);
}
