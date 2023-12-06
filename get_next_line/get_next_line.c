/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:22:20 by codespace         #+#    #+#             */
/*   Updated: 2023/12/06 17:41:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free(char *src)
{
	free(src);
	src = 0;
	return (0);
}

static char	*ft_n_copy(char *str)
{
	int		i;
	char	*test;
	int		j;

	j = 0;
	i = 0;
	while (str[i] != '\n')
		i++;
	test = malloc((ft_strlen(str) - ft_nstrlen(str)) + 1);
	if (!test)
	{
		ft_free(str);
		return (NULL);
	}
	i++;
	while (str[i] != '\0')
	{
		test[j] = str[i];
		j++;
		i++;
	}
	test[j] = '\0';
	ft_free(str);
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
	if (!len)
		return (NULL);
	dest = malloc(sizeof(*dest) * (len + 2));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	ft_free(src);
	return (dest);
}

char	*process_buffer(int fd, char **line, char **buffer)
{
	int	reading;

	reading = 1;
	if (ft_strlen(*buffer))
	{
		*line = ft_strjoin(*line, *buffer);
		ft_free(*buffer);
	}
	while (!(ft_strchr(*buffer, '\n')) && reading > 0)
	{
		reading = read(fd, *buffer, BUFFER_SIZE);
		if (reading <= 0)
		{
			free(*buffer);
			*buffer = 0;
			free(*line);
			*line = 0;
			return (NULL);
		}
		(*buffer)[reading] = '\0';
		*line = ft_strjoin(*line, *buffer);
	}
	*line = ft_get_line(*line);
	*buffer = ft_n_copy(*buffer);
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	line = ft_calloc(1, 1);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	line = process_buffer(fd, &line, &buffer);
	return (line);
}
