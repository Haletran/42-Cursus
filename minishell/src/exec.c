/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:30:53 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/05 19:38:38 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_commands(char **src)
{
	int	i;

	i = 0;
	while (src[i])
		printf("test : %s\n", src[i++]);
}

char	*strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*result;

	len1 = strlen(s1);
	len2 = strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	memcpy(result, s1, len1);
	memcpy(result + len1, s2, len2 + 1);
	return (result);
}

int	check_commands(char **str)
{
	char	*cwd;
	if (!ft_strncmp(str[0], "pwd", 3))
	{
		cwd = getenv("PWD");
		if (cwd != NULL)
			printf("%s\n", cwd);
		return (1);
	}
	else if (!ft_strncmp(str[0], "echo", 4))
	{
		ft_echo(str);
		return (1);
	}
	else if (!ft_strncmp(str[0], "cd", 2))
		return (1);
	else if (!ft_strncmp(str[0], "export", 6))
		return (1);
	else if (!ft_strncmp(str[0], "unset", 5))
		return (1);
	else if (!ft_strncmp(str[0], "env", 3))
		return (1);
	else if (!ft_strncmp(str[0], "exit", 4))
		exit(0);
	return (0);
}

int	exec(char **str)
{
	char	*path;
	char	*cmd;
	char **test = NULL;
	char	*full_path;
	char	**envp= NULL;
	pid_t	pid;

	path = getenv("PATH");
	cmd = str[0];
	test = ft_split(path, ':');
	*test = strjoin(*test, "/");
	full_path = strjoin(*test, cmd);
	while (*test)
	{
		//printf("test %s\n", test[0]);
		if (access(full_path, F_OK | R_OK) == 0)
			break;
		else
		{
			*test = strjoin(*test, "/");
			full_path = strjoin(*test, cmd);
		}
		test++;
	}
	if (full_path == NULL)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		if (execve(full_path, str, envp) == -1)
		{
			perror(full_path);
			exit(127);
		}
	}
	waitpid(pid, NULL, 0);
	free(full_path);
	return (0);
}
