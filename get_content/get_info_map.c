/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:23:25 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/24 18:50:17 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	get_map(char **file_matrix, t_content *s_content)
{
	int	i;
	int	j;
	int	lines_map;

	j = 0;
	i = 0;
	lines_map = find_map(file_matrix);
	s_content->map = malloc((lines_map + 1) * sizeof(char *));
	if (!s_content->map)
		return (print_error(ERROR_3));
	while (file_matrix[lines_map] != NULL)
	{
		i = ft_strlen(file_matrix[lines_map]);
		s_content->map[j] = malloc((i + 1) * sizeof(char));
		if (!s_content->map[j])
		{
			free_matrix(s_content->map);
			return (print_error(ERROR_3));
		}
		ft_strlcpy(s_content->map[j], file_matrix[lines_map], i);
		j++;
		lines_map++;
	}
	s_content->map[j] = NULL;
	return (1);
}

void	get_map_sizes_y(t_content *s_content)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s_content->map[i] != NULL)
	{
		while (s_content->map[i][count] == ' ')
			count++;
		if (s_content->map[i][count] == '\n'
			|| s_content->map[i][count] == '\0')
			break ;
		i++;
	}
	s_content->map_max_y = i;
}

void	get_map_sizes_x(t_content *s_content)
{
	int	i;
	int	size_line;
	int	comp_size;

	i = 0;
	size_line = 0;
	comp_size = 0;
	size_line = ft_strlen(s_content->map[i]);
	while (s_content->map[i] != NULL)
	{
		comp_size = ft_strlen(s_content->map[i]);
		if (comp_size > size_line)
			size_line = comp_size;
		i++;
	}
	s_content->map_max_x = size_line;
}
