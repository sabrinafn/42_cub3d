/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:40:50 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/05/28 05:28:38 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	word_size(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		line;
	int		letter;
	int		i;

	if (s == NULL)
		return (NULL);
	line = 0;
	i = 0;
	words = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!words)
		return (NULL);
	while (line < word_count(s, c))
	{
		letter = 0;
		while (s[i] == c)
			i++;
		words[line] = ft_calloc((word_size(&s[i], c) + 1), sizeof(char));
		if (!words[line])
			return (NULL);
		while (s[i] != c && s[i] != '\0')
			words[line][letter++] = s[i++];
		line++;
	}
	return (words);
}
