/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:21:51 by codespace         #+#    #+#             */
/*   Updated: 2024/02/14 00:39:48 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_list(int nb_args, char **src)
{
	int	i;
	int	j;

	i = 1;
	if (!src)
		return (0);
	if (nb_args == 2)
	{
		nb_args = get_args(src);
		i = 0;
	}
	while (i < nb_args - 1)
	{
		j = i + 1;
		while (j < nb_args)
		{
			if (ft_strlen(src[i]) == 0)
				return (0);
			if (ft_atoi(src[i]) == ft_atoi(src[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input(int nb_args, char **src)
{
	int	i;
	int	j;

	i = 1;
	if (!src)
		return (0);
	if (nb_args == 2)
	{
		nb_args = get_args(src);
		i = 0;
	}
	while (i != nb_args)
	{
		j = 0;
		while (src[i][j])
			if (!ft_isdigit(src[i][j++]))
				return (0);
		i++;
	}
	return (1);
}

int	verif_input(int nb_args, char **src)
{
	if (check_input(nb_args, src) && check_list(nb_args, src)
		&& get_args(src) > 1)
		return (1);
	return (0);
}
