/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:22:24 by codespace         #+#    #+#             */
/*   Updated: 2023/12/11 14:22:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_nstrlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	size_t	c;
	char	*test;

	c = 0;
	if (elementCount <= 0 || elementSize <= 0)
		return (malloc(1));
	if ((long)elementSize < 0 || (long)elementCount < 0)
		return (NULL);
	test = malloc(elementSize * elementCount);
	if (!test)
		return (NULL);
	while (c < elementSize * elementCount)
		test[c++] = 0;
	return (test);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *src1, char *src2)
{
	char	*result;
	int		c;
	int		d;
	int		len;

	c = 0;
	d = 0;
	if (!src1 && !src2)
		return (NULL);
	len = (ft_strlen(src1) + ft_strlen(src2) + 1);
	result = malloc(sizeof(*result) * len);
	if (result == NULL)
		return (NULL);
	while (c < (int)ft_strlen(src1))
	{
		result[c] = src1[c];
		c++;
	}
	while (c < (int)(ft_strlen(src1) + ft_strlen(src2)))
		result[c++] = src2[d++];
	result[c] = '\0';
	free(src1);
	return (result);
}
