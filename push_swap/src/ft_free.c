/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:23:37 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/18 18:31:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_free_arr(char **arr, int size)
{
	int	i;

	i = 0;
	if (size == 1)
	{
		if (arr)
		{
			while (arr[i])
				free(arr[i++]);
			free(arr);
		}
	}
}

void	ft_free(t_lst **a, t_lst **b, int size, char **arr)
{
	struct s_lst	*tmp;

	if (a)
	{
		while (*a != NULL)
		{
			tmp = (*a)->next;
			free(*a);
			*a = tmp;
		}
		free(a);
	}
	if (b)
	{
		while (*b != NULL)
		{
			tmp = *b;
			*b = (*b)->next;
			free(tmp);
		}
		free(b);
	}
	ft_free_arr(arr, size);
}
