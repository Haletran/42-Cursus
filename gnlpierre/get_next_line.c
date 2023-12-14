#include "get_next_line.h"

char	*get_rest(char *tmp, char *s)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i] != '\n' || '\0')
		i++;
	i++;
	tmp = malloc(strlen_trunk(s) + 1);
	if (!tmp)
		return (NULL);
	while (s[i] != '\0')
	{
		tmp[j] = s[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			nb_read;
	char		*buffer;
	static char	*tmp = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (tmp)
	{
		line = ft_strjoin(line, tmp);
		free(tmp);
	}
	nb_read = 1;
	while (nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read <= 0)
			break ;
		buffer[nb_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_check_n(line, '\n'))
			break ;
	}
	if (nb_read <= 0)
	{
		free(buffer);
		free(line);
		return (NULL);
	}
	tmp = get_rest(tmp, line);
	line = ft_clean(line);
	free(buffer);
	buffer = NULL;
	return (line);
}

int	main(void)
{
	int fd;
	char *line;

	fd = open("../libft/ft_atoi.c", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	return (0);
}