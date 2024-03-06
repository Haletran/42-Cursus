/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:54:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/06 12:15:25 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/**
 * @brief Init different path value
 * 
 * @param args 
 */
void	init_lst(t_lst **args)
{
	(*args)->home_path = getenv("HOME");
	(*args)->env_path = getenv("PATH");
	(*args)->current_path = getenv("PWD");
	(*args)->exit_code = 0;
}