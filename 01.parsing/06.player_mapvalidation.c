/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mapvalidation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:32:30 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/27 18:16:05 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	only_player(char *string)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (string[i] != '\0')
	{
		if (ft_strchr("NSEW", string[i]))
			count++;
		i++;
	}
	return (count);
}

int	find_player(char **file_matrix)
{
	int	cols;
	int	count;

	count = 0;
	cols = find_map(file_matrix);
	while (file_matrix[cols] != NULL)
	{
		count = count + only_player(file_matrix[cols]);
		cols++;
	}
	if (count > 1 || count == 0)
		return (0);
	return (1);
}
