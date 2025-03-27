/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:56:55 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/27 16:41:14 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int has_newline(char *saved)
{
    int i = 0;

    while (saved[i])
    {
        if (saved[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char *extract_line(char *saved, int newline_index)
{
    char *temp;
    int j;

    j = 0;
    if (!(temp = malloc(newline_index + 2)))
        return (NULL);
    ft_strcpy(temp, saved, newline_index + 1);
    newline_index++;
    while (saved[newline_index])
        saved[j++] = saved[newline_index++];
    saved[j] = '\0';
    return (temp);
}

char *flush_saved(char *saved)
{
    char *temp;
    int i = 0;

    while (saved[i])
        i++;
    if (i == 0)
        return (NULL);
    if (!(temp = malloc(i + 1)))
        return (NULL);
    ft_strcpy(temp, saved, i);
    saved[0] = '\0';
    return (temp);
}

void update_saved(char *saved, char *buffer, int bytes_read)
{
    int j = 0, k = 0;

    while (saved[j])
        j++;
    while (k < bytes_read && j < BUFFER_SIZE)
        saved[j++] = buffer[k++];
    saved[j] = '\0';
}

char *get_next_line(int fd)
{
    static char saved[BUFFER_SIZE + 1];
    char dest_file[BUFFER_SIZE + 1];
    int len_read, newline_index;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if ((newline_index = has_newline(saved)) >= 0)
        return (extract_line(saved, newline_index));

    len_read = read(fd, dest_file, BUFFER_SIZE);
    if (len_read <= 0)
        return (flush_saved(saved));

    dest_file[len_read] = '\0';
    update_saved(saved, dest_file, len_read);

    return get_next_line(fd);
}
