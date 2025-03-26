/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:56:55 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/26 17:59:04 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// get_next_line.c
#include "get_next_line.h"

static void ft_strcpy(char *dst, char *src, int len)
{
    int i = 0;
    while (i < len)
    {
        dst[i] = src[i];
        i++;
    }
    dst[len] = '\0';
}

char *get_next_line(int fd)
{
    static char stash[BUFFER_SIZE + 1];
    char buffer[BUFFER_SIZE + 1];
    char *line;
    int bytes_read, i = 0, j = 0, k = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    while (stash[i] && stash[i] != '\n')
        i++;

    if (stash[i] == '\n')
    {
        line = malloc(i + 2);
        if (!line)
            return (NULL);
        ft_strcpy(line, stash, i + 1);
        i++;
        while (stash[i])
            stash[j++] = stash[i++];
        stash[j] = '\0';
        return (line);
    }

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
    {
        if (stash[0] != '\0')
        {
            line = malloc(i + 1);
            if (!line)
                return (NULL);
            ft_strcpy(line, stash, i);
            stash[0] = '\0';
            return (line);
        }
        return (NULL);
    }

    buffer[bytes_read] = '\0';

    while (stash[j])
        j++;

    k = 0;
    while (buffer[k] && j < BUFFER_SIZE)
        stash[j++] = buffer[k++];
    stash[j] = '\0';

    return get_next_line(fd);
}