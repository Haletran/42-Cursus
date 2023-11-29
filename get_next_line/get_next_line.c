/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:23:16 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/29 18:31:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
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
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
char	*get_str(char *src1, char *src2)
{
	char	*result;
	int		c;
	int		d;
	int		len;

	c = 0;
	d = 0;
	if (src1 == NULL || src2 == NULL)
		return (NULL);
	len = ft_strlen(src1) + ft_strlen(src2);
	result = malloc(sizeof(*result) * len + 1);
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
char	*ft_strcpy(char *dest, char *src)
{
	int	s;

	s = 0;
	while (src[s] != '\n')
	{
		dest[s] = src[s];
		s++;
	}
	dest[s] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char *line;
	int reading;

	line = ft_calloc(BUFFER_SIZE + 1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reading = 1;
	while (reading > 0)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		line = ft_strjoin(line, buffer);
		line[reading] = '\0';
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}