/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:09:45 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/06 12:03:50 by bapasqui         ###   ########.fr       */
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