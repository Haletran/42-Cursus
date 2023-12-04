/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:23:16 by bapasqui          #+#    #+#             */
/*   Updated: 2023/12/04 22:07:12 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char *ft_n_copy(char *str)
{
	int i;
	char *test;
	int j;

	j = 0;
	i = 0;
	while (str[i] != '\n')
		i++;
	test = malloc((ft_strlen(str) - ft_nstrlen(str)));
	if (!test)
		return (NULL);
	i++;
	while (str[i] != '\0')
	{
		test[j] = str[i];
		j++;
		i++;
	}
	test[j] = '\0';
	return (test);
}

char *ft_get_line(char *src)
{
	int i;
	int len;
	char *dest;

	i = 0;
	if (!src)
		return (NULL);
	len = ft_nstrlen(src);
	dest = malloc(sizeof(char) * (len + 2));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\n' && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	free(src);
	return (dest);
}

char *get_next_line(int fd)
{
	static char *buffer = NULL;
	char *line;
	int reading;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	line = ft_calloc(1, 1);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	reading = 1;
	if (ft_strlen(buffer))
		line = ft_strjoin(line, buffer);
	while (!(ft_strchr(buffer, '\n')) && reading > 0)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		buffer[reading] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (reading <= 0)
	{
		free(buffer);
		free(line);
		return (NULL);
	}
	line = ft_get_line(line);
	buffer = ft_n_copy(buffer);
	return (line);
}
