/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:02:38 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/06/23 18:28:53 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*malloc_line(char *str)
{
	int		count;
	char	*line;

	count = 0;
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	if (ft_strchr(str, '\n'))
		line = malloc((count + 2) * sizeof(char));
	else
		line = malloc((count + 1) * sizeof(char));
	return (line);
}

static char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	line = malloc_line(str);
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (ft_strchr(str, '\n'))
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	free(str);
	return (line);
}

static char	*get_rest(char *str)
{
	int		count;
	int		i;
	char	*rest;

	count = 0;
	i = 0;
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	rest = malloc(((ft_strlen(str) - count) + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	if (str[count] != '\0')
		count++;
	while (str[count] != '\0')
	{
		rest[i++] = str[count++];
	}
	rest[i] = '\0';
	if (rest[0] == '\0')
	{
		free(rest);
		rest = NULL;
	}
	return (rest);
}

char	*len_free(char *dest_file, char *temp, char **rest)
{
	free (dest_file);
	free (temp);
	*rest = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*dest_file;
	char		*temp;
	static char	*rest;
	ssize_t		len_read;

	temp = rest;
	if (BUFFER_SIZE <= 0 && fd < 0)
		return (NULL);
	dest_file = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!dest_file)
		return (NULL);
	len_read = 1;
	while (!ft_strchr(dest_file, '\n') && len_read != 0)
	{
		len_read = read(fd, dest_file, BUFFER_SIZE);
		if (len_read < 0)
			return (len_free (dest_file, temp, &rest));
		dest_file[len_read] = '\0';
		temp = ft_strjoin(temp, dest_file);
	}
	rest = get_rest(temp);
	temp = get_line(temp);
	free(dest_file);
	return (temp);
}
