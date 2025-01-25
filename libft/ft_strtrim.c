/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:03:41 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/05/28 04:03:12 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		i;
	size_t		n;
	char		*ptr;

	i = 0;
	n = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (s1[n] != '\0')
		n++;
	while (n > i && ft_strrchr(set, s1[n - 1]))
		n--;
	ptr = ft_substr(s1, i, n - i);
	return (ptr);
}
