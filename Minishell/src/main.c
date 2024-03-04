/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:19:09 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/04 18:53:43 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void signal_handler(int signalNum)
{
    if (signalNum == SIGINT)
    {
        write(1, "\n", 1);
        rl_replace_line("", 1);
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

    while (1)
    {
        signal(SIGINT, signal_handler);
        signal(SIGQUIT, signal_handler);
        input = readline("$> ");
        if (input == NULL)
            exit(0);
        if (input[0] != '\0') {
            add_history(input);
        }
        if (input[0] == 'l')
            exec(input);
    }
    free(input);
    return (0);
}

