/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:56:55 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/28 16:43:24 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	has_newline(char *saved)
{
	int	i;

	i = 0;
	while (saved[i])
	{
		if (saved[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_line(char *saved, int newline_index)
{
	char	*temp;
	int		j;

	j = 0;
	temp = malloc(newline_index + 2);
	if (!temp)
		return (NULL);
	ft_strcpy(temp, saved, newline_index + 1);
	newline_index++;
	while (saved[newline_index])
		saved[j++] = saved[newline_index++];
	saved[j] = '\0';
	return (temp);
}

char	*flush_saved(char *saved)
{
	char	*temp;
	int		i;

	i = 0;
	while (saved[i])
		i++;
	if (i == 0)
		return (NULL);
	temp = malloc(i + 1);
	if (!temp)
		return (NULL);
	ft_strcpy(temp, saved, i);
	saved[0] = '\0';
	return (temp);
}

void	update(char *temp, char *buffer, int bytes_read)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (temp[j])
		j++;
	while (k < bytes_read && j < BUFFER_SIZE)
		temp[j++] = buffer[k++];
	temp[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	saved[BUFFER_SIZE + 1];
	char		dest_file[BUFFER_SIZE + 1];
	int			len_read;
	int			newline_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newline_index = has_newline(saved);
	if (newline_index >= 0)
		return (get_line(saved, newline_index));
	len_read = read(fd, dest_file, BUFFER_SIZE);
	if (len_read <= 0)
		return (flush_saved(saved));
	dest_file[len_read] = '\0';
	update(saved, dest_file, len_read);
	return (get_next_line(fd));
}
