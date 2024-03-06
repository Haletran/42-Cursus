/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:19:09 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/06 12:03:53 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av)
{
	char	*input;
	char	**commands;
	t_lst	**args;

	args = NULL;
	(void)av;
	if (ac > 1)
		return (0);
	args = malloc(sizeof(t_lst));
	*args = malloc(100);
	init_lst(args);
	while (1)
	{
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, signal_handler);
		input = readline("$> ");
		if (input == NULL)
		{
			free(input);
			exit(0);
		}
		else if (input[0] == '\0')
			rl_on_new_line();
		else if (input[0] != '\0')
		{
			add_history(input);
			commands = ft_split(input, ' ');
			if (check_commands(commands, *args) == -1)
				exec(commands, *args);
			free_tab(commands);
		}
		// free(input);
	}
	return (0);
}
