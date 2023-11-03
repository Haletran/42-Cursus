/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:34:15 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/02 11:10:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	c;
	int	d;

	c = 0;
	d = 0;
	while (dest[d] != '\0')
	{
		d++;
	}
	while (src[c] != '\0')
	{
		dest[d] = src[c];
		d++;
		c++;
	}
	dest[d] = '\0';
	return (dest);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *result;
    char *test2 = (char *)s2;
    char *test1 = (char *)s1;

	if(!s1 || !s2)
		return NULL;
    result = malloc(sizeof(char *) * 100);
    if (result == NULL)
        return (NULL);
    result = ft_strcat(test1, test2);
    size_t t = ft_strlen(result);
    result[t] = '\0';
    return(&result[t]);
}
