/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:30:20 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/02 14:12:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int check_size(char *src, char *cr)
{
    int c;
    int d;

    c = 0;
    d = ft_strlen(src);
    while(!(src[c] >= 33 && src[c] <= 122) || src[c] == *cr)
        c++;
    while(!(src[d] >= 33 && src[d] <= 122) || src[d] == *cr)
        d--;
    return (d - c);
}

int check_alpha(char *str)
{
    int c;  
    c = 0;

    while (str[c] != '\0')
    {
        if (str[c] >= 33 && str[c] <= 126)
            return 1;
        c++;
    }
    return 0;
}

char *ft_strtrim(char const *s1, char const *set)
{
    int c;
    int d;
    int e;
    char *dest;
    char *empty = "";
    char *src = (char *)s1;
    char *cr = (char *)set;

    e = 0;
    c = 0;
    d = 0;
    if (!s1)
        return NULL;
    d = ft_strlen(s1);
    if (!d || !check_alpha(src))
        return (empty);
    dest = malloc(check_size(src, cr) + 2);
    if (!dest)
        return (NULL);
    while(!(src[c] >= 33 && src[c] <= 126))
        c++;
    while(!(src[d] >= 33 && src[d] <= 126) || src[d] == *cr)
        d--;
    while(c <= d)
    {
        dest[e] = src[c];
        c++;
        e++;
    }
    dest[e] = '\0';
    return (dest);
}

