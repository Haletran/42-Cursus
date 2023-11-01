/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:54:50 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/01 12:39:08 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
    t_size_t    srclen;

    srclen = ft_strlen(src);
    if (srclen + 1 < size)
    {
        ft_memcpy(dest, src, srclen + 1);
    }
    else if (size != 0)
    {
        ft_memcpy(dest, src, size - 1);
        dest[size - 1] = '\0';
    }
    return (srclen);
}



