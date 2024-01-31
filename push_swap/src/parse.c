/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:47:27 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 19:25:37 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// TODO: need to check another if the input is sorted in case of a split WTF (ex: "1 2" 1)
t_lst	*init_stack(t_lst *a, int size, char **arr)
{
	int		i;
	t_lst	*start;
	
	i = 1;
	start = NULL;
	if (size == 2)
	{
		size = get_args(arr);
		i = 0;
	}
	while (i < size)
	{
		if (!a)
		{
			a = ft_lstnew(ft_atoi(arr[i]));
			start = a;
		}
		else
		{
			if (a)
			{
				while (a && a->next != NULL)
					a = a->next;
				ft_lstadd_back(a, ft_atoi(arr[i]));
			}
		}
		i++;
	}
	a = start;
	return (a);
}
