/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:30:53 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/04 18:54:33 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void exec()
{
    char *path = "/bin/ls";
    char *argv[] = {"ls", "-l", NULL};
    char *envp[] = {"HOME=/home/baptiste", "PATH=/usr/bin", NULL};

    execve(path, argv, envp);
}