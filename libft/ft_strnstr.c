/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:56:28 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/05/28 04:02:04 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ib;
	size_t	il;

	ib = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[ib] != '\0' && ib < len)
	{
		il = 0;
		while (big[ib] == little[il] && big[ib] != '\0' && ib < len)
		{
			il++;
			ib++;
		}
		if (little[il] == '\0')
			return ((char *)&big[ib] - il);
		ib = ib - il;
		ib++;
	}
	return (0);
}
