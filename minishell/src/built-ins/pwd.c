/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:28:43 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/18 13:30:14 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd(t_lst *args)
{
	args->current_path = getcwd(args->current_path, 1024);
	ft_putstr_fd(args->current_path, 1);
	ft_putstr_fd("\n", 1);
}