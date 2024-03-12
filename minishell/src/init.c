/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:54:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/12 18:11:40 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/**
 * @brief Init different path value
 *
 * @param args
 */
void	init_lst(t_lst **args, char **envp)
{
	int	i;

	i = 0;
	(*args)->home_path = getenv("HOME");
	(*args)->username = getenv("USER");
	(*args)->env_path = getenv("PATH");
	(*args)->env_var = malloc(get_len(envp));
	while (envp[i])
	{
		(*args)->env_var[i] = envp[i];
		i++;
	}
	(*args)->prompt = ft_join((*args)->username, MAGENTA"$> "RESET);
	(*args)->exit_code = 0;
}

t_com	*init_stack(t_com *com, char **str)
{
	t_com	*head;
	int		tmp;

	head = NULL;
	tmp = 0;
	while (tmp != get_nbargs(str))
	{
		if (!com)
		{
			com = ft_lst_new(ft_atoi(str[tmp]), 0);
			head = com;
		}
		else
		{
			while (com && com->next != NULL)
				com = com->next;
			ft_lstadd_back(com, ft_atoi(str[tmp]));
		}
		tmp++;
	}
	com = head;
	return (com);
}
