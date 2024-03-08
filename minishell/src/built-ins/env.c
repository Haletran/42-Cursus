/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:59:39 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/08 10:13:51 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(char **envp, char **str)
{
	int i;

	i = 0;
	if (ft_strlen(str[1]) > 0)
	{
		printf("env : '%s': No such file or directory\n", str[1]);
		g_value += 127;
	}
	else
	{
		while (envp[i])
		{
			printf("%s\n", envp[i]);
			i++;;
		}
	}
}