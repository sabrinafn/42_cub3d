/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:51:41 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/13 20:43:48 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int  validate_content(t_args *s_map)
{
	if(!check_elements(s_map->matrix))
		return(1);
	//if(validate_numbers(s_map->matrix) == 1)
		//return(1);
	//if(texture_path(s_map->matrix) == 1)
	  	//return(1);		
	return(0);	
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
	{
		printf("Invalid Numbers Elements\n");	
		return(0);
	}
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
		{
			printf("Invalid Elements\n");	
			return(0);
		}
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
	temp = NULL;
	while(matrix[cols] != NULL)
	{ 
		count = walk_spaces(matrix[cols]);
		if(matrix[cols][count] == 'F' || matrix[cols][count] == 'C')
		{
				count = 0;
				if(ft_strchr("1234567890", matrix[cols][count]))
				{
					while(ft_strchr("1234567890", matrix[cols][count]))
					{
						temp[i]= matrix[cols][count];
						i++;
						count++;
					}
					temp[i] = '\0';
					printf("%s\n",temp);
					number = ft_atoi(temp);
					if(number < 1 || number > 255)
						return(1);
					free(temp);
				}
		}
		count++;
		cols++;
	}
	return(0);
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
					printf("invalid taxture\n");
					return(1);
				}
				
				mlx_delete_texture(text);
				free_matrix(temp);
			}
		cols++;	
	}
	return(0);
}
