/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:14:35 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/05/28 04:22:40 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*c;
	char		*f;

	i = 0;
	c = src;
	f = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > i)
	{
		f[i] = c[i];
		i++;
	}
	return (dest);
}
