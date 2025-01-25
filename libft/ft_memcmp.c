/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:48:02 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/05/28 04:05:44 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p;
	const unsigned char	*f;
	size_t				i;

	p = (const unsigned char *)s1;
	f = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p[i] != f[i])
		{
			if (p[i] > f[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
