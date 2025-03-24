/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:34:53 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/24 14:28:54 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int validation_map(char **file_matrix)
{
	if(!find_player(file_matrix))
		return(print_error(ERROR_11));
	if(!invalid_character(file_matrix))
		return(print_error(ERROR_12));
	if(!validate_wall(file_matrix))
		return(print_error(ERROR_13));
	if(!empty_line(file_matrix))
		return(print_error(ERROR_14));
	return(1);
}

