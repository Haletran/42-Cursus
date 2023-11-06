/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:18:54 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/02 15:59:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int c;
    char *dest;
    int size;

    c = 0;
    dest = (char *)f;
    if (!s)
        return ;
    size = ft_strlen(s);
    dest = malloc(size + 1);
    if (!dest)
        return ;
    while(s[c])
    {
        f(c, &s[c]);
        c++;
    }
}
