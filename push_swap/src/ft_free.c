/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:23:37 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/05 16:25:52 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_free_arr(char **arr, int size)
{
	int	i;

	i = 0;
	if (size == 2)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
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