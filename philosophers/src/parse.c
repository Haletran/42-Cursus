/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:33:14 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/22 15:39:38 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_input(char **src)
{
	int	i;
	int	j;

	i = 1;
	if (!src)
		return (0);
	while (src[i] != NULL)
	{
		j = 0;
		while (src[i][j])
		{
			if (!(src[i][j] >= '0' && src[i][j] <= '9'))
				return (0);
			j++;
		}
		if (ft_atoi_check(src[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}

int	checker(char **arr)
{
	if (!check_input(arr))
		return (0);
	return (1);
}