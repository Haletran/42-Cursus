/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:10:28 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/06 12:04:18 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cd(char **str)
{
	char	*path;

	print_commands(str);
	if (!str[1])
	{
		path = getenv("HOME");
		chdir(path);
	}
	return (0);
}
