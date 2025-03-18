/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:51:41 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/18 16:33:04 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int  validate_content(t_args *s_map)
{
	if(!check_elements(s_map->matrix))
		return(0);
	if(!validate_numbers(s_map->matrix))
		return(0);
	//if(!texture_path(s_map->matrix) == 1)
	  	//return(0);		
	return(1);	
}

int	check_elements(char **matrix)
{
	int cols;
	int line;
	int count;

	cols = 0;
	line = 0;
	count = 0;	
	while(matrix[cols] != NULL)
	{
		line = walk_spaces(matrix[cols]);
		if(matrix[cols][line] != '\0' && matrix[cols][line] != '\n')
		{
			printf("%s\n", matrix[cols]);
			if(matrix[cols][line] == '1' || matrix[cols][line] == '0')
				break;
			if(!validate_element(matrix[cols], line))
				return(0);
			else
				count++;
		}
		cols++;
	}
	if(count != 6)	
		return(print_error(ERROR_1));
	return(1);
}

int	validate_element(char *matrix_line, int line_number)
{
	char *temp;
	
	temp = malloc(4 * sizeof(char));
	temp[0] = matrix_line[line_number];
	temp[1] = matrix_line[line_number + 1];
	temp[2] = matrix_line[line_number + 2];
	temp[3] = '\0';
	if(ft_strncmp(temp, "NO ", 3) == 0 || ft_strncmp(temp, "SO ", 3) == 0 \
		|| ft_strncmp(temp, "WE ", 3) == 0 || ft_strncmp(temp, "EA ", 3) == 0 \
		|| ft_strncmp(temp, "F ", 2) == 0 || ft_strncmp(temp, "C ", 2) == 0)
			return(1);
	else
			return(print_error(ERROR_8));
}


int validate_numbers(char **matrix)
{
	int cols;
	int count;
	char *temp;
	int number;
	int i;
	
	i = 0;
	number = 0;
	count = 0;
	cols = 0;
	temp = malloc(4 * sizeof(char));
	while(matrix[cols] != NULL)
	{ 
		count = walk_spaces(matrix[cols]);
		if(matrix[cols][count] == 'F' || matrix[cols][count] == 'C')
		{
			while(matrix[cols][count])
			{
				ft_bzero(temp, 4);
				i = 0;
				temp = malloc(4 * sizeof(char));
				while (matrix[cols][count] && (matrix[cols][count] < '0' || matrix[cols][count] > '9'))
					count++;
				while (matrix[cols][count] && (matrix[cols][count] >= '0' && matrix[cols][count] <= '9'))
				{
					temp[i] = matrix[cols][count]; 
					i++;
					count++;
				}
				temp[i + 1] = '\0';
				number = ft_atoi(temp);
				if(number < 0 || number > 255)
				{
					free(temp);
					return(print_error(ERROR_9));
				}
				if(matrix[cols][count] == '\0')
					break;
			}
		}
		cols++;
	}
	free(temp);
	return(1);
}


int texture_path(char **matrix)
{
	int cols;
	char **temp;
	mlx_texture_t* text;
	
	temp = NULL;
	cols = 0;
	while(matrix[cols] != NULL)
	{
		if(ft_strchr(matrix[cols], 'N') != NULL || ft_strchr(matrix[cols], 'W') != NULL \
		|| ft_strchr(matrix[cols], 'S') != NULL || ft_strchr(matrix[cols], 'E') != NULL)
			{
				temp = ft_split(matrix[cols], ' ');
				text = mlx_load_png(temp[1]);
				if(text == NULL)
				{
					free_matrix(temp);
					return(print_error(ERROR_9));
				}
				
				mlx_delete_texture(text);
				free_matrix(temp);
			}
		cols++;	
	}
	return(1);
}
