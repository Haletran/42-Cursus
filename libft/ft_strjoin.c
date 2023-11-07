/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:34:15 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/07 16:33:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_str(char *src1, char *src2)
{
	char	*result;
	int		c;
	int		d;

	c = 0;
	d = 0;
	result = malloc(sizeof(char *) * (ft_strlen(src1) + ft_strlen(src2)) + 1);
	if (result == NULL)
		return (NULL);
	while (c < (int)ft_strlen(src1))
	{
		result[c] = src1[c];
		c++;
	}
	while (c < (int)(ft_strlen(src1) + ft_strlen(src2)))
	{
		result[c] = src2[d];
		d++;
		c++;
	}
	result[c] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*src1;
	char	*src2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	src1 = (char *)s1;
	src2 = (char *)s2;
	result = (get_str(src1, src2));
	return (result);
}
