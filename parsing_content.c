/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:51:41 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/01/30 19:54:13 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int valide_content(t_map s_map)
{
	if(six_content(s_map.matrix) == 1)
		return(1);
	if(validate_element(s_map.matrix) == 1)
		return(1);
	if(valide_numbers(s_map.matrix) == 1)
		return(1);
	if(texture_path(s_map.matrix) == 1)
		return(1);		
	return(0);	
}

int	six_content(char **matrix)
{
	int cols;
	int line;
	int count;

	cols = 0;
	line = 0;
	count = 0;	
	while(matrix[cols] != NULL)
	{
		if(count == 6)
			break;
		line = walk_spaces(matrix[cols]);
		if(matrix[cols][line] == '\0' || matrix[cols][line] == '\n')
			cols++;
		else
		{
			cols++;
			count++;
		}
	}
	if(count != 6)
		return(1);
	return(0);
}

int	validate_element(char **matrix)
{
	int cols;
	int line;
	int count;
	char *temp;
	
	cols = 0;
	line = 0;
	temp = malloc(4 * sizeof(char));
	count = 0;
	while(matrix[cols] != NULL)
	{
		if(count > 6)
			break;
		line = walk_spaces(matrix[cols]);
		if(matrix[cols][line] != '\0')
		{
			if(count < 6)
			{
				temp[0] = matrix[cols][line];
				temp[1] = matrix[cols][line + 1];
				temp[2] = matrix[cols][line + 2];
				temp[3] = '\0';
				if(ft_strncmp(temp, "NO ", 3) == 0 || ft_strncmp(temp, "SO ", 3) == 0 \
					|| ft_strncmp(temp, "WE ", 3) == 0 || ft_strncmp(temp, "EA ", 3) == 0 \
					|| ft_strncmp(temp, "F ", 2) == 0 || ft_strncmp(temp, "C ", 2) == 0)
						count++;		
				else
				{
					free(temp);
					return(1);		
				}		
			}
		}
		cols++;
	}
	free(temp);
	return(0);
}

int valide_numbers(char **matrix)
{
	int cols;
	int count;
	char **temp;
	int number;
	
	temp = NULL;
	count = 0;
	cols = 0;
	while(matrix[cols] != NULL)
	{
		if(ft_strchr(matrix[cols], 'F') != NULL || ft_strchr(matrix[cols], 'C') != NULL)
		{
			count = 0;
			temp = ft_split(matrix[cols], ' ');
			temp = ft_split(temp[1], ',');
			while(temp[count] != NULL)
			{
				number = ft_atoi(temp[count]);
				if(number < 0 || number > 255)
					return(1);
				count++;
			}
			free (temp);
		}
		cols++;
	}
	free(temp);
	return(0);
}

int texture_path(char **matrix)
{
	int cols;
	char **temp;
	int fd;
	
	temp = NULL;
	cols = 0;
	while(matrix[cols] != NULL)
	{
		if(ft_strchr(matrix[cols], 'N') != NULL || ft_strchr(matrix[cols], 'W') != NULL \
		|| ft_strchr(matrix[cols], 'S') != NULL || ft_strchr(matrix[cols], 'E') != NULL)
			{
				temp = ft_split(matrix[cols], ' ');
				printf("%s\n", temp[1]);
				fd = open(temp[1], O_RDONLY);
				if(fd == -1)
				{
					close(fd);
					return(1);
				}
			}
		cols++;	
	}
	return(0);
}