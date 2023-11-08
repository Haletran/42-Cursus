/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:42:46 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/08 00:27:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	size_t	c;
	char	*test;

	c = 0;
	if((int)elementSize < 0 && (int)elementCount < 0)
		return NULL;
	test = malloc(elementSize * elementCount);
	if (!test)
		return (NULL);
	while (c < elementSize * elementCount)
		test[c++] = 0;
	return (test);
}
