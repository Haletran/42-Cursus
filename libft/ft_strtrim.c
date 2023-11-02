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

char *ft_strtrim(char const *s1, char const *set)
{
    size_t count;
    size_t trimright;
    size_t trimleft;
    trimright = 0;
    count = 0;
    trimleft = 0;
    char *dest;
    char *tr;
    if(!s1)
        return NULL;
    dest = malloc(sizeof(char *) * 10 + 1);
    if (dest == NULL)
        return NULL;
    tr = (char *)s1;
    while(s1[count] == *set)
        count++;
    trimleft = count;
    while(ft_isalnum(ft_atoi(&tr[count])))
    {
        trimright++;
        count++;
    }
    count = 0;
    while(trimleft <= trimright)
    {
        dest[count] = tr[trimleft];
        count++;
        trimleft++;
    }
    dest[count] = '\0';
    return (&dest[count]);  
}

