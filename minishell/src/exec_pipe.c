/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:54:32 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/12 16:40:53 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_split2(char *str, char *delim)
{
	int		num_words;
	char	**words;

	int i, j, k;
	num_words = 0;
	char *start, *end;
	// Count the number of words in the string
	i = 0;
	while (str[i] != '\0')
	{
		if (strstr(&str[i], delim) == &str[i])
		{
			i += ft_strlen(delim);
		}
		else if (str[i] != '\0')
		{
			num_words++;
			while (str[i] != '\0' && strstr(&str[i], delim) != &str[i])
			{
				i++;
			}
		}
	}
	// Allocate memory for the array of words
	words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}
	// Extract the words from the string
	i = 0;
	j = 0;
	while (j < num_words)
	{
		while (str[i] != '\0' && strstr(&str[i], delim) == &str[i])
		{
			i += ft_strlen(delim);
		}
		start = &str[i];
		while (str[i] != '\0' && strstr(&str[i], delim) != &str[i])
		{
			i++;
		}
		end = &str[i];
		k = end - start;
		words[j] = (char *)malloc((k + 1) * sizeof(char));
		if (words[j] == NULL)
		{
			return (NULL);
		}
		strncpy(words[j], start, k);
		words[j][k] = '\0';
		j++;
	}
	words[j] = NULL;
	return (words);
}

int	pipe_creation(char **commands, char **path, t_lst *args)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	status;

	pid1 = 0;
	pid2 = 0;
	if (pipe(fd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 < 0)
		return (-1);
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(path[0], &commands[0], args->env_var);
		exit(1);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (-1);
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(path[1], &commands[1], args->env_var);
		exit(1);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (0);
}
char	**get_real_path(char **path, char *remove)
{
	int		i;
	int		j;
	int		size;
	char	**dest;

	dest = malloc(1000);
	i = 0;
	j = 0;
	size = ft_strlen(remove);
	while (path[i])
	{
		if (ft_strncmp(path[i], remove, size))
		{
			dest[j] = ft_strdup(path[i]);
			i++;
			j++;
		}
		else
			i++;
	}
	return (dest);
}

int	exec_pipe(char **str, t_lst *args)
{
	int		i;
    char **tab;

	i = 0;
	while (str[i])
	{
        tab = ft_split(str[i], ' ');
        exec(tab, args);   
		i++;
        free_tab(tab);
        tab = NULL;
	}
	return (0);
}
