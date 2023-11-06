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

int ft_count(char *src, char *cr)
{
    int c;
    int d;

    d = 0;
    c = 0;
    while(src[c] != '\0')
    {
        if (src[c] == cr[c])
            d++;
        c++;
    }
    return(d);
}

char *ft_strtrim(char const *s1, char const *set)
{
    int c;
    int d;
    char *dest;
    char *src = (char *)s1;
    char *cr = (char *)set;

    c = 0;
    d = 0;
    if (!s1)
        return NULL;
    c = 0;
    d = ft_strlen(s1) - ft_count(src,  cr);
    dest = malloc(sizeof(char *));
    if (!dest)
        return (NULL);
    return (dest);

    




}

