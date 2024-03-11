/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:10:28 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/11 09:48:10 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cd(char **str, t_lst *lst)
{
	int	valid;

	valid = 0;
	if (!str[1])
		chdir(lst->home_path);
	else
	{
		if (get_nbargs(str) > 2)
		{
			printf("cd : too many arguments\n");
			return (1);
		}
		valid = chdir(str[1]);
		if (valid)
			perror(str[1]);
	}
	return (0);
}
