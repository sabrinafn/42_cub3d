/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:13:34 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/03/26 17:13:36 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4096
#endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
char *get_next_line(int fd);

#endif
