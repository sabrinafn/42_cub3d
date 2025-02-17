/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:51:41 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/02/01 19:56:59 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_3d.h"

int valide_content(t_map s_map)
{
	if(six_content(s_map.matrix) == 1)
		return(1);
	if(validate_element(s_map.matrix) == 1)
		return(1);
	if(valide_numbers(s_map.matrix) == 1)
		return(1);
	//if(texture_path(s_map.matrix) == 1)
	  	//return(1);		
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
		line = walk_spaces(matrix[cols]);
		if(matrix[cols][line] == '\0' || matrix[cols][line] == '\n')
			cols++;
		else
		{
			if(matrix[cols][line] == '1')
				break;
			cols++;
			count++;
		}
	}
	if(count != 6)
	{
		printf("Invalid number of elements\n");	
		return(1);
	}
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
					printf("invalid Elements\n");
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
	//int number;
	char **temp2;
	int i;

	i = 0;
	temp2 = NULL;
	temp = NULL;
	count = 0;
	cols = 0;
	while(matrix[cols] != NULL)
	{
		if(ft_strchr(matrix[cols], 'F') != NULL || ft_strchr(matrix[cols], 'C') != NULL)
		{
			count = 0;
			temp = ft_split(matrix[cols], ' ');
			temp2 = ft_split(temp[1], ',');
			while(temp2[count] != NULL)
			{
				while (temp2[count][i] != '\0')
				{
					printf("%c", temp2[count][i]);
					// if(ft_strchr("1234567890", temp2[count][i]) == NULL)
					// {
					// 	free_matrix (temp);
					// 	free_matrix (temp2);
					// 	printf("Invalid colokjkljlkrs\n");	
					// 	return(1);
					// }
					i++;
				}
				// number = ft_atoi(temp2[count]);
				// if( number < 0 || number  > 255 || count > 3)
				// {
				// 	free_matrix (temp);
				// 	free_matrix (temp2);
				// 	printf("Invalid colors\n");	
				// 	return(1);
				// }
				count++;
			}
			free_matrix (temp); 
			free_matrix (temp2);
		}
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
