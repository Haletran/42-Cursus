/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:49:49 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/14 15:13:53 by bapasqui         ###   ########.fr       */
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

#include <stdlib.h>

char	*make_str(char **src)
{
	char	*dest;
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = 0;
	dest = malloc(sizeof(dest) * get_nbargs(src));
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
	dest[k] = '\0';
	return (dest);
}

void	ft_export(t_lst *args, char **str)
{
	char **to_add;
	char *stock;
	int len_env;
	int args_len;
	int i;

	i = 0;
	if (!args->env_var)
		return ;
	if (!str[1])
	{
		while (args->env_var[i])
			printf("declare -x %s\n", args->env_var[i++]);
		return ;
	}
	if (!ft_strchr(str[1], '='))
		return ;
	i = 1;
	len_env = 0;
	while (args->env_var[len_env])
		len_env++;
	while (str[i])
	{
		to_add = ft_split(str[i], '=');
		args_len = 0;
		while (to_add[args_len])
			args_len++;
		stock = make_str(to_add);
		args->env_var[len_env] = stock;
		len_env++;
		i++;
	}
}
