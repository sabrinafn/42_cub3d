/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:45:36 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/05/29 14:04:24 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	r1;
	size_t	r2;
	size_t	t;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	r1 = ft_strlen (s1);
	r2 = ft_strlen (s2);
	t = r1 + r2;
	ptr = malloc((t + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, s1, r1);
	ft_memmove(&ptr[r1], s2, r2);
	ptr[t] = '\0';
	return (ptr);
}
