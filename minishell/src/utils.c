/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:09:45 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/12 17:22:49 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_nbargs(char **str)
{
	int	size;

	size = 0;
	while (*str)
	{
		size++;
		str++;
	}
	return (size);
}

void	get_exit_code(t_lst *args)
{
	if (WIFEXITED(args->exit_code))
		args->exit_code = WEXITSTATUS(args->exit_code);
	else if (WIFSIGNALED(args->exit_code))
		args->exit_code = WTERMSIG(args->exit_code) + 128;
	else if (WIFSTOPPED(args->exit_code))
		args->exit_code = WSTOPSIG(args->exit_code);
}

void	print_commands(char **src)
{
	int	i;

	i = 0;
	while (src[i])
		printf("%s\n", src[i++]);
}

char	*ft_join(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2 + 1);
	return (result);
}

int	get_len(char **str)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			j++;
			size++;
		}
		i++;
	}
	return (size);
}

int	check_space(char *str)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (str[i])
	{
		if (str[i] == 32)
			space++;
		i++;
	}
	if (space == i)
		return (1);
	return (0);
}

int	check_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
