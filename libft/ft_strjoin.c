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

char *ft_strjoin(char const *s1, char const *s2)
{
	char *src1 = (char *)s1;
	char *src2 = (char *)s2;
	char *result;
	int c;
	int d;

	c = 0;
	d = 0;
	int s1_len = ft_strlen(src1);
	int s2_len = ft_strlen(src2);
	int size = s1_len + s2_len;

	if (!s1 || !s2)
		return NULL;
	result = malloc(sizeof(char *) * size + 1);
	if (result == NULL)
		return NULL;
	while(c < s1_len)
	{
		result[c] = src1[c];
		c++;
	}
	while(c < size)
	{
		result[c]  = src2[d];
		d++;
		c++;
	}
	result[c] = '\0';
	return (result);
}
