/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05.character_mapvalidation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:25:28 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/30 19:48:48 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	invalid_character(char **file_matrix)
{
	int	cols;

	cols = find_map(file_matrix);
	while (file_matrix[cols] != NULL)
	{
		if (!validate_char(file_matrix[cols]))
			return (0);
		cols++;
	}
	return (1);
}

int	validate_char(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (ft_strchr("0NSEW1 \n", string[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}
