/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:34:53 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/28 14:52:23 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	validate_content(char **matrix_file)
{
	if (!check_elements(matrix_file))
		return (0);
	if (!validate_numbers(matrix_file))
		return (0);
	if (!texture_path(matrix_file))
		return (0);
	if (!validation_map(matrix_file))
		return (0);
	return (1);
}

int	validation_map(char **file_matrix)
{
	if (!validate_wall(file_matrix))
	return (print_error(ERROR_13));
	if (!invalid_character(file_matrix))
		return (print_error(ERROR_12));
	if (!find_player(file_matrix))
		return (print_error(ERROR_11));
	if (!empty_line(file_matrix))
		return (print_error(ERROR_14));
	return (1);
}
