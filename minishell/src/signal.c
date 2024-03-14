/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:03:28 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/14 08:21:23 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	sig_ctrl_c(int signum)
{
	(void)signum;
	ft_putstr_fd("\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

/**
 * @brief Handle CTRL+C and CTRL+\ signal
 *
 * @param signalNum
 */
void	handle_sig(void)
{
	signal(CTRL_C, sig_ctrl_c);
	signal(CTRL_BACKSLACH, RESET_SIG);
}
