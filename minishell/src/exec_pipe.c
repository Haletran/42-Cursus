/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:54:32 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/12 12:51:14 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char **ft_split2(char *str, char *delim)
{
    int i, j, k;
    int num_words = 0;
    char **words;
    char *start, *end;

    // Count the number of words in the string
    i = 0;
    while (str[i] != '\0') {
        if (strstr(&str[i], delim) == &str[i]) {
            i += ft_strlen(delim);
        } else if (str[i] != '\0') {
            num_words++;
            while (str[i] != '\0' && strstr(&str[i], delim) != &str[i]) {
                i++;
            }
        }
    }

    // Allocate memory for the array of words
    words = (char **)malloc((num_words + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL;
    }

    // Extract the words from the string
    i = 0;
    j = 0;
    while (j < num_words) {
        while (str[i] != '\0' && strstr(&str[i], delim) == &str[i]) {
            i += ft_strlen(delim);
        }
        start = &str[i];
        while (str[i] != '\0' && strstr(&str[i], delim) != &str[i]) {
            i++;
        }
        end = &str[i];
        k = end - start;
        words[j] = (char *)malloc((k + 1) * sizeof(char));
        if (words[j] == NULL) {
            return NULL;
        }
        strncpy(words[j], start, k);
        words[j][k] = '\0';
        j++;
    }
    words[j] = NULL;

    return words;
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

int	exec_pipe(char **str, t_lst *args)
{
	char	**full_path; 
    char *tmp;
	int		i;

	i = 0;
	full_path = malloc(1000);
    str = ft_split2(str[0], " | ");
	while (str[i])
	{
        if (check_one_space(str[i]))
        {
            tmp = ft_strrchr(str[i], ' ');
            full_path[i] = check_path(&tmp, args, i);
            if (full_path[i] == NULL)
			    return (0);

        }
        else
        {
		    full_path[i] = check_path(str, args, i);
		    if (full_path[i] == NULL)
			    return (0);
        }
		i++;
	}
    print_commands(str);
    print_commands(full_path);
    if (pipe_creation(str, full_path, args))
		return (1);
	return (0);
}
