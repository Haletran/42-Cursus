/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:19:09 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/04 23:42:37 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void signal_handler(int signalNum)
{
    if (signalNum == SIGINT)
    {
        rl_replace_line("\n", 1);
        rl_on_new_line();
        rl_redisplay();
    }
    else if (signalNum == SIGQUIT)
    {
        rl_on_new_line();
        rl_redisplay();
    }
}

int main()
{
    char *input;
    char **commands;

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
        if (input[0] != '\0')  {
            add_history(input);
            commands = ft_split(input, ' ');
            exec(commands);
            free(commands);
        }
        free(input);
    }
    return (0);
}

