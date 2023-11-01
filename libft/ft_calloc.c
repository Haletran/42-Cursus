/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:42:46 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/01 19:13:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void * ft_calloc( size_t elementCount, size_t elementSize )
{
    size_t c;
    char * test;

    c = 0;
    test = malloc(elementSize * elementCount);
    if (test == NULL)
        return NULL;
    while (c < elementSize*elementCount)
        test[c++] = 0;      
    return (test);
}
