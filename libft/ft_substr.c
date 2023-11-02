/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:42:46 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/02 12:36:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	size_t c;

	c = 0;
	while (src[c] != '\0' && c < n)
	{
		dest[c] = src[c];
		c++;
	}
	while (c < n)
	{
		dest[c] = '\0';
		c++;
	}
	return (dest);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *dest;
    char *tmp = (char *)s;


    dest = malloc(len + 1);
    if (dest == NULL)
        return NULL;
    if (len > 0 && (!(start >= ft_strlen(s))))
    {
        ft_strncpy(dest, &tmp[start], len);
        dest[len] = '\0';
        return(dest);
    }
    return 0;
}