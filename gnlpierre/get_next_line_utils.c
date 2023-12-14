#include "get_next_line.h"

char	*ft_clean(char *raw)
{
	char	*clean;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (!raw)
		return (NULL);
	while (raw[len] != '\n')
		len++;
	clean = malloc(sizeof(char) * len + 2);
	if (!clean)
		return (NULL);
	while (raw && raw[i] != '\n')
	{
		clean[i] = raw[i];
		i++;
	}
	if (raw[i] == '\n')
	{
		clean[i] = raw[i];
		i++;
	}
	clean[i] = '\0';
	free(raw);
	return (clean);
}

int	ft_strlenn(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		len_all;
	int		j;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	len_all = (ft_strlenn(s1) + ft_strlenn(s2));
	result = malloc(sizeof(char) * len_all + 1);
	if (result == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

int	ft_check_n(char *s, int c)
{
	int				i;
	unsigned char	cc;

	cc = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			return (1);
		i++;
	}
	return (0);
}
int	strlen_trunk(char *s)
{
	int i;
	int j;
	int len;

	j = 0;
	i = 0;
	len = 0;
	while (s[i] != '\n')
		i++;
	i++;
	while (s[j] != '\0')
		j++;
	len = j - i;
	return (len);
}