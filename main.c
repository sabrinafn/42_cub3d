/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:21:32 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/01/24 15:22:30 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(char *e)
{
	printf("Error\n%s", e);
	return (0);
}

int check_name(char *argv)
{
	int count;
	count = ft_strlen(argv);
	if (ft_strncmp(argv[count - 4], ".cub", 4) == 0)
		return (0);
	return (1);
}

int check_arguments(int argc, char *argv)
{
	int	count;
	
	if(argc == 1)
	{
		write(1, "Error: Not enough params!", 24);
		return(1);
	}
	else if(argc > 2)
	{
		write(1, "Error: Too many params!", 23);
		return(1);
	}
	else if(check_name(argv) == 1)
	{
		write(1, "Error: The file need be .cub\n", 32);
		return(1);
	}
	return(0);
}

int main(int argc, char **argv)
{
	if(check_arguments(argc, argv[1]) == 1)
		return(1);
	validação aquivo vazio;
	read_content(argv[1]);
	
	
}