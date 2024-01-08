/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:21:51 by codespace         #+#    #+#             */
/*   Updated: 2024/01/08 17:54:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(int i)
{
	if ((i >= '0' && i <= '9') || (i == 43 || i == 45 || i == 32))
		return (1);
	else
		return (0);
}

int	check_input(int nb_args, char **src)
{
	int	i;
	int	cool;
	int	j;
	int	validity;

	cool = 0;
	validity = 0;
	i = 1;
	if (nb_args <= 2)
		return (0);
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
