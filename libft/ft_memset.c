/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:30:48 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/01 11:30:55 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	char	*p;

	p = pointer;
	while (count > 0)
    	{
      	*p = value;
      	p++;
      	count--;
    	}
	return(pointer);
}
