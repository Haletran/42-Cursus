/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:03:28 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/08 09:14:05 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/**
 * @brief Handle CTRL+C and CTRL+\ signal
 * 
 * @param signalNum
 */
void	signal_handler(int signalNum)
{
	if (signalNum == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_value = 130;
	}
	else if (signalNum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		g_value = 0;
	}
	// usleep(10);
}