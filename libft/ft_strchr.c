/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:05:42 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/01 22:21:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int to_find)
{
	int	c;
	int d;
	char *test;

	c = 0;
	d = 0;
	test = 0;
	while (str[c])
	{
		if (str[c] == (unsigned char)to_find)
			d++;
		c++;
	}
	c = 0;
	if (d > 0)
	{
		while(str[d] != '\0')
			test[c++] = str[d++];
		test[c] = '\0';
		return (&test[c]);
	}
	return 0;
}
