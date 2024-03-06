/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:19:09 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/06 10:26:59 by bapasqui         ###   ########.fr       */
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
	else if (signalNum == SIGQUIT)
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
	t_lst **args = NULL;

	(void)av;
	if (ac > 1)
		return (0);
	args = malloc(sizeof(t_lst));
    *args = ft_calloc(1, 1);
	init_lst(args);
	while (1)
	{
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, signal_handler);
		input = readline("$> ");
		if (input == NULL)
			exit(0);
		else if (input[0] == '\0')
			rl_on_new_line();
		else if (input[0] != '\0')
		{
			add_history(input);
			commands = ft_split(input, ' ');
			if (check_commands(commands, *args) == 0)
				exec(commands, *args);
			free(commands);
		}
		free(input);
	}
	return (0);
}
