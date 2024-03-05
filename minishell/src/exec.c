/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:30:53 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/04 23:41:46 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void print_commands(char **src)
{
    int i;

    i = 0;
    while (src[i])
        printf("test : %s\n", src[i++]);
}

char *strjoin(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1);
    if (result == NULL)
        return NULL;
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);
    return result;
}


int exec(char **str)
{
    int status;
    char *path = "/bin/";
    char *cmd = str[0];
    char *full_path = strjoin(path, cmd);
    if (full_path == NULL)
        return (1);

    char *envp[] = {"HOME=/home/baptiste", "PATH=/usr/bin", NULL};

    pid_t pid = fork();
    if (pid == -1)
        return 1;
    else if (pid == 0) 
    {
        execve(full_path, str, envp);
        perror("execve");
        write(1, "\n", 1);
        return 1;
    } 
    else 
    {
        waitpid(pid, &status, 0);
        rl_redisplay();
        rl_on_new_line();
        return 0;
    }
}

