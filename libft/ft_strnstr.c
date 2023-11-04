/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:34:15 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/02 10:40:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char * str = (char *)big;
    char * to_find = (char *) little;


	i = 0;
	if (to_find[i] == 0)
		return (str);
	while (i < len && str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while ((i + j) < len && to_find[j] && str[i + j] == to_find[j])
			{
				j++;
			}
			if (to_find[j] == 0)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}


