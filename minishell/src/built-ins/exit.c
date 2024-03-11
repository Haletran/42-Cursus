/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:16:58 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/11 08:34:18 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_exit(t_lst *args)
{
    int code;

    code = args->exit_code;
    free(args);
    //free_tab(args->env_var);
    args = NULL;
    exit(code);    
}