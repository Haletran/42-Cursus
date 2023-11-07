/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:42:46 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/07 16:45:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char *src, char del)
{
	int	c;
	int	d;
	int	tmp;

	d = 0;
	c = 0;
	while (c <= (int)ft_strlen(src))
	{
		while (src[c] != del)
			d++;
		if (d > 1)
			d--;
		tmp = tmp + d;
		c++;
	}
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	int		d;
	char	**dest;
	char	*src;
	int		size;

	src = (char *)s;
	d = 0;
	src = 0;
	size = (ft_strlen(src) - count_words(src, c));
	if (!src && !c)
		return (NULL);
	dest = malloc(sizeof(char *) * size + 1);
	if (!dest)
		return (NULL);
	return (dest);
}
