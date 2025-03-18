/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcitions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:55:30 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/18 16:00:21 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int	print_error(char *e)
{
	printf("Error\n%s", e);
	return (0);
}

int check_name(char *argv)
{
	int count;
	count = ft_strlen(argv);
	if (ft_strncmp(&argv[count - 4], ".cub", 4) == 0)
		return (1);
	return (0);
}

int check_arguments(int argc, char *argv)
{
	if(argc == 1)
		return(print_error(ERROR_4));
	else if(argc > 2)
		return(print_error(ERROR_5));
	else if(!check_name(argv))
		return(print_error(ERROR_5));
	return(1);
}
int empty_file(char *argv)
{
	int fd;
	char *string;
	
	fd = open(argv, O_RDONLY);
	string = get_next_line(fd);
	if(string == NULL)
		return(print_error(ERROR_2));
	free(string);
	close(fd);
	return(1);
}