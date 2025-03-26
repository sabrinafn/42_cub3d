/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:58:23 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/26 15:10:35 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	check_arguments(int argc, char *argv)
{
	if (argc == 1)
		return (print_error(ERROR_4));
	else if (argc > 2)
		return (print_error(ERROR_5));
	else if (!check_name(argv))
		return (print_error(ERROR_6));
	else if (!empty_file(argv))
		return (print_error(ERROR_2));
	return (1);
}

int	check_name(char *argv)
{
	int	count;

	count = ft_strlen(argv);
	if (ft_strncmp(&argv[count - 4], ".cub", 4) == 0)
		return (1);
	return (0);
}

int	empty_file(char *argv)
{
	int		fd;
	char	*string;
	
	fd = open(argv, O_RDONLY);
	string = get_next_line(fd);
	if (string == NULL)
	{
		free(string);
		close(fd);
		return (0);
	}
	free(string);
	close(fd);
	return (1);
}
