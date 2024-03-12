/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:10:30 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/12 17:42:29 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_current(void)
{
	DIR				*dir;
	struct dirent	*cur;

	dir = opendir(".");
	if (dir != NULL)
	{
		cur = readdir(dir);
		while (cur != NULL)
		{
			if (cur->d_name[0] != '.')
				printf("%s ", cur->d_name);
			cur = readdir(dir);
		}
		closedir(dir);
	}
}

int	ft_echo(char **str)
{
	int		i;
	char	**var;
	int		check;
	int		flag;

	i = 1;
	check = 1;
	flag = 0;
	var = malloc(sizeof(char **));
	if (!ft_strncmp(str[i], "-n", 2))
	{
		while (str[1][check] == 'n')
			check++;
		if (check == (int)ft_strlen(str[1]))
		{
			flag++;
			i++;
		}
	}
	while (str[i])
	{
		if (!ft_strncmp(str[i], "$?", 2))
			printf("%d", g_value);
		else if (!ft_strncmp(str[i], "$", 1))
		{
			var = ft_split(str[i], '$');
			printf("%s", getenv(var[0]));
		}
		else if (!ft_strncmp(str[i], "*", 1))
			print_current();
		else if (str[i + 1] == NULL)
			printf("%s", str[i]);
		else
			printf("%s ", str[i]);
		i++;
	}
	if (flag == 0)
		printf("\n");
	return (0);
}
