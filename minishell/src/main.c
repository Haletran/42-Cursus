/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:19:09 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/05 10:54:03 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void signal_handler(int signalNum)
{
    if (signalNum == SIGINT)
	{
        ft_putstr_fd("\n", 1);
		rl_on_new_line();
        rl_replace_line("", 1);
        rl_redisplay();
	}
	if (signalNum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
    usleep(10);
}

int	main(int ac, char **av)
{
	char	*input;
	char	**commands;

	(void)av;
	if (ac > 1)
		return (0);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	while (1)
	{
		input = readline("$> ");
		if (input == NULL)
		{
			free(input);
			exit(0);
		}
		if (input[0] != '\0')
		{
			add_history(input);
			commands = ft_split(input, ' ');
			exec(commands);
			free(commands);
		}
		free(input);
	}
	return (0);
}
