/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:18:54 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/03 13:05:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char uppercase(char c, unsigned int i)
{
    if (i % 2 == 0)
        return toupper(c);
    else
        return tolower(c);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *dest;
    int d;
    int c;

    c = 0;
    d = ft_strlen(s);
    f = uppercase;
    dest = malloc(d + 1);
    if (dest == NULL)
        return NULL;
    while(s[c])
    {
        dest[c] = s[c];
        return(*dest, f);
        c++;
    }
    dest[c] = '\0';
    return (dest);
}
