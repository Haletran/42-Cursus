/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:30:53 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/13 11:52:54 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_if_pipe(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_strchr(str[i], '|'))
			return (1);
		i++;
	}
	return (0);
}

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
		ft_putstr_fd(args->current_path, 1);
		ft_putstr_fd("\n", 1);
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
	{
		ft_export(args->env_var, str);
		return (1);
	}
	else if (!ft_strncmp(str[0], "unset", 5) && ft_strlen(str[0]) == 5)
	{
		ft_unset(str, args);
		return (1);
	}
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
 * @brief Path check if access is ok and loop until it test all path available
 *
 * @param str
 * @param args
 * @param nb
 * @return char*
 */
char	*check_path(char **str, t_lst *args, int nb)
{
	char	*cmd;
	char	**path;
	char	*full_path;

	cmd = str[nb];
	path = NULL;
	path = ft_split(args->env_path, ':');
	*path = ft_join(*path, "/");
	full_path = ft_join(*path, cmd);
	while (*path)
	{
		if (access(full_path, F_OK | R_OK) == 0)
			break ;
		else
		{
			*path = ft_join(*path, "/");
			full_path = ft_join(*path, cmd);
		}
		path++;
	}
	return (full_path);
}

/**
 * @brief Execute the command after checking the path
 *
 * @param str
 * @param args
 * @param full_path
 * @return int
 */
int	exec_command(char **str, t_lst *args, char *full_path)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		args->pid = &pid;
		if (execve(full_path, str, args->env_var) == -1)
		{
			perror(full_path);
			g_value = 127;
			exit(127);
		}
	}
	waitpid(pid, &g_value, 0);
	return (0);
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
	char	*full_path = NULL;
	char	*tmp;
	int i;

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
			tmp = ft_strrchr(str[0], '/');
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
		full_path = check_path(str, args, 0);
		if (full_path == NULL)
			return (1);
	}
	exec_command(str, args, full_path);
	return (0);
}
