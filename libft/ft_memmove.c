/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:18:54 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/07 16:39:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char *tmp = (unsigned char *)dest;
	unsigned char *tmp2 = (unsigned char *)src;
	if (size > 0)
	{
		if (src > dest)
			ft_memcpy(tmp, tmp2, size);
		else if (dest > src)
			while(size--)
				tmp[size] = tmp2[size];
	}	
	return (tmp);
}
