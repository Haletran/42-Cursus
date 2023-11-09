/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:33 by ppitzini          #+#    #+#             */
/*   Updated: 2023/11/09 04:16:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int		c_w;
	int		tmp;

	tmp = 0;
	c_w = 0;
	while (*s != '\0')
	{
		if (tmp == 1 && *s == c)
			in_substring = 0;
		if (tmp == 0 && *s != c)
		{
			tmp = 1;
			c_w++;
		}
		s++;
	}
	return (c_w);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		x;
	int tmp;

	i = 0;
	x = 0;
	if (!s)
		return (NULL);
	tmp = count_words(s, c);
	if (ft_strlen(s) == 0)
		tmp = 0;
	dest = malloc(sizeof(char *) * (tmp + 1));
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