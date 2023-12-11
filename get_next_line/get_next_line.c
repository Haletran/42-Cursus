/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:22:20 by codespace         #+#    #+#             */
/*   Updated: 2023/12/11 15:44:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_n_copy(char *str)
{
	int		i;
	int		j;
	char	*test;

	j = 0;
	if (!str)
		return (NULL);
	i = ft_nstrlen(str) + 1;
	test = malloc((ft_strlen(str) - ft_nstrlen(str)) + 1);
	if (!test)
		return (NULL);
	while (str[i] != '\0')
	{
		test[j] = str[i];
		j++;
		i++;
	}
	test[j] = '\0';
	free(str);
	return (test);
}
static char	*ft_get_line(char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	if (!src)
		return (NULL);
	len = ft_nstrlen(src);
	dest = malloc((sizeof(*dest) * len) + 2);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save;
	char		*line;
	int			reading;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	reading = 1;
	while (!(ft_strchr(save, '\n')) && reading > 0)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading <= 0)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[reading] = '\0';
		if (reading > 0)
			save = ft_strjoin(save, buffer);
	}
	line = ft_get_line(save);
	save = ft_n_copy(save);
	free(buffer);
	return (line);
}
