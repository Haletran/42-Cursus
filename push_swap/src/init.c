/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:21:51 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 18:51:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_input(int nb_args, char **src)
{
	int	i;
	int	cool;
	int	j;
	int	validity;

	cool = 0;
	validity = 0;
	i = 1;
	while (i < nb_args)
	{
		j = 0;
		while (src[i][j])
			validity += ft_isdigit(src[i][j++]);
		if (validity == j)
			cool++;
		validity = 0;
		i++;
	}
	if (cool == nb_args - 1)
		return (1);
	return (0);
}

int	valid_input(int nb_args, char **src)
{
	if (check_input(nb_args, src))
		write(1, "VALID\n", 6);
	else
		write(1, "NOT VALID\n", 10);
	return (0);
}