/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:18:54 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/01 22:22:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void * ft_memchr( const void * memoryBlock, int searchedChar, size_t size )
{
    size_t c;
    char *mem = (char *)memoryBlock;
    
    c = 0;
    while (c < size)
    {
            if (mem[c] == searchedChar)
                return (&mem[c]);
            c++;        
    }
    return (0);    
}