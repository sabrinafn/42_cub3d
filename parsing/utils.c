/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:05:51 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/24 14:41:09 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	print_error(char *e)
{
	printf("Error\n%s", e);
	return (0);
}

int walk_spaces(char *string)
{
	int i;

	i = 0;
	while(string[i] == ' ' || string[i] == '\n' || string[i] == '\t')
		i++;
	return(i);	
}

void	free_matrix(char **malloc_string)
{
	int	count;

	count = 0;
	if (!malloc_string)
		return ;
	while (malloc_string[count] != NULL)
	{
		free(malloc_string[count]);
		count++;
	}
	free(malloc_string);
}