/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:10:30 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/07 11:20:03 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(char **str)
{
	int i = 1;
	int check = 1;
	int flag = 0;
	if (!ft_strncmp(str[i], "-n", 2))
	{
		while(str[1][check] == 'n')
			check++;
		if (check == (int)ft_strlen(str[1]))
		{	
			flag++;
			i++;
		}	
	}
	while (str[i])
	{
		if (str[i + 1] == NULL)
			printf("%s", str[i]);
		else
			printf("%s ", str[i]);
		i++;
	}
	if (flag == 0)
		printf("\n");
	return (0);
}