/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:54:32 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/18 08:43:49 by bapasqui         ###   ########.fr       */
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

	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO); // that's dumb because no redirection
		close(fd[0]);              
		close(fd[1]);
		if (execve(full_path, str, args->env_var) == -1)
		{
			perror(full_path);
			g_value = 127;
			exit(127);
		}
	}
	else
	{
		close(fd[1]);
		waitpid(pid, &g_value, 0);
	}
	return (0);
}

int	test_exec(char **str, t_lst **args)
{
	char	*full_path;
	char	*tmp;
	int		i;

	full_path = NULL;
	i = 0;
	if (!ft_strncmp(str[i], "./", 2))
	{
		if (access(str[i], F_OK) == 0)
		{
			full_path = str[i];
			str[i] = ft_strrchr(str[i], '/');
		}
	}
	else if (ft_strchr(str[i], '/'))
	{
		if (access(str[i], F_OK) == 0)
		{
			full_path = str[i];
			tmp = ft_strrchr(str[i], '/');
			str[i] = ft_strdup(tmp);
		}
		else
		{
			perror(str[i]);
			g_value = 127;
			return (127);
		}
	}
	else
	{
		full_path = check_path(str, *args, 0); // path not working don't know why
		if (full_path == NULL)
			return (1);
	}
	piping(str, *args, full_path);
	return (0);
}

int	exec_pipe(char **str, t_lst *args)
{
	int		i;
	char	**tab;

	i = 0;
	while (str[i])
	{
		tab = ft_split(str[i], ' ');
		test_exec(tab, &args);
		i++;
		free_tab(tab);
		tab = NULL;
	}
	return (0);
}
