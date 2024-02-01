/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:47:27 by codespace         #+#    #+#             */
/*   Updated: 2024/02/01 18:40:48 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// TODO: need to check another if the input is sorted in case of a split WTF (ex: "1 2" 1)
// TODO: add check if the number is > MAX_INT or < MIN_INT or else

t_lst	*init_stack(t_lst *a, int size, char **arr, int count)
{
	t_lst	*start;
	
	start = NULL;
	if (size == 2)
		size = get_args(arr);
	while (count != size)
	{
		if (!a)
		{
			a = ft_lstnew(ft_atoi(arr[count]));
			start = a;
		}
		else
		{
			while (a && a->next != NULL)
				a = a->next;
			ft_lstadd_back(a, ft_atoi(arr[count]));
		}
		count++;
	}
	a = start;
	return (a);
}
