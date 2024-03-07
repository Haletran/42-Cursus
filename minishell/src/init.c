/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:54:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/07 09:44:17 by bapasqui         ###   ########.fr       */
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
	int i = 0;
	(*args)->home_path = getenv("HOME");
    (*args)->username = getenv("USER");
	(*args)->env_path = getenv("PATH");
	(*args)->env_var = malloc(sizeof(char **) * get_len(envp));
	while (envp[i])
	{
		(*args)->env_var[i] = envp[i];
		i++;
	}
	(*args)->current_path = getenv("PWD");
    (*args)->prompt = ft_join((*args)->username,  "$> ");
	(*args)->exit_code = 0;
}