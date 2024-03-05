/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:19:09 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/05 13:17:51 by bapasqui         ###   ########.fr       */
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
		//130
	}
	if (signalNum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		//130
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
		}
		if (check_commands(commands) == 0)
			exec(commands);
		free(input);
		free(commands);
	}
	return (0);
}
