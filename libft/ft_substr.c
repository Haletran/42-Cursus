/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:42:46 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/08 14:12:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_check_input(char const *s, unsigned int start, size_t len)
{
	if (start > ft_strlen(s))
		return(len = 0);
	if (len > strlen(s) - start)
		return(len = strlen(s) - start);
	return(len);	
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t size;

	i = 0;
	j = 0;
	size = ft_check_input(s, start, len);
	if (!s)
		return (NULL);
	ptr = malloc(sizeof(size + 1));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
