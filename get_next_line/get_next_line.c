/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:22:20 by codespace         #+#    #+#             */
/*   Updated: 2023/12/12 15:34:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_n_copy(char *str)
{
	int		i;
	int		j;
	char	*test;

	j = 0;
	if (!str)
		return (NULL);
	i = ft_nstrlen(str);
	test = malloc(ft_strlen(str + i) + 1);
	while (str[i])
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
	dest = malloc((sizeof(*dest) * len) + 1);
	if (!dest)
		return (NULL);
	while (i < len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_read(int fd, char *buffer, char *save)
{
	int	reading;

	reading = 1;
	while (!(ft_strchr(save, '\n')) && reading > 0)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading <= 0)
			break ;
		buffer[reading] = '\0';
		save = ft_strjoin(save, buffer);
		if (ft_strchr(save, '\n'))
			break ;
	}
	if (reading < 0 || (reading == 0 && !ft_strlen(save)))
	{
		free(save);
		return (NULL);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(*buffer) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	save = ft_read(fd, buffer, save);
	free(buffer);
	line = ft_get_line(save);
	save = ft_n_copy(save);
	return (line);
}
