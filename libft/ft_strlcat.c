/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:40:56 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/05/24 16:28:11 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	g;
	size_t	t;

	t = ft_strlen(src);
	g = ft_strlen(dst);
	n = 0;
	if (g >= size)
		return (t + size);
	while (g + n < size - 1 && src[n] != '\0')
	{
		dst[n + g] = src[n];
		n++;
	}
	dst[n + g] = '\0';
	return (t + g);
}
