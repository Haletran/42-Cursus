/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:22:20 by codespace         #+#    #+#             */
/*   Updated: 2023/12/07 10:57:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *line, char *test)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	if (test)
		return (NULL);
	return (test);
}
static char	*ft_n_copy(char *str)
{
    int		i;
    int		j;
    char	*test;

    i = 0;
    j = 0;
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    if (!(test = malloc(ft_strlen(str) - i + 1)))
        return (NULL);
    i++;
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
    if (!(dest = malloc(sizeof(*dest) * (len + 2))))
        return (NULL);
    while (i < len)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\n';
    dest[i + 1] = '\0';
    free(src);
    return (dest);
}

char	*get_next_line(int fd)
{
    static char	*buffer = NULL;
    char		*line;
    int			reading;

    if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
        return (NULL);
    line = ft_calloc(1, 1);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	else if (ft_strlen(buffer) > 0)
		line = ft_strjoin(line, buffer);
    reading = 1;
    while (!(ft_strchr(buffer, '\n')) && reading > 0)
    {
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading <= 0)
			return (ft_free(buffer, line, NULL));
        buffer[reading] = '\0';
        if (reading > 0)
            line = ft_strjoin(line, buffer);
    }
    line = ft_get_line(line);
    buffer = ft_n_copy(buffer);
    return (line);
}
