/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:21:51 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 20:15:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ✅ check if same number multiple time
// check if the list is already sorted
// ✅ check if there is others things than numbers (WORKING BUT WHEN NOT USING WITHOUT <"">)

static int	check_list(int nb_args, char **src)
{
	int	i;
	int	j;

	i = 0;
	if (nb_args == 2)
		nb_args = get_args(src);
	while (i < nb_args - 1)
	{
		j = i + 1;
		while (j < nb_args)
		{
			if (ft_atoi(src[i]) == ft_atoi(src[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_input(int nb_args, char **src)
{
	int i;
	int j;
	
	i = 1;
	if (nb_args == 2)
		nb_args = get_args(src);
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

int	valid_input(int nb_args, char **src)
{
	if (check_input(nb_args, src) && check_list(nb_args, src))
		write(1, "VALID\n", 6);
	else
		write(1, "NOT VALID\n", 10);
	return (0);
}
