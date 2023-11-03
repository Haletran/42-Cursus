/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:18:54 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/03 13:59:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *dest;
    int d;
    unsigned int c;

    c = 0;
    if (!s)
        return NULL;
    d = ft_strlen(s);
    dest = malloc(d + 1);
    if (!dest)
        return NULL;
    while(s[c])
    {
        dest[c] = f(s[c], c);
        c++;
    }
    dest[c] = '\0';
    return (dest);
}
