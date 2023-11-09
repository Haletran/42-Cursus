/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:33 by ppitzini          #+#    #+#             */
/*   Updated: 2023/11/09 01:34:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int		i;
	int		l;
	int		tmp;
	int		c_w;

	c_w = 0;
	tmp = 0;
	l = 0;
	i = 0;
	if (s[0] != '\0' && s[0] != c)
		c_w++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			l++;
			tmp = tmp + l;
		}
		else
			c_w++;
		l = 0;
		i++;
	}
	return (c_w);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		x;

	x = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char **) * count_words(s, c) + 1);
	if (!dest)
		return (NULL);
	while (*s)
	{
		if (s[0] == c)
			s++;
		else
		{
			i = 0;
			while (s[i] != '\0' && s[i] != c)
				i++;
			dest[x++] = ft_substr(s, 0, i);
			s = s + i;
		}
	}
	dest[x] = NULL;
	return (dest);
}
