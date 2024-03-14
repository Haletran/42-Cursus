/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:30:09 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/12 19:40:14 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_tab(char **str)
{
	while (*str)
	{
		free(*str);
		str++;
	}
}

void	free_list(t_lst **lst)
{
	free(*lst);
}
