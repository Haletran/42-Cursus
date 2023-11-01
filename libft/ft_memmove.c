/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:18:54 by bapasqui          #+#    #+#             */
/*   Updated: 2023/10/31 14:55:23 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t c;
	char *save[80];
	
	char *temps = (char *)src;
	char *tempd = (char *)dest;

	c = 0;
	if (ft_strlen(dest) > ft_strlen(src))
	{
		while(temps[c] != '\0')
		{
			save[c] = &temps[c];
			c++;
		}
		c = 0;
		while (c < ft_strlen(src))
		{
			tempd[c] = *save[c];
			c++;
		}
		return (tempd);
	}
	else
		ft_memcpy(dest, src, size);	
	return (dest);
}
