/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:19:09 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/07 09:33:11 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/**
 * @Main function
 * 
 * @param ac 
 * @param av
 * @brief allocate t_lst, handle signal, handle prompt print and history 
 * @return 0 
 */
int	main(int ac, char **av, char **envp)
{
	char	*input;
	char	**commands;
	t_lst	**args;
	char *prompt;
 
	(void)av;
	if (ac > 1)
		return (0);
	args = malloc(sizeof(t_lst));
	*args = malloc(sizeof(t_lst *) * 10);
	init_lst(args, envp);
	prompt = (*args)->prompt;
	while (1)
	{
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, signal_handler);
		input = readline(prompt);
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
	}
	return (0);
}
