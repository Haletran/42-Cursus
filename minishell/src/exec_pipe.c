/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:54:32 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/14 13:16:58 by bapasqui         ###   ########.fr       */
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
	words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}
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

int	piping(char **str, t_lst *args, char *full_path)
{
	pid_t	pid;
	int		fd[2];

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		// close(fd[1]);
		if (execve(full_path, str, args->env_var) == -1)
		{
			perror(full_path);
			g_value = 127;
			exit(127);
		}
	}
	// close(fd[0]);
	// close(fd[1]);
	waitpid(pid, &g_value, 0);
	// waitpid(pid2, &status, 0);
	return (0);
}

int	exec_pipe(char **str, t_lst *args)
{
	int		i;
	char	**tab;
	char	*full_path;

	i = 0;
	while (str[i])
	{
		tab = ft_split(str[i], ' ');
		full_path = check_path(tab, args, i);
		piping(tab, args, full_path);
		free(full_path);
		full_path = NULL;
		i++;
	}
	free_tab(tab);
	tab = NULL;
	return (0);
}
