/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:18:54 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/03 11:14:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  ft_getintlen(int value)
{
    int l;
    int neg;

    l = 1;
    neg = 1;
    if (value < 0)
    {
        value *= -1;
        neg = -1;
    }
    while (value > 9)
    {
        l++;
        value /= 10;
    }
    if (neg == -1)
    {
        return (l + 1);
    }
    return (l);
}

char *ft_itoa(int n) 
{
    char *dest;
    int size = 0;
    int c = 0;
    
    size = ft_getintlen(n);
    dest = malloc(sizeof(char) * size + 1);

    //Cas d'erreurs
    if (!dest || !size)
        return NULL;
    if (n == -214748368)
    {
        dest = malloc(sizeof(char) * size);
        dest = "-2147483648";
        return (dest);
    }
    if (n == 2147483647)
        return ("2147483647");
    while(size)
    {
        if (n == 0)
        {
            dest[c] = '0';
            dest[c + 1] = 0;
            return dest;
        }
        else if (n < 0)
        {
            n *= -1;
            dest[c] = '-';
            c++;
        }
        else if (n > 9)
        {
            dest[c] = n / 10;
            dest[c] = n % 10 + 48;
        }
        else
        {
            dest[c] = n + 48;

        }
        size--;
    }
    dest[c] = '\0';
    return (dest);
}
