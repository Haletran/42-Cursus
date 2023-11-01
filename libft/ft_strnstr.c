/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:34:15 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/01 20:03:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char * ft_strnstr(const char *big,	const char *little, size_t len)
{
	size_t c;
	size_t d;

	c = 0;
	d = 0;
    char * str = (char *)big;
    char * to_find = (char *) little;
	if (to_find[c] == '\0')
		return (str);
	while (c < len)
	{
		while (str[c + d] == to_find[d])
		{
			if (to_find[d + 1] == '\0')
				return (&str[c]);
            d++;
		}
			c++;
	}
	return (0);
}