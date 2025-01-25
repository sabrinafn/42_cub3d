/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:21:00 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/05/28 05:29:43 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sizestr(int numb)
{
	int	size;

	size = 0;
	if (numb <= 0)
	{
		size = size + 1;
	}
	while (numb != 0)
	{
		numb = numb / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ptr;
	long	nlong;

	nlong = n;
	size = sizestr (nlong);
	ptr = malloc ((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (nlong < 0)
	{
		nlong = nlong * -1;
		ptr [0] = '-';
	}
	if (nlong == 0)
		ptr[0] = '0';
	ptr[size] = '\0';
	while (size >= 0 && nlong != 0)
	{
		ptr[size - 1] = (nlong % 10) + 48;
		nlong = nlong / 10;
		size--;
	}
	return (ptr);
}
