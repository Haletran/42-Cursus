/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:30:53 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/08 10:32:48 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/**
 * @brief Associate commands to built-ins if needed
 *
 * @param str
 * @param args
 * @return int (true / false)
 */
int	check_commands(char **str, t_lst *args)
{
	if (!ft_strncmp(str[0], "pwd", 3) && ft_strlen(str[0]) == 3)
	{
		args->current_path = getcwd(args->current_path, 1024);
		printf("%s\n", args->current_path);
		return (1);
	}
	else if (!ft_strncmp(str[0], "echo", 4) && ft_strlen(str[0]) == 4)
	{
		ft_echo(str);
		return (1);
	}
	else if (!ft_strncmp(str[0], "cd", 2) && ft_strlen(str[0]) == 2)
	{
		ft_cd(str, args);
		return (1);
	}
	else if (!ft_strncmp(str[0], "export", 6) && ft_strlen(str[0]) == 6)
		return (-1);
	else if (!ft_strncmp(str[0], "unset", 5) && ft_strlen(str[0]) == 5)
		return (-1);
	else if (!ft_strncmp(str[0], "env", 3) && ft_strlen(str[0]) == 3)
	{
		ft_env(args->env_var, str);
		return (1);
	}
	else if (!ft_strncmp(str[0], "exit", 4) && ft_strlen(str[0]) == 4)
		ft_exit(args);
	return (-1);
}

/**
 * @brief Main execution ft, check command path and execute
 *
 * @param str
 * @param args
 * @return int
 */
int	exec(char **str, t_lst *args)
{
	char	*cmd;
	char	**test;
	char	*full_path;
	char	**envp;
	pid_t	pid;

	test = NULL;
	envp = NULL;
	cmd = str[0];
	// parse here so that you have a clean command a the end
	test = ft_split(args->env_path, ':');
	*test = ft_join(*test, "/");
	full_path = ft_join(*test, cmd);
	while (*test)
	{
		if (access(full_path, F_OK | R_OK) == 0)
			break ;
		else
		{
			*test = ft_join(*test, "/");
			full_path = ft_join(*test, cmd);
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
			g_value = 127;
			exit(127);
		}
	}
	waitpid(pid, &args->exit_code, 0);
	get_exit_code(args);
	free_tab(test);
	return (0);
}
