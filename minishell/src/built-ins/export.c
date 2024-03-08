/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:49:49 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/08 12:02:47 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*str_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

char	*make_str(char **src)
{
	char	*dest;
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = 0;
	dest = malloc(1000);
	while (src[i][j])
	{
		dest[k] = src[i][j];
		k++;
		j++;
	}
	j = 0;
	i++;
	dest[k++] = '=';
	while (src[i][j])
	{
		dest[k] = src[i][j];
		k++;
		j++;
	}
	//dest[k++] = '\n';
	dest[k++] = '\0';
	return (dest);
}

void	ft_export(char **envp, char **str)
{
	if (envp)
	{
		char **to_add;
		char *stock;
		int len_env;
		int args_len;
		int i = 1;
		len_env = get_nbargs(envp);
		to_add = malloc(sizeof(char) * ft_strlen(str[1]) + 1);
		while (str[i])
		{
			to_add = ft_split(str[i], '=');
			to_add[0] = str_capitalizer(to_add[0]);
			args_len = ft_strlen(to_add[0]);
			// printf("%s", to_add[1]);
			stock = make_str(to_add);
			envp[len_env] = ft_strjoin(envp[len_env], stock);
            len_env++;
			i++;
		}
		// print_commands(to_add);
	}
}