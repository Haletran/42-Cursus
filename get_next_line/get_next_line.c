/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:23:16 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/30 17:33:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *src)
{
	int		s;
	int		len;
	char	*dest;

	s = 0;
	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (src[s] != '\n')
	{
		dest[s] = src[s];
		s++;
	}
	dest[s] = '\0';
	return (dest);
}

void	ft_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

char	*get_next_line(int fd)
{
	static char *buffer = NULL;
	char *line;
	int reading;

	line = ft_calloc(BUFFER_SIZE + 1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);

	if (!line || !buffer || BUFFER_SIZE <= 0)
	{
		ft_free(buffer, line);
		return (NULL);
	}

	reading = 1;
	while (reading > 0)
	{
		reading = read(fd, buffer, (BUFFER_SIZE - BUFFER_SIZE) + 1);

		if (reading == -1)
		{
			ft_free(buffer, line);
			return (NULL);
		}

		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}

	ft_free(buffer, NULL);
	return (line);
}