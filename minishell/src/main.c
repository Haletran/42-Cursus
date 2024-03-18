/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:19:09 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/18 13:50:13 by bapasqui         ###   ########.fr       */
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
	char	*prompt;

	commands = NULL;
	(void)av;
	if (ac > 1)
		return (0);
	args = malloc(sizeof(t_lst));
	*args = malloc(sizeof(t_lst *) * 100);
	init_lst(args, envp);
	prompt = (*args)->prompt;
	while (1)
	{
		handle_sig(0);
		input = readline(prompt);
		if (!input)
		{
			g_value = 0;
			exit(g_value);
		}
		add_history(input);
		//commands = ft_split(input, ' ');
		//show_token(commands, com);
		choose(input, commands, args);
	}
	return (0);
}
